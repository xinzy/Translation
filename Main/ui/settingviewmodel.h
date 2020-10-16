#ifndef SETTINGVIEWMODEL_H
#define SETTINGVIEWMODEL_H

#include <QAction>
#include <QObject>

#include "settingitem.h"

class SettingViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QList<SettingItem> settings READ settings NOTIFY settingsChanged)

public:
    explicit SettingViewModel(QObject *parent = nullptr);

    QList<SettingItem> settings() const;

signals:
    void settingsChanged();

private:
    QList<SettingItem> mSettings;
};

#endif // SETTINGVIEWMODEL_H
