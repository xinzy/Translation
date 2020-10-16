#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <ui/mainui.h>
#include <util/destiny.h>
#include <uibase.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initUi();

private:
    MainUI *mMainUi { nullptr };

};
#endif // MAINWINDOW_H
