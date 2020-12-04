#ifndef CONFIG_H
#define CONFIG_H

#include "apiconfig.h"
#include "proxy.h"

#include <core/translationengine.h>

#include <QSettings>

class Config
{
public:
    static Config* instance();

    void setupConfig();

    QList<TranslationEngine> &availableEngines();
    TranslationEngine currentTranslationEngine();

    Engine currentEngine();
    void changeEngine(Engine engine);

    bool showTrayIconWhenExit();
    void setShowTrayIconWhenExit(bool b);

    bool isEnableProxy();
    void setEnableProxy(bool b);

    Proxy proxy();
    void setProxy(QString url, QString port, QString username, QString password);

    ApiConfig baiduApiConfig();
    void saveBaiduApiConfig(ApiConfig &config);
    ApiConfig youdaoApiConfig();
    void saveYoudaoApiConfig(ApiConfig &config);

private:
    Config();

private:
    static Config* sInstance;
    Engine mTranslationEngine;
    QList<TranslationEngine> mAvailableEngines;
    QSettings mSettings;
};

#endif // CONFIG_H
