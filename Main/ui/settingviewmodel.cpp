#include "settingviewmodel.h"


SettingViewModel::SettingViewModel(QObject *parent)
    : QObject(parent)
{
    mSettings << SettingItem("翻译引擎", "", "qrc:/qml/SettingItemEngine.qml")
              << SettingItem("代理", "", "qrc:/qml/SettingItemProxy.qml")
              << SettingItem("Api设置", "", "qrc:/qml/SettingItemApi.qml");
}

QList<SettingItem> SettingViewModel::settings() const
{
    return mSettings;
}

QList<TranslationEngine> SettingViewModel::engines() const
{
    return Config::instance()->availableEngines();
}

int SettingViewModel::currentEngine() const
{
    return Config::instance()->currentEngine();
}
