import QtQuick 2.15
import QtQuick.Controls 2.15

import UiBase 1.0
import "qrc:/qml"
import "qrc:/qml/styles"
import "qrc:/js/XFunctions.js" as Functions

Item {
    anchors.fill: parent

    XText {
        id: destText
        anchors.top: parent.top
        anchors.topMargin: Destiny.dp(24)
        anchors.horizontalCenter: parent.horizontalCenter
        xStyle: XTextStyleBlack { size: XTextStyle.Size.Content }
        text: "常规设置"
    }

    GroupBox {
        id: contentItem
        anchors.top: destText.bottom
        anchors.topMargin: Destiny.dp(24)
        anchors.left: parent.left
        anchors.leftMargin: Destiny.dp(36)
        anchors.right: parent.right
        anchors.rightMargin: Destiny.dp(36)

        label: XText {
            xStyle: XTextStyleBlack { size: XTextStyle.Size.AssistPrimary }
            text: "退出设置"
        }

        Column {
            XRadioButton {
                id: exitToTrayIcon
                textSize: Destiny.dp(12)
                text: "退出到托盘"
                checked: viewModel.showTrayIconWhenExit
                onCheckedChanged: {
                    viewModel.showTrayIconWhenExit = checked
                }
            }

            XRadioButton {
                id: exitImmediatelyBtn
                textSize: Destiny.dp(12)
                text: "直接退出"
                checked: !viewModel.showTrayIconWhenExit
            }
        }
    }
}
