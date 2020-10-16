#ifndef CONFIG_H
#define CONFIG_H

#include "translationengine.h"
#include <utils/utils.h>

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

private:
    Config();

private:
    static Config* sInstance;
    Engine mTranslationEngine;
    QList<TranslationEngine> mAvailableEngines;
    QSettings mSettings;
};

#endif // CONFIG_H
