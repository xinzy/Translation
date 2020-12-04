#ifndef GOOGLELANGPROVIDER_H
#define GOOGLELANGPROVIDER_H

#include "googleutils.h"
#include "googleutils.h"

#include <core/langprovider.h>
#include <http/httpmanager.h>

#include <QUrl>

#define GOOGLE_BASE_API "https://translate.google.cn/translate_a/single"

class GoogleLangProvider : public LangProvider
{
    Q_OBJECT

public:
    GoogleLangProvider(QObject *parent = nullptr);

    virtual void translate(QString input, QString sourceCode, QString targetCode);

};

#endif // GOOGLELANGPROVIDER_H
