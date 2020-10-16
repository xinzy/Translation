#include "translator.h"


Translator::Translator(QObject *parent)
    : QObject(parent), mLangProvider(nullptr)
{
    initConfig();
    setupProvider();
}

void Translator::translate(QString input)
{
    mLangProvider->translate(input, mSourceLangCode, mTargetLangCode);
}

QString Translator::autoLangCode() const
{
    return mLangProvider->autoLangCode();
}

QList<Language *> *Translator::supportedLangs() const
{
    return mLangProvider->supportedLangs();
}

QList<Language *> Translator::commonSourceLanguage() const
{
    return mLangProvider->commonSourceLangs();
}

QList<Language *> Translator::commonTargetLanguage() const
{
    return mLangProvider->commonTargetLangs();
}

void Translator::setSourceLangCode(QString code)
{
    mSourceLangCode = code;
}

void Translator::setTargetLangCode(QString code)
{
    mTargetLangCode = code;
}

QString Translator::sourceLangCode() const
{
    return mSourceLangCode;
}

QString Translator::targetLangCode() const
{
    return mTargetLangCode;
}

Engine Translator::selectedEngine()
{
    return mCurrentEngine.engine();
}

void Translator::changeEngine(TranslationEngine &engine)
{
    mCurrentEngine = engine;
    Config::instance()->changeEngine(engine.engine());
    setupProvider();
}

void Translator::initConfig()
{
    mCurrentEngine = Config::instance()->currentTranslationEngine();
}

void Translator::setupProvider()
{
    if (mLangProvider) {
        disconnect(mLangProvider, 0, 0, 0);
        mLangProvider->deleteLater();
    }
    switch (mCurrentEngine.engine()) {
    case Engine::Baidu:
        mLangProvider = new BaiduLangProvider(this);
        break;
    case Engine::Youdao:
        mLangProvider = new YoudaoLangProvider(this);
        break;
    case Engine::Google:
    default:
        mLangProvider = new GoogleLangProvider(this);
        break;
    }

    connect(mLangProvider, &LangProvider::onTranslationResult, this, [this](QString result) {
        emit onTranslationResult(result);
    });
}
