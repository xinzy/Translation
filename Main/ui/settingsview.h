#ifndef SETTINGSVIEW_H
#define SETTINGSVIEW_H

#include "settingviewmodel.h"

#include <util/destiny.h>
#include <widget/xquickwidget.h>

#include <QQmlContext>

class SettingsView : public XQuickWidget
{
public:
    SettingsView(QWidget *parent = nullptr);

private:
    SettingViewModel *mViewModel;
};

#endif // SETTINGSVIEW_H
