#include "youdaolangprovider.h"

#include <http/httpmanager.h>
#include <utils/config.h>
#include "youdaotranslateresult.h"

YoudaoLangProvider::YoudaoLangProvider(QObject *parent)
    : LangProvider(parent)
{
    initLangs(":/raw/lang.youdao.json");
}

void YoudaoLangProvider::translate(QString text, QString sourceCode, QString targetCode)
{
    QString uuid = QString::number(QDateTime::currentDateTime().toMSecsSinceEpoch()); //QUuid::createUuid().toString(QUuid::WithoutBraces);
    QString timestamp = QString::number(QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000);
    QString sign = makeSign(text, uuid, timestamp);
    qDebug() << "uuid: " << uuid << "; sign: " << sign;

    HttpManager::get(YOUDAO_BASE_API)
            ->addParam("signType", "v3")
            ->addParam("appKey", appId())
            ->addParam("from", sourceCode)
            ->addParam("to", targetCode)
            ->addParam("q", text)
            ->addParam("salt", uuid)
            ->addParam("curtime", timestamp)
            ->addParam("sign", sign)
            ->request<YoudaoTranslateResult>()
            .then([this](YoudaoTranslateResult result) {
                qDebug() << "youdao result: " << result;
                if (result.isSuccess()) {
                    emit onTranslationResult(result.result());
                } else {
                    emit onTranslationResult("");
                }
            });
}

QString YoudaoLangProvider::makeSign(QString &text, QString &salt, QString &timestamp)
{
    QString input = text;
    if (text.length() > 20)
    {
        input = text.mid(0, 10) + QString::number(text.length()) + text.mid(text.length() - 10);
    }
    QString content = appId();
    content.append(input).append(salt).append(timestamp).append(appSecert());

    qDebug() << "sign content: " << content;
    return QCryptographicHash::hash(content.toUtf8(), QCryptographicHash::Sha256).toHex();
}

QString YoudaoLangProvider::appId()
{
    return Config::instance()->youdaoApiConfig().appId.isEmpty() ? YOUDAO_APP_ID : Config::instance()->youdaoApiConfig().appId;
}

QString YoudaoLangProvider::appSecert()
{
    return Config::instance()->youdaoApiConfig().appSecert.isEmpty() ? YOUDAO_APP_SECERT : Config::instance()->youdaoApiConfig().appSecert;
}
