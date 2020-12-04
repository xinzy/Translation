import QtQuick 2.15

import UiBase 1.0
import "qrc:/qml"
import "qrc:/qml/styles"
import "qrc:/js/XFunctions.js" as Functions

Item {
    property string cancelText: "取消"
    property string okText: "确定"
    property bool isOkEnabled: true
    property bool isCancelVisible: true

    signal okBtnClick()
    signal cancelBtnClick()

    XButton {
        id: okBtn
        anchors.right: parent.right
        anchors.rightMargin: Destiny.dp(24)
        xStyle: XButtonStylePrimary { size: XButtonStyle.Size.S }
        text: okText
        enabled: isOkEnabled
        onClicked: {
            okBtnClick()
        }
    }

    XButton {
        id: cancelBtn
        anchors.right: okBtn.left
        anchors.rightMargin: Destiny.dp(16)
        xStyle: XButtonStyleGhostSecondary { size: XButtonStyle.Size.S }
        visible: isCancelVisible
        text: cancelText
        onClicked: {
            cancelBtnClick()
        }
    }
}
