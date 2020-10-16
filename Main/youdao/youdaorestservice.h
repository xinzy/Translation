#ifndef YOUDAORESTSERVICE_H
#define YOUDAORESTSERVICE_H

#include "youdaotranslateresult.h"

#include <http/baseapi.h>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#define YOUDAO_APP_ID "229d103f10e5a0dc"
#define YOUDAO_APP_SECERT "5v0kkMOsGQm8VygPIJ2r79fGwi0kq8A7"
#define YOUDAO_BASE_API "https://openapi.youdao.com/api"

class YoudaoRestService : public BaseApi
{
    Q_OBJECT

public:
    YoudaoRestService(QObject *parent = nullptr);
    void translate(QString text, QString sourceCode, QString targetCode);

protected:
    virtual void onNetworkRequest(QNetworkRequest &request) override;
    virtual void onNetworkFinished(QNetworkReply *reply) override;

private:
    QString makeSign(QString &input, QString &salt, QString &timestamp);
    YoudaoTranslateResult *parseResult(QByteArray &content);

signals:
    void onTranslationResult(QString result);
};

#endif // YOUDAORESTSERVICE_H
