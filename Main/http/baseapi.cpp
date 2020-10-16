#include "baseapi.h"

BaseApi::BaseApi(QObject *parent)
    : QObject(parent),
      mManager(nullptr),
      mReply(nullptr)
{ }

void BaseApi::get(QString url, QMap<QString, QString> &params)
{
    QString requestUrl(url);
    QString queryString = makeQueryString(params);
    if (!queryString.isEmpty()) {
        requestUrl.append("?").append(queryString);
    }
    qDebug() << "url: " << requestUrl;

    mManager = new QNetworkAccessManager(this);
    QNetworkRequest request;
    request.setUrl(QUrl(requestUrl));
    onNetworkRequest(request);
    mReply = mManager->get(request);

    connect(mManager, &QNetworkAccessManager::finished, this, &BaseApi::networkFinish);
}

void BaseApi::post(QString url, QMap<QString, QString> &params)
{
    QString queryString = makeQueryString(params);
    mManager = new QNetworkAccessManager(this);

    QNetworkRequest request;
    request.setUrl(QUrl(url));
    onNetworkRequest(request);
    mReply = mManager->post(request, queryString.toUtf8());

    connect(mManager, &QNetworkAccessManager::finished, this, &BaseApi::networkFinish);
}

void BaseApi::onNetworkRequest(QNetworkRequest &request)
{
    Q_UNUSED(request)
}

void BaseApi::onNetworkFinished(QNetworkReply *reply)
{
    Q_UNUSED(reply)
}

QString BaseApi::makeQueryString(QMap<QString, QString> &map)
{
    QString queryString;
    if (!map.isEmpty()) {
        auto current = map.constBegin();
        auto end = map.constEnd();
        while (current != end) {
            queryString.append(current.key()).append("=").append(current.value()).append("&");
            current++;
        }
        return queryString.mid(0, queryString.length() - 1);
    }
    return queryString;
}

void BaseApi::networkFinish()
{
    onNetworkFinished(mReply);
}
