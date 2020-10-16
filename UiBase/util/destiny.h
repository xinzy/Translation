#ifndef DESTINY_H
#define DESTINY_H

#include <QObject>

#include <QGuiApplication>
#include <QScreen>

#include <algorithm>

#include "UiBase_global.h"

class UIBASE_EXPORT Destiny : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int screenWidth READ screenWidth NOTIFY screenWidthChanged)
    Q_PROPERTY(int screenHeight READ screenHeight NOTIFY screenHeightChanged)

public:
    Destiny();

    Q_INVOKABLE static int getScreenWidth();

    Q_INVOKABLE static int getScreenHeight();

    Q_INVOKABLE static int dp(float dp);

    Q_INVOKABLE static int sp(float sp);

    int screenWidth() const;
    int screenHeight() const;

signals:
    void screenWidthChanged();
    void screenHeightChanged();

private:
    static void checkInit();

private:
    static bool isInited;

};

#endif // DESTINY_H
