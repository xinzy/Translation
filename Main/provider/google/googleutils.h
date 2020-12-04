#ifndef GOOGLEUTILS_H
#define GOOGLEUTILS_H

#include <QFile>
#include <QDebug>
#include <QScriptEngine>

class GoogleUtils
{
public:
    GoogleUtils();

    static QString makeToken(QString input);
};

#endif // GOOGLEUTILS_H
