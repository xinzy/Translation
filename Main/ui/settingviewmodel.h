#ifndef SETTINGVIEWMODEL_H
#define SETTINGVIEWMODEL_H

#include <QAction>
#include <QObject>

#include <core/translationengine.h>

#include "settingitem.h"
#include <utils/config.h>

class SettingViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<SettingItem> settings READ settings NOTIFY settingsChanged)
    Q_PROPERTY(QList<TranslationEngine> engines READ engines NOTIFY enginesChanged)
    Q_PROPERTY(Engine currentEngine READ currentEngine NOTIFY currentEngineChanged)
    Q_PROPERTY(bool showTrayIconWhenExit READ showTrayIconWhenExit WRITE setShowTrayIconWhenExit NOTIFY showTrayIconWhenExitChanged)
    Q_PROPERTY(bool enableProxy READ enableProxy WRITE setEnableProxy NOTIFY enableProxyChanged)
    Q_PROPERTY(Proxy proxy READ proxy NOTIFY proxyChanged)

    Q_PROPERTY(ApiConfig baiduApi READ baiduApi WRITE setBaiduApi NOTIFY baiduApiChanged)
    Q_PROPERTY(ApiConfig youdaoApi READ youdaoApi WRITE setYoudaoApi NOTIFY youdaoApiChanged)

public:
    explicit SettingViewModel(QObject *parent = nullptr);

    QList<SettingItem> settings() const;
    QList<TranslationEngine> engines() const;
    Engine currentEngine() const;
    Q_INVOKABLE void switchEngine(Engine engine);

    bool showTrayIconWhenExit() const;
    void setShowTrayIconWhenExit(bool b);

    bool enableProxy() const;
    void setEnableProxy(bool b);

    Proxy proxy() const;
    Q_INVOKABLE void setProxy(QString url, QString port, QString username, QString password);

    ApiConfig baiduApi() const;
    void setBaiduApi(ApiConfig config);

    ApiConfig youdaoApi() const;
    void setYoudaoApi(ApiConfig config);

signals:
    void settingsChanged();
    void enginesChanged();
    void currentEngineChanged();

    void showTrayIconWhenExitChanged();
    void enableProxyChanged();
    void proxyChanged();

    void baiduApiChanged();
    void youdaoApiChanged();
private:
    QList<SettingItem> mSettings;
};

#endif // SETTINGVIEWMODEL_H
