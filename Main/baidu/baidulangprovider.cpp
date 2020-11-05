#include "baidulangprovider.h"

BaiduLangProvider::BaiduLangProvider(QObject *parent)
    : LangProvider(parent)
{
    initLangs(":/raw/lang.baidu.json");

    JsonSerializer::registerListConverters<ResultItem>();
}

BaiduLangProvider::~BaiduLangProvider()
{
    delete mSupportedLangs;
}

QString BaiduLangProvider::autoLangCode() const
{
    return "auto";
}

void BaiduLangProvider::translate(QString input, QString sourceCode, QString targetCode)
{
    QString salt = createRandom();
    QString text = QUrl::toPercentEncoding(input);
    HttpManager::post(BAIDU_API_URL)->setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded")
            ->addParam("q", text)
            ->addParam("from", sourceCode)
            ->addParam("to", targetCode)
            ->addParam("appid", BAIDU_APP_ID)
            ->addParam("salt", salt)
            ->addParam("sign", makeSign(input, salt))
            ->request<TranslationResult>()
            .then([this](TranslationResult result) {

                qDebug().noquote() << result;
                int size = result.result.size();
                QString content;
                for (int i = 0; i < size; i++) {
                    auto item = result.result.at(i);
                    content.append(item.dst).append("\n");
                }
                emit onTranslationResult(content);
            });
}

QString BaiduLangProvider::createRandom()
{
    int num = QRandomGenerator::global()->bounded(100000, 999999);
    return QString::number(num);
}

QString BaiduLangProvider::makeSign(QString &text, QString &salt)
{
    QString str;
    str.append(BAIDU_APP_ID).append(text).append(salt).append(BAIDU_APP_SERCERT);
    qDebug() << str;
    QByteArray ba = QCryptographicHash::hash(str.toUtf8(), QCryptographicHash::Md5);
    return ba.toHex();
}
