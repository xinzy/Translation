#ifndef BASEAPI_H
#define BASEAPI_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>

class BaseApi : public QObject
{
    Q_OBJECT
public:
    explicit BaseApi(QObject *parent = nullptr);

    void get(QString url, QMap<QString, QString> &params);

    void post(QString url, QMap<QString, QString> &params);

protected:
    virtual void onNetworkRequest(QNetworkRequest &request);
    virtual void onNetworkFinished(QNetworkReply *reply);

private:
    QString makeQueryString(QMap<QString, QString> &map);

    void networkFinish();

private:
    QNetworkAccessManager *mManager;
    QNetworkReply *mReply;
};

#endif // BASEAPI_H
