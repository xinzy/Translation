#ifndef BAIDURESTSERVICE_H
#define BAIDURESTSERVICE_H

#include <http/baseapi.h>

#include <QRandomGenerator>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include <core/exception.h>
#include "translationresult.h"

#define BAIDU_APP_ID "20200914000565830"
#define BAIDU_APP_SERCERT "iYohXtxWzMtlUGgATcJh"
#define BAIDU_API_URL "http://api.fanyi.baidu.com/api/trans/vip/translate"

class BaiduRestService : public BaseApi
{
    Q_OBJECT
public:
    BaiduRestService(QObject *parent = nullptr);

    void translate(QString text, QString sourceCode, QString targetCode);

protected:
    virtual void onNetworkRequest(QNetworkRequest &request) override;
    virtual void onNetworkFinished(QNetworkReply *reply) override;

signals:
    void onTranslationResult(TranslationResult *result);

private:
    TranslationResult *parseResult(QByteArray &content);
    QString createRandom();
    QString makeSign(QString &text, QString &salt);
};

#endif // BAIDURESTSERVICE_H
