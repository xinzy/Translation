import QtQuick 2.15

import UiBase 1.0
import "qrc:/qml"
import "qrc:/qml/styles"
import "qrc:/js/XFunctions.js" as Functions

Item {
    anchors.fill: parent
    property var proxy: viewModel.proxy

    onProxyChanged: {
        console.log(proxy)
    }

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

        XRadioButton {
            id: noproxyBtn
            text: "不使用代理"
            textSize: Destiny.dp(12)
            checked: !viewModel.enableProxy
        }

        XRadioButton {
            id: proxyBtn
            anchors.top: noproxyBtn.bottom
            textSize: Destiny.dp(12)
            text: "自定义代理"
            checked: viewModel.enableProxy
        }

        Column {
            id: inputArea
            width: parent.width - anchors.leftMargin - anchors.rightMargin
            anchors.left: parent.left
            anchors.leftMargin: Destiny.dp(24)
            anchors.right: parent.right
            anchors.rightMargin: Destiny.dp(24)
            anchors.top: proxyBtn.bottom
            anchors.topMargin: Destiny.dp(24)
            spacing: Destiny.dp(12)

            InputContent {
                id: urlText
                width: parent.width
                height: Destiny.dp(24)
                titleWidth: Destiny.dp(48)
                contentText: "服务器"
                enableInput: proxyBtn.checked
                text: viewModel.proxy.url
            }

            InputContent {
                id: portText
                width: parent.width
                height: Destiny.dp(24)
                titleWidth: Destiny.dp(48)
                contentText: "端口"
                enableInput: proxyBtn.checked
                text: viewModel.proxy.port
            }
            InputContent {
                id: usernameText
                width: parent.width
                height: Destiny.dp(24)
                titleWidth: Destiny.dp(48)
                contentText: "用户名"
                enableInput: proxyBtn.checked
                text: viewModel.proxy.username
            }

            InputContent {
                id: passwordText
                width: parent.width
                height: Destiny.dp(24)
                titleWidth: Destiny.dp(48)
                contentText: "密码"
                enableInput: proxyBtn.checked
                text: viewModel.proxy.password
            }
        }

        XText {
            id: errorText
            anchors.top: inputArea.bottom
            anchors.topMargin: Destiny.dp(12)
            xStyle: XTextStyleBlack { size: XTextStyle.Size.AssistSecondary }
            color: "red"
        }
    }

    SettingButtonBar {
        id: buttonBar
        width: parent.width
        height: Destiny.dp(48)
        anchors.bottom: parent.bottom
        anchors.bottomMargin: Destiny.dp(24)
        onCancelBtnClick: {
            rootWidget.close()
        }
        onOkBtnClick: {
            errorText.text = ""
            if (noproxyBtn.checked) {
                viewModel.enableProxy = false
            } else {
                console.log("save proxy", proxy, usernameText.text)
                if (proxy.url === "") {
                    errorText.text = "先输入服务器"
                } else if (proxy.port === "") {
                    errorText.text = "先输入端口号"
                } else {
                    viewModel.enableProxy = true
                    viewModel.setProxy(urlText.text, portText.text, usernameText.text, passwordText.text)
                }
            }
            rootWidget.close()
        }
    }
}
