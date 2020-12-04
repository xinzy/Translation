#ifndef HTTPMANAGER_H
#define HTTPMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QHttpMultiPart>
#include <QMap>

#include <QtPromise>
#include <QtJsonSerializer/QtJsonSerializer>

using namespace QtPromise;
using namespace QtJsonSerializer;

class HttpManager : public QObject
{
public:
    static HttpManager* get(QString url);
    static HttpManager* post(QString url, QHttpMultiPart::ContentType contentType = QHttpMultiPart::FormDataType);
    static HttpManager* head(QString url);
    static HttpManager* put(QString url, QHttpMultiPart::ContentType contentType = QHttpMultiPart::FormDataType);
    static HttpManager* deleteResource(QString url);

public:
    HttpManager* setHeader(QNetworkRequest::KnownHeaders header, const QVariant &value);
    HttpManager* setRawHeader(const QByteArray &headerName, const QByteArray &headerValue);
    HttpManager* setPriority(QNetworkRequest::Priority priority);

    HttpManager* addParam(QString key, QString value);
    HttpManager* setUploadFile(QIODevice *file);

    HttpManager* addMultiPart(QString key, QString value);
    HttpManager* addMultiPart(QString typeHeader, QString dispositionHeader, QIODevice& file);

    template <class T>
    QPromise<T> request();
    QPromise<QByteArray> request();

private:
    HttpManager(QString url, QNetworkAccessManager::Operation operation,
                QHttpMultiPart::ContentType contentType = QHttpMultiPart::FormDataType);

    QNetworkAccessManager *instance();

    QString makeQuery();
    QNetworkReply *startRequest();

private:
    static QNetworkAccessManager *sNetworkManager;

    QNetworkRequest mRequest;

    QString mUrl;
    QNetworkAccessManager::Operation mOperation;
    QHttpMultiPart::ContentType mContentType;

    QMap<QString, QString> mParam;
    QIODevice *mUploadFile{ nullptr };

    bool mHasMultiPart{ false };
    QHttpMultiPart mMultiPart;
};

template<class T>
QPromise<T> HttpManager::request()
{
    return request().then([](QByteArray content) {
        qDebug() << "response content: " << content;
        JsonSerializer serializer;
        return serializer.deserializeFrom<T>(content);
    });
}

#endif // HTTPMANAGER_H
