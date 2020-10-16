#ifndef XQUICKWIDGET_H
#define XQUICKWIDGET_H

#include <QQuickWidget>

#include "UiBase_global.h"

class UIBASE_EXPORT XQuickWidget : public QQuickWidget
{
public:
    XQuickWidget(QWidget *parent = nullptr);
};

#endif // XQUICKWIDGET_H
