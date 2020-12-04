#include "config.h"
#include <utils/utils.h>

Config *Config::sInstance = nullptr;

static const QString KEY_ENGINE("Engine");
static const QString KEY_SHOW_TRAY_ICON_WHEN_EXIT("ShowTrayIconWhenExit");

static const QString KEY_ENABLE_PROXY("EnableProxy");
static const QString KEY_PROXY_URL("ProxyUrl");
static const QString KEY_PROXY_PORT("ProxyPort");
static const QString KEY_PROXY_USERNAME("ProxyUsername");
static const QString KEY_PROXY_PASSWORD("ProxyPassword");

static const QString KEY_BAIDU_APP_ID("BaiduAppId");
static const QString KEY_BAIDU_APP_SECERT("BaiduAppSecert");

static const QString KEY_YOUDAO_APP_ID("YoudaoAppId");
static const QString KEY_YOUDAO_APP_SECERT("YoudaoAppSecert");

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
    int engine = mSettings.value(KEY_ENGINE, 0).toInt();
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
    mSettings.setValue(KEY_ENGINE, engine);
}

bool Config::showTrayIconWhenExit()
{
    return mSettings.value(KEY_SHOW_TRAY_ICON_WHEN_EXIT, true).toBool();
}

void Config::setShowTrayIconWhenExit(bool b)
{
    mSettings.setValue(KEY_SHOW_TRAY_ICON_WHEN_EXIT, b);
    mSettings.sync();
}

bool Config::isEnableProxy()
{
    return mSettings.value(KEY_ENABLE_PROXY, false).toBool();
}

void Config::setEnableProxy(bool b)
{
    mSettings.setValue(KEY_ENABLE_PROXY, b);
    mSettings.sync();
}

Proxy Config::proxy()
{
    Proxy proxy;
    proxy.url = mSettings.value(KEY_PROXY_URL, "127.0.0.1").toString();
    proxy.port = mSettings.value(KEY_PROXY_PORT, "8888").toString();
    proxy.username = mSettings.value(KEY_PROXY_USERNAME, "").toString();
    proxy.password = mSettings.value(KEY_PROXY_PASSWORD, "").toString();
    return proxy;
}

void Config::setProxy(QString url, QString port, QString username, QString password)
{
    mSettings.setValue(KEY_PROXY_URL, url);
    mSettings.setValue(KEY_PROXY_PORT, port);
    mSettings.setValue(KEY_PROXY_USERNAME, username);
    mSettings.setValue(KEY_PROXY_PASSWORD, password);
    mSettings.sync();
}

ApiConfig Config::baiduApiConfig()
{
    ApiConfig config;
    config.appId = mSettings.value(KEY_BAIDU_APP_ID, "").toString();
    config.appSecert = mSettings.value(KEY_BAIDU_APP_SECERT, "").toString();
    return config;
}

void Config::saveBaiduApiConfig(ApiConfig &config)
{
    mSettings.setValue(KEY_BAIDU_APP_ID, config.appId);
    mSettings.setValue(KEY_BAIDU_APP_SECERT, config.appSecert);
    mSettings.sync();
}

ApiConfig Config::youdaoApiConfig()
{
    ApiConfig config;
    config.appId = mSettings.value(KEY_YOUDAO_APP_ID, "").toString();
    config.appSecert = mSettings.value(KEY_YOUDAO_APP_SECERT, "").toString();
    return config;
}

void Config::saveYoudaoApiConfig(ApiConfig &config)
{
    mSettings.setValue(KEY_YOUDAO_APP_ID, config.appId);
    mSettings.setValue(KEY_YOUDAO_APP_SECERT, config.appSecert);
    mSettings.sync();
}
