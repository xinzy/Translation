#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    UiBase::init();
    setMinimumSize(Destiny::dp(960), Destiny::dp(640));
    initUi();
}

MainWindow::~MainWindow()
{
}

void MainWindow::initUi()
{
    mMainUi = new MainUI(this);
    setCentralWidget(mMainUi);
}

