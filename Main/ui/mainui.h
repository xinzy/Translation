#ifndef MAINUI_H
#define MAINUI_H

#include <QQmlContext>
#include <QQuickItem>

#include "mainuiviewmodel.h"
#include <widget/xquickwidget.h>

class MainUI : public XQuickWidget
{
public:
    MainUI(QWidget *parent = nullptr);

private slots:
    void onActiveFocusItemChanged();

private:
    MainUiViewModel *mViewModel;
};

#endif // MAINWINDOW_H
