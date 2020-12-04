#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    UiBase::init();
    setMinimumSize(Destiny::dp(960), Destiny::dp(640));

    initUi();
    initTrayIcon();

    mSystemTrayIcon->show();
}

MainWindow::~MainWindow()
{
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    hide();
    event->ignore();
}

void MainWindow::initUi()
{
    mMainUi = new MainUI(this);
    setCentralWidget(mMainUi);
}

void MainWindow::initTrayIcon()
{
    mSystemTrayIcon = new QSystemTrayIcon(this);
    mSystemTrayIcon->setToolTip("翻译");
    mSystemTrayIcon->setIcon(QIcon(":/resource/icon/icon.png"));

    mTrayMenu = new QMenu(this);
    mTrayMenu->addAction("显示主界面", this, [this]() {
        show();
    });
    mTrayMenu->addSeparator();
    mTrayMenu->addAction("退出", this, [this]() {
        qApp->exit();
    });

    connect(mSystemTrayIcon, &QSystemTrayIcon::activated, this, [this](QSystemTrayIcon::ActivationReason reason) {
        if (reason == QSystemTrayIcon::DoubleClick) {
            if (!isVisible()) show();
        }
    });

    mSystemTrayIcon->setContextMenu(mTrayMenu);
}

