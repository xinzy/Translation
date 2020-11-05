#ifndef YOUDAOLANGPROVIDER_H
#define YOUDAOLANGPROVIDER_H

#include <core/langprovider.h>
#include <http/httpmanager.h>

#include "youdaotranslateresult.h"

#define YOUDAO_APP_ID "229d103f10e5a0dc"
#define YOUDAO_APP_SECERT "5v0kkMOsGQm8VygPIJ2r79fGwi0kq8A7"
#define YOUDAO_BASE_API "https://openapi.youdao.com/api"

class YoudaoLangProvider : public LangProvider
{
    Q_OBJECT

public:
    YoudaoLangProvider(QObject *parent = nullptr);

    virtual void translate(QString input, QString sourceCode, QString targetCode);

private:
    QString makeSign(QString &input, QString &salt, QString &timestamp);
};

#endif // YOUDAOLANGPROVIDER_H
