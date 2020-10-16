#include "settingsview.h"


SettingsView::SettingsView(QWidget *parent)
    : XQuickWidget(parent),
      mViewModel(new SettingViewModel(this))
{
    setWindowTitle("设置");
    setFixedSize(Destiny::dp(560), Destiny::dp(420));
    setResizeMode(QQuickWidget::SizeRootObjectToView);

    rootContext()->setContextProperty("viewModel", QVariant::fromValue(mViewModel));
    setSource(QUrl("qrc:/qml/SettingsWidget.qml"));
}
