#include "httpmanager.h"

#include <utils/config.h>

#include <QNetworkProxy>

QNetworkAccessManager *HttpManager::sNetworkManager = nullptr;


QNetworkAccessManager *HttpManager::instance()
{
    if (sNetworkManager) {
        return sNetworkManager;
    }
    sNetworkManager = new QNetworkAccessManager;
    if (Config::instance()->isEnableProxy()) {
        Proxy proxy = Config::instance()->proxy();
        QNetworkProxy p(QNetworkProxy::HttpProxy, proxy.url, proxy.port.toInt(), proxy.username, proxy.password);
        sNetworkManager->setProxy(p);
    }
    return sNetworkManager;
}

HttpManager *HttpManager::get(QString url)
{
    return new HttpManager(url, QNetworkAccessManager::GetOperation);
}

HttpManager *HttpManager::post(QString url, QHttpMultiPart::ContentType contentType)
{
    return new HttpManager(url, QNetworkAccessManager::PostOperation, contentType);
}

HttpManager *HttpManager::head(QString url)
{
    return new HttpManager(url, QNetworkAccessManager::HeadOperation);
}

HttpManager *HttpManager::put(QString url, QHttpMultiPart::ContentType contentType)
{
    return new HttpManager(url, QNetworkAccessManager::PutOperation, contentType);
}

HttpManager *HttpManager::deleteResource(QString url)
{
    return new HttpManager(url, QNetworkAccessManager::DeleteOperation);
}

HttpManager *HttpManager::setHeader(QNetworkRequest::KnownHeaders header, const QVariant &value)
{
    mRequest.setHeader(header, value);
    return this;
}

HttpManager *HttpManager::setRawHeader(const QByteArray &headerName, const QByteArray &headerValue)
{
    mRequest.setRawHeader(headerName, headerValue);
    return this;
}

HttpManager *HttpManager::setPriority(QNetworkRequest::Priority priority)
{
    mRequest.setPriority(priority);
    return this;
}

HttpManager *HttpManager::addParam(QString key, QString value)
{
    mParam.insert(key, value);
    return this;
}

HttpManager *HttpManager::setUploadFile(QIODevice *file)
{
    if (mOperation != QNetworkAccessManager::PostOperation ||
            mOperation != QNetworkAccessManager::PutOperation) {
        return this;
    }

    mUploadFile = file;
    return this;
}

HttpManager *HttpManager::addMultiPart(QString key, QString value)
{
    if (mOperation != QNetworkAccessManager::PostOperation ||
            mOperation != QNetworkAccessManager::PutOperation) {
        return this;
    }

    QHttpPart textPart;
    QString header("form-data; name=\"%1\"");
    header.arg(key);
    textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(header));
    textPart.setBody(value.toUtf8());
    mMultiPart.append(textPart);

    mHasMultiPart = true;

    return this;
}

HttpManager *HttpManager::addMultiPart(QString typeHeader, QString dispositionHeader, QIODevice& file)
{
    if (mOperation != QNetworkAccessManager::PostOperation ||
            mOperation != QNetworkAccessManager::PutOperation) {
        return this;
    }

    QHttpPart imagePart;
    imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant(typeHeader));
    QString header("form-data; name=\"%1\"");
    header.arg(dispositionHeader);
    imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(header));
    imagePart.setBodyDevice(&file);
    mMultiPart.append(imagePart);

    mHasMultiPart = true;

    return this;
}

QPromise<QByteArray> HttpManager::request()
{
    return QtPromise::QPromise<QByteArray> {[&](
        const QtPromise::QPromiseResolve<QByteArray>& resolve,
        const QtPromise::QPromiseReject<QByteArray>& reject) {

            QNetworkReply* reply = startRequest();

            if (!reply) {
                reject("paramater error");
            } else {
                setParent(reply);

                QObject::connect(reply, &QNetworkReply::finished, [=]() {
                    if (reply->error() == QNetworkReply::NoError) {
                        resolve(reply->readAll());
                    } else {
                        qDebug() << "request error: " << reply->error();
                        reject("request fail");
                    }
                    reply->deleteLater();
                });
            }
    } };
}

QString HttpManager::makeQuery()
{
    QString query("");

    auto it = mParam.cbegin();
    while (it != mParam.cend()) {
        query.append(it.key()).append("=").append(it.value()).append("&");
        it++;
    }
    if (!query.isEmpty()) {
        query.remove(query.length() - 1, 1);
    }

    return query;
}

QNetworkReply *HttpManager::startRequest()
{
    QNetworkReply *reply = nullptr;
    if (mOperation != QNetworkAccessManager::PostOperation &&
            mOperation != QNetworkAccessManager::PutOperation) {
        QString url(mUrl);
        QString query = makeQuery();

        if (!query.isEmpty()) {
            if (!url.contains('?')) {
                url.append("?");
            } else {
                url.append("&");
            }
            url.append(query);
        }

        QUrl uri(url);
        QNetworkRequest request(uri);
        switch (mOperation) {
        case QNetworkAccessManager::HeadOperation:
            reply = instance()->head(request);
            break;
        case QNetworkAccessManager::DeleteOperation:
            reply = instance()->deleteResource(request);
            break;
        case QNetworkAccessManager::GetOperation:
        default:
            reply = instance()->get(request);
            break;
        }
    } else {
        QUrl uri(mUrl);
        QNetworkRequest request(uri);
        if (mUploadFile != nullptr) {
            if (mOperation == QNetworkAccessManager::PostOperation) {
                reply = instance()->post(request, mUploadFile);
            } else {
                reply = instance()->put(request, mUploadFile);
            }
        } else if (mHasMultiPart) {
            if (!mParam.isEmpty()) {
                auto it = mParam.cbegin();
                while (it != mParam.cend()) {
                    addMultiPart(it.key(), it.value());
                    it++;
                }
            }
            if (mOperation == QNetworkAccessManager::PostOperation) {
                reply = instance()->post(request, &mMultiPart);
            } else {
                reply = instance()->put(request, &mMultiPart);
            }
        } else {
            QString query = makeQuery();
            if (mOperation == QNetworkAccessManager::PostOperation) {
                reply = instance()->post(request, query.toUtf8());
            } else {
                reply = instance()->put(request, query.toUtf8());
            }
        }
    }
    return reply;
}

HttpManager::HttpManager(QString url, QNetworkAccessManager::Operation operation,
                         QHttpMultiPart::ContentType contentType)
    : mUrl(url), mOperation(operation), mContentType(contentType)
{
}

