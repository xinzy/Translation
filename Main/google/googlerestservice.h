#ifndef GOOGLERESTSERVICE_H
#define GOOGLERESTSERVICE_H

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include <core/exception.h>
#include <http/baseapi.h>
#include "googleutils.h"

#define GOOGLE_BASE_API "https://translate.google.cn/translate_a/single"

class GoogleRestService : public BaseApi
{
    Q_OBJECT
public:
    GoogleRestService(QObject *parent = nullptr);

    void translate(QString text, QString sourceCode, QString targetCode);

protected:
    virtual void onNetworkRequest(QNetworkRequest &request) override;
    virtual void onNetworkFinished(QNetworkReply *reply) override;

private:
    QString parseResult(QByteArray &content);

signals:
    void onTranslationResult(QString result);
};

#endif // GOOGLERESTSERVICE_H
