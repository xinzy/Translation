#include "settingviewmodel.h"

#include <QProcess>
#include <QApplication>
#include <QTimer>

SettingViewModel::SettingViewModel(QObject *parent)
    : QObject(parent)
{
    mSettings << SettingItem("常规设置", "", "qrc:/qml/SettingItemGeneral.qml")
              << SettingItem("翻译引擎", "", "qrc:/qml/SettingItemEngine.qml")
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

Engine SettingViewModel::currentEngine() const
{
    return Config::instance()->currentEngine();
}

void SettingViewModel::switchEngine(Engine engine)
{
    Config::instance()->changeEngine(engine);

    QTimer::singleShot(100, [](){
        qApp->quit();
        QProcess::startDetached(qApp->applicationFilePath(), QStringList());
    });
}

bool SettingViewModel::showTrayIconWhenExit() const
{
    return Config::instance()->showTrayIconWhenExit();
}

void SettingViewModel::setShowTrayIconWhenExit(bool b)
{
    Config::instance()->setShowTrayIconWhenExit(b);
}

bool SettingViewModel::enableProxy() const
{
    return Config::instance()->isEnableProxy();
}

void SettingViewModel::setEnableProxy(bool b)
{
    Config::instance()->setEnableProxy(b);
}

Proxy SettingViewModel::proxy() const
{
    return Config::instance()->proxy();
}

void SettingViewModel::setProxy(QString url, QString port, QString username, QString password)
{
    Config::instance()->setProxy(url, port, username, password);
}

ApiConfig SettingViewModel::baiduApi() const
{
    return Config::instance()->baiduApiConfig();
}

void SettingViewModel::setBaiduApi(ApiConfig config)
{
    Config::instance()->saveBaiduApiConfig(config);
}

ApiConfig SettingViewModel::youdaoApi() const
{
    return Config::instance()->youdaoApiConfig();
}

void SettingViewModel::setYoudaoApi(ApiConfig config)
{
    Config::instance()->saveYoudaoApiConfig(config);
}
