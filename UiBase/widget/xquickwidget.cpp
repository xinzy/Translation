#include "xquickwidget.h"
#include <QQmlContext>

XQuickWidget::XQuickWidget(QWidget *parent) : QQuickWidget(parent)
{
    setStyleSheet("background-color:transparent;");
    setClearColor(QColor(Qt::transparent));

    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_AcceptTouchEvents);
    setAttribute(Qt::WA_DeleteOnClose);

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    rootContext()->setContextProperty("rootWidget", this);
}
