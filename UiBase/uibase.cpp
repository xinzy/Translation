#include "uibase.h"

static bool isInit = false;

UiBase::UiBase(QObject *parent) : QObject(parent)
{ }

void UiBase::init()
{
    if (isInit) return ;
    isInit = true;

    qmlRegisterSingletonType<Destiny>("UiBase", 1, 0, "Destiny", [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        Destiny *destiny = new Destiny();
        return destiny;
    });

    qmlRegisterSingletonType<Utils>("UiBase", 1, 0, "Utils", [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        Utils *obj = new Utils();
        return obj;
    });
}
