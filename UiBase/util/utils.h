#ifndef UTILS_H
#define UTILS_H

#include <QObject>
#include <QQuickWindow>

#include "UiBase_global.h"

class UIBASE_EXPORT Utils : public QObject
{
public:
    Utils();

    Q_INVOKABLE static bool isSoftwareRender();
};

#endif // UTILS_H
