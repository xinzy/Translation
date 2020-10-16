#include "googlelangprovider.h"

GoogleLangProvider::GoogleLangProvider(QObject *parent)
    : LangProvider(parent)
{
    initLangs(":/raw/lang.google.json");

    connect(&mService, &GoogleRestService::onTranslationResult, this, [this](QString result) {
        qDebug() << "google translate result: " << result;
        emit onTranslationResult(result);
    });
}

void GoogleLangProvider::translate(QString input, QString sourceCode, QString targetCode)
{
    mService.translate(input, sourceCode, targetCode);
}
