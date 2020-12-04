#ifndef BAIDULANGPROVIDER_H
#define BAIDULANGPROVIDER_H

#include <core/langprovider.h>

#include "translationresult.h"

#define BAIDU_APP_ID "20200914000565830"
#define BAIDU_APP_SERCERT "iYohXtxWzMtlUGgATcJh"
#define BAIDU_API_URL "http://api.fanyi.baidu.com/api/trans/vip/translate"

class BaiduLangProvider : public LangProvider
{
    Q_OBJECT

public:
    BaiduLangProvider(QObject *parent = nullptr);
    ~BaiduLangProvider();

    virtual QString autoLangCode() const override;

    virtual void translate(QString input, QString sourceCode, QString targetCode) override;

private:
    QString createRandom();
    QString makeSign(QString &text, QString &salt);

    QString appId();
    QString appSecert();
};

#endif // BAIDULANGPROVIDER_H
