#ifndef UIBASEHELPER_H
#define UIBASEHELPER_H

#include <QObject>
#include <QQmlEngine>

#include <util/destiny.h>
#include <util/utils.h>
#include "UiBase_global.h"

class UIBASE_EXPORT UiBase : public QObject
{
    Q_OBJECT

public:
    explicit UiBase(QObject *parent = nullptr);

    static void init();

signals:

};

#endif // UIBASEHELPER_H
