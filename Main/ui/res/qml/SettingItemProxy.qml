import QtQuick 2.0
import QtQuick.Controls 1.4

import UiBase 1.0
import "qrc:/qml"
import "qrc:/qml/styles"
import "qrc:/js/XFunctions.js" as Functions

Item {
    anchors.fill: parent
    property bool proxyEnable: false

    XText {
        id: destText
        anchors.top: parent.top
        anchors.topMargin: Destiny.dp(24)
        anchors.horizontalCenter: parent.horizontalCenter
        xStyle: XTextStyleBlack { size: XTextStyle.Size.Content }
        text: "代理设置"
    }

    Item {
        id: contentItem
        anchors.top: destText.bottom
        anchors.topMargin: Destiny.dp(24)
        anchors.left: parent.left
        anchors.leftMargin: Destiny.dp(36)
        anchors.right: parent.right
        anchors.rightMargin: Destiny.dp(36)

        ExclusiveGroup { id: proxyGroup }
        XRadioButton {
            id: noproxyBtn
            exclusiveGroup: proxyGroup
            text: "不使用代理"
        }

        XRadioButton {
            id: proxyBtn
            anchors.top: noproxyBtn.bottom
            anchors.topMargin: Destiny.dp(12)
            exclusiveGroup: proxyGroup
            text: "自定义代理"
        }

        Column {
            width: parent.width - anchors.leftMargin - anchors.rightMargin
            height: Destiny.dp(200)
            anchors.left: parent.left
            anchors.leftMargin: Destiny.dp(24)
            anchors.right: parent.right
            anchors.rightMargin: Destiny.dp(24)
            anchors.top: proxyBtn.bottom
            anchors.topMargin: Destiny.dp(24)
            spacing: Destiny.dp(12)

            InputContent {
                width: parent.width
                height: Destiny.dp(24)
                titleWidth: Destiny.dp(48)
                contentText: "服务器"
                enableInput: proxyEnable
            }

            InputContent {
                width: parent.width
                height: Destiny.dp(24)
                titleWidth: Destiny.dp(48)
                contentText: "端口"
                enableInput: proxyEnable
            }
            InputContent {
                width: parent.width
                height: Destiny.dp(24)
                titleWidth: Destiny.dp(48)
                contentText: "用户名"
                enableInput: proxyEnable
            }

            InputContent {
                width: parent.width
                height: Destiny.dp(24)
                titleWidth: Destiny.dp(48)
                contentText: "密码"
                enableInput: proxyEnable
            }
        }
    }

    SettingButtonBar {
        id: buttonBar
        width: parent.width
        height: Destiny.dp(48)
        anchors.bottom: parent.bottom
        anchors.bottomMargin: Destiny.dp(24)
        onCancelBtnClick: {
        }
        onOkBtnClick: {
        }
    }
}
