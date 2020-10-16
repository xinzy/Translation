#ifndef GOOGLELANGPROVIDER_H
#define GOOGLELANGPROVIDER_H

#include "googlerestservice.h"

#include <core/langprovider.h>

class GoogleLangProvider : public LangProvider
{
    Q_OBJECT

public:
    GoogleLangProvider(QObject *parent = nullptr);

    virtual void translate(QString input, QString sourceCode, QString targetCode);


private:
    GoogleRestService mService;
};

#endif // GOOGLELANGPROVIDER_H
