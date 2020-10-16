#include "youdaolangprovider.h"

YoudaoLangProvider::YoudaoLangProvider(QObject *parent)
    : LangProvider(parent)
{
    initLangs(":/raw/lang.youdao.json");
    connect(&mService, &YoudaoRestService::onTranslationResult, this, [this](QString result) {
        emit onTranslationResult(result);
    });
}

void YoudaoLangProvider::translate(QString input, QString sourceCode, QString targetCode)
{
    mService.translate(input, sourceCode, targetCode);
}
