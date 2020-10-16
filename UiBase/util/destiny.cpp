#include "destiny.h"

bool Destiny::isInited = false;

static int sScreenWidth = 0;
static int sScreenHeight = 0;
static float sDestiny = 1.0;

Destiny::Destiny() : QObject()
{
    checkInit();
}

int Destiny::getScreenWidth()
{
    checkInit();
    return sScreenWidth;
}

int Destiny::getScreenHeight()
{
    checkInit();
    return sScreenHeight;
}

int Destiny::dp(float dp)
{
    checkInit();
    return std::max(dp * sDestiny, 1.0f);
}

int Destiny::sp(float sp)
{
    checkInit();
    return std::max(sp * sDestiny, 1.0f);
}

int Destiny::screenWidth() const
{
    return sScreenWidth;
}

int Destiny::screenHeight() const
{
    return sScreenHeight;
}

void Destiny::checkInit()
{
    if (isInited) return ;
    isInited = true;

    sScreenWidth = QGuiApplication::primaryScreen()->size().width();
    sScreenHeight = QGuiApplication::primaryScreen()->size().height();

    sDestiny = sScreenHeight / 1080.0;
}
