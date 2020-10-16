#include "youdaorestservice.h"

#include <QUuid>

YoudaoRestService::YoudaoRestService(QObject *parent)
    : BaseApi(parent)
{
}

void YoudaoRestService::translate(QString text, QString sourceCode, QString targetCode)
{
    QMap<QString, QString> param;
    param["signType"] = "v3";
    param["appKey"] = YOUDAO_APP_ID;
    param["from"] = sourceCode;
    param["to"] = targetCode;
    param["q"] = text;

    QString uuid = QString::number(QDateTime::currentDateTime().toMSecsSinceEpoch()); //QUuid::createUuid().toString(QUuid::WithoutBraces);
    QString timestamp = QString::number(QDateTime::currentDateTime().toMSecsSinceEpoch() / 1000);
    QString sign = makeSign(text, uuid, timestamp);
    qDebug() << "uuid: " << uuid << "; sign: " << sign;

    param["salt"] = uuid;
    param["curtime"] = timestamp;
    param["sign"] = sign;

    get(YOUDAO_BASE_API, param);
}

void YoudaoRestService::onNetworkRequest(QNetworkRequest &request)
{
    BaseApi::onNetworkRequest(request);
}

void YoudaoRestService::onNetworkFinished(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    qDebug().noquote() << data;
    YoudaoTranslateResult *result = parseResult(data);

    if (result->isSuccess()) {
        emit onTranslationResult(result->result());
    } else {
        emit onTranslationResult("");
    }
    delete result;
}

QString YoudaoRestService::makeSign(QString &text, QString &salt, QString &timestamp)
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

YoudaoTranslateResult *YoudaoRestService::parseResult(QByteArray &content)
{
    YoudaoTranslateResult *result = new YoudaoTranslateResult;

    QJsonDocument document = QJsonDocument::fromJson(content);
    QJsonObject json = document.object();
    int code = json.value("errorCode").toInt();
    result->errorCode = code;
    if (code == 0)
    {
        result->query = json.value("query").toString();
        QJsonArray array = json.value("translation").toArray();
        int length = array.size();
        for (int i = 0; i < length; i++) {
            QString item = array.at(i).toString();
            result->translation.append(item);
        }
    }

    return result;
}
