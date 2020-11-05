#include "youdaolangprovider.h"

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
            ->addParam("appKey", YOUDAO_APP_ID)
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
    QString content = YOUDAO_APP_ID;
    content.append(input).append(salt).append(timestamp).append(YOUDAO_APP_SECERT);

    qDebug() << "sign content: " << content;
    return QCryptographicHash::hash(content.toUtf8(), QCryptographicHash::Sha256).toHex();
}
