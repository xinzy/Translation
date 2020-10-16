#include "baidurestservice.h"

BaiduRestService::BaiduRestService(QObject *parent)
    : BaseApi(parent)
{
}

void BaiduRestService::translate(QString text, QString sourceCode, QString targetCode)
{
    QMap<QString, QString> params;
    params["q"] = QUrl::toPercentEncoding(text);
    params["from"] = sourceCode;
    params["to"] = targetCode;
    params["appid"] = BAIDU_APP_ID;
    QString salt = createRandom();
    params["salt"] = salt;
    params["sign"] = makeSign(text, salt);

    qDebug() << params;
    post(BAIDU_API_URL, params);
}

void BaiduRestService::onNetworkRequest(QNetworkRequest &request)
{
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
}

void BaiduRestService::onNetworkFinished(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();

    try {
        TranslationResult *resut = parseResult(data);
        qDebug().noquote() << *resut;
        emit onTranslationResult(resut);
    } catch (Exception &e) {
        qWarning() << e.message();
    }
}

TranslationResult *BaiduRestService::parseResult(QByteArray &content)
{
    QJsonDocument document = QJsonDocument::fromJson(content);
    QJsonObject jsonObject = document.object();

    if (jsonObject.contains("error_msg")) {
        QString msg = jsonObject.value("error_msg").toString();
        QString code = jsonObject.value("error_code").toString();
        throw Exception(msg + "(" + code + ")");
    }

    TranslationResult *result = new TranslationResult;
    result->from = jsonObject.value("from").toString();
    result->to = jsonObject.value("to").toString();

    QJsonArray array = jsonObject.value("trans_result").toArray();
    int size = array.size();
    for (int i = 0; i < size; i++) {
        QJsonObject json = array.at(i).toObject();
        ResultItem *item = new ResultItem;
        item->src = json.value("src").toString();
        item->dst = json.value("dst").toString();

        result->result.append(item);
    }

    return result;
}

QString BaiduRestService::createRandom()
{
    int num = QRandomGenerator::global()->bounded(100000, 999999);
    return QString::number(num);
}

QString BaiduRestService::makeSign(QString &text, QString &salt)
{
    QString str;
    str.append(BAIDU_APP_ID).append(text).append(salt).append(BAIDU_APP_SERCERT);
    qDebug() << str;
    QByteArray ba = QCryptographicHash::hash(str.toUtf8(), QCryptographicHash::Md5);
    return ba.toHex();
}
