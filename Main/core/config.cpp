#include "config.h"

Config *Config::sInstance = nullptr;

Config::Config() : mTranslationEngine(Engine::Google),
    mSettings(Utils::getConfigPath() + "config.ini", QSettings::IniFormat)
{
    mAvailableEngines << TranslationEngine(Engine::Google, "Google", "qrc:/resource/icon/google.png")
                      << TranslationEngine(Engine::Baidu, "百度", "qrc:/resource/icon/baidu.png")
                      << TranslationEngine(Engine::Youdao, "有道", "qrc:/resource/icon/youdao.png");
    setupConfig();
}

Config *Config::instance()
{
    if (!sInstance) {
        sInstance = new Config;
        sInstance->setupConfig();
    }
    return sInstance;
}

void Config::setupConfig()
{
    int engine = mSettings.value("engine", 0).toInt();
    mTranslationEngine = Engine(engine);
}

QList<TranslationEngine> &Config::availableEngines()
{
    return mAvailableEngines;
}

TranslationEngine Config::currentTranslationEngine()
{
    for (int i = 0; i < mAvailableEngines.size(); i++) {
        if (currentEngine() == mAvailableEngines.at(i).engine()) {
            return mAvailableEngines.at(i);
        }
    }
    return mAvailableEngines.at(0);
}

Engine Config::currentEngine()
{
    return mTranslationEngine;
}

void Config::changeEngine(Engine engine)
{
    mTranslationEngine = engine;
    mSettings.setValue("engine", engine);
}
