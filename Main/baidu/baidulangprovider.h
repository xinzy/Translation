#ifndef BAIDULANGPROVIDER_H
#define BAIDULANGPROVIDER_H

#include "baidurestservice.h"

#include <QDebug>

#include <core/langprovider.h>

class BaiduLangProvider : public LangProvider
{
    Q_OBJECT

public:
    BaiduLangProvider(QObject *parent = nullptr);
    ~BaiduLangProvider();

    virtual QString autoLangCode() const override;

    virtual void translate(QString input, QString sourceCode, QString targetCode) override;

private:
    BaiduRestService *mService;
};

#endif // BAIDULANGPROVIDER_H
