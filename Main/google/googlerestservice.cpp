#include "googlerestservice.h"

GoogleRestService::GoogleRestService(QObject *parent)
    : BaseApi(parent)
{
}

void GoogleRestService::translate(QString text, QString sourceCode, QString targetCode)
{
    QMap<QString, QString> params;
    params["client"] = "webapp";
    params["dt"] = "t";
    params["q"] = QUrl::toPercentEncoding(text);
    params["sl"] = sourceCode;
    params["tl"] = targetCode;
    params["tk"] = GoogleUtils::makeToken(text);

    get(GOOGLE_BASE_API, params);
}

void GoogleRestService::onNetworkRequest(QNetworkRequest &request)
{
    QString userAgent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.121 Safari/537.36";
    request.setHeader(QNetworkRequest::KnownHeaders::UserAgentHeader, QVariant(userAgent));
}

void GoogleRestService::onNetworkFinished(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    qDebug().noquote() << data;
    QString result = parseResult(data);
    emit onTranslationResult(result);
}

QString GoogleRestService::parseResult(QByteArray &content)
{
    QString result("");

    QJsonDocument document = QJsonDocument::fromJson(content);
    QJsonArray array = document.array();
    QJsonValue value0 = array.at(0);

    if (value0.isArray()) {
        array = value0.toArray();
        int length = array.size();
        for (int i = 0; i < length; i++) {
            QJsonArray item = array.at(i).toArray();
            QJsonValue value = item.at(0);
            if (!value.isNull()) {
                result.append(value.toString());
            }
        }
    }
    return result;
}
