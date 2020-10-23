#ifndef SETTINGVIEWMODEL_H
#define SETTINGVIEWMODEL_H

#include <QAction>
#include <QObject>

#include <core/translationengine.h>

#include "settingitem.h"
#include <core/config.h>

class SettingViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<SettingItem> settings READ settings NOTIFY settingsChanged)
    Q_PROPERTY(QList<TranslationEngine> engines READ engines NOTIFY enginesChanged)
    Q_PROPERTY(int currentEngine READ currentEngine NOTIFY currentEngineChanged)

public:
    explicit SettingViewModel(QObject *parent = nullptr);

    QList<SettingItem> settings() const;
    QList<TranslationEngine> engines() const;
    int currentEngine() const;

signals:
    void settingsChanged();
    void enginesChanged();
    void currentEngineChanged();

private:
    QList<SettingItem> mSettings;
};

#endif // SETTINGVIEWMODEL_H
