#include "utils.h"

Utils::Utils()
{ }

QString Utils::getConfigPath()
{
    QString path = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation) + "\\config\\";
    if (!QFile::exists(path)) {
        QDir dest(path);
        dest.mkpath(path);
    }
    return path;
}
