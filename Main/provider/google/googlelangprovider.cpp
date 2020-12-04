#include "googlelangprovider.h"

QString userAgent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.121 Safari/537.36";

GoogleLangProvider::GoogleLangProvider(QObject *parent)
    : LangProvider(parent)
{
    initLangs(":/raw/lang.google.json");
}

void GoogleLangProvider::translate(QString input, QString sourceCode, QString targetCode)
{
    HttpManager::get(GOOGLE_BASE_API)
            ->setHeader(QNetworkRequest::UserAgentHeader, userAgent)
            ->addParam("client", "webapp")
            ->addParam("dt", "t")
            ->addParam("q", QUrl::toPercentEncoding(input))
            ->addParam("sl", sourceCode)
            ->addParam("tl", targetCode)
            ->addParam("tk", GoogleUtils::makeToken(input))
            ->request()
            .then([this](QByteArray content) {
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
                emit onTranslationResult(result);
            });
}
