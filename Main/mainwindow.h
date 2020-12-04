#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QSystemTrayIcon>

#include <ui/mainui.h>
#include <util/destiny.h>
#include <uibase.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    virtual void closeEvent(QCloseEvent *event);

private:
    void initUi();
    void initTrayIcon();

private:
    MainUI *mMainUi { nullptr };

    QSystemTrayIcon *mSystemTrayIcon = nullptr;

    QMenu *mTrayMenu = nullptr;


};
#endif // MAINWINDOW_H
