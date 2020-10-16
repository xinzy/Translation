#ifndef UTILS_H
#define UTILS_H

#include <QObject>

#include <QDir>
#include <QFile>
#include <QStandardPaths>

class Utils
{
public:
    Utils();

    static QString getConfigPath();
};

#endif // UTILS_H
