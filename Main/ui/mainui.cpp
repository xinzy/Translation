#include "mainui.h"

MainUI::MainUI(QWidget *parent)
    : XQuickWidget(parent),
      mViewModel(new MainUiViewModel(parent))
{
    setResizeMode(QQuickWidget::SizeRootObjectToView);

    rootContext()->setContextProperty("viewModel", mViewModel);
    setSource(QUrl("qrc:/qml/TranslationMainWindow.qml"));

    connect(quickWindow(), &QQuickWindow::activeFocusItemChanged, this, &MainUI::onActiveFocusItemChanged);
}

void MainUI::onActiveFocusItemChanged()
{
    QQuickItem *focusItem = quickWindow()->activeFocusItem();
    if (focusItem && focusItem->inherits("QQuickTextArea")) {
        clearFocus();
        focusItem->forceActiveFocus();
    }
}
