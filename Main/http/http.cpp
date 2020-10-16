#include "http.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>

Http::Http(QObject *parent) : QObject(parent)
{
}

void Http::testHttp()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    qDebug() << manager->supportedSchemes();
    connect(manager, &QNetworkAccessManager::finished, this, [](QNetworkReply* reply) {
        qDebug() << reply->readAll();
    });
    QNetworkRequest request;
    request.setUrl(QUrl("https://www.baidu.com"));
    manager->get(request);
}
