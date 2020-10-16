#include "baidulangprovider.h"

BaiduLangProvider::BaiduLangProvider(QObject *parent)
    : LangProvider(parent)
{
    initLangs(":/raw/lang.baidu.json");
    mService = new BaiduRestService(this);
    connect(mService, &BaiduRestService::onTranslationResult, this, [this](TranslationResult *result) {
        int size = result->result.size();
        QString content;
        for (int i = 0; i < size; i++) {
            auto item = result->result.at(i);
            content.append(item->dst).append("\n");
        }
        emit onTranslationResult(content);
    });
}

BaiduLangProvider::~BaiduLangProvider()
{
    delete mSupportedLangs;
}

QString BaiduLangProvider::autoLangCode() const
{
    return "auto";
}

void BaiduLangProvider::translate(QString input, QString sourceCode, QString targetCode)
{
    mService->translate(input, sourceCode, targetCode);
}
