#ifndef YOUDAOLANGPROVIDER_H
#define YOUDAOLANGPROVIDER_H

#include "youdaorestservice.h"

#include <core/langprovider.h>

class YoudaoLangProvider : public LangProvider
{
    Q_OBJECT

public:
    YoudaoLangProvider(QObject *parent = nullptr);

    virtual void translate(QString input, QString sourceCode, QString targetCode);

private:
    YoudaoRestService mService;
};

#endif // YOUDAOLANGPROVIDER_H
