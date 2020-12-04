import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import UiBase 1.0
import "qrc:/qml"
import "qrc:/qml/styles"
import "qrc:/js/XFunctions.js" as Functions

Rectangle {
    property var baiduApi: viewModel.baiduApi
    property var youdaoApi: viewModel.youdaoApi

    anchors.fill: parent

    XText {
        id: destText
        anchors.top: parent.top
        anchors.topMargin: Destiny.dp(24)
        anchors.horizontalCenter: parent.horizontalCenter
        xStyle: XTextStyleBlack { size: XTextStyle.Size.Content }
        text: "Api设置"
    }

    TabBar {
        id: bar
        width: parent.width
        anchors.top: destText.bottom
        anchors.topMargin: Destiny.dp(24)
        anchors.left: parent.left
        anchors.leftMargin: Destiny.dp(36)
        anchors.right: parent.right
        anchors.rightMargin: Destiny.dp(36)
        spacing: -1

        TabItem {
            id: baiduBtn
            width: Destiny.dp(64)
            text: "百度"
        }
        TabItem {
            id: youdaoBtn
            width: Destiny.dp(64)
            text: "有道"
        }
    }
    Rectangle {
        width: parent.width
        height: Destiny.dp(160)
        anchors.top: bar.bottom
        anchors.left: bar.left
        anchors.right: bar.right

        border.width: 1
        border.color: "#D9D9D9"

        Rectangle {
            width: Destiny.dp(126)
            height: 1
            color: parent.color
            anchors.leftMargin: 1
        }

        StackLayout {
            anchors.fill: parent
            anchors.topMargin: Destiny.dp(12)
            anchors.leftMargin: Destiny.dp(12)
            anchors.rightMargin: Destiny.dp(12)
            currentIndex: bar.currentIndex

            Column {
                id: homeTab
                spacing: Destiny.dp(12)

                InputContent {
                    id: baiduAppIdInput
                    width: parent.width
                    height: Destiny.dp(24)
                    titleWidth: Destiny.dp(72)
                    contentText: "App Id"
                    text: baiduApi.appId
                }

                InputContent {
                    id: baiduAppSecertInput
                    width: parent.width
                    height: Destiny.dp(24)
                    titleWidth: Destiny.dp(72)
                    contentText: "App Secert"
                    text: baiduApi.appSecert
                }
            }

            Column {
                id: discoverTab
                spacing: Destiny.dp(12)

                InputContent {
                    id: youdaoAppIdInput
                    width: parent.width
                    height: Destiny.dp(24)
                    titleWidth: Destiny.dp(72)
                    contentText: "App Id"
                    text: youdaoApi.appId
                }

                InputContent {
                    id: youdaoAppSecertInput
                    width: parent.width
                    height: Destiny.dp(24)
                    titleWidth: Destiny.dp(72)
                    contentText: "App Secert"
                    text: youdaoApi.appSecert
                }
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
            rootWidget.close()
        }
        onOkBtnClick: {
            if (bar.currentIndex == 0) {
                baiduApi.appId = baiduAppIdInput.text
                baiduApi.appSecert = baiduAppSecertInput.text
                viewModel.baiduApi = baiduApi
            } else if (bar.currentIndex == 1) {
                youdaoApi.appId = youdaoAppIdInput.text
                youdaoApi.appSecert = youdaoAppSecertInput.text
                viewModel.youdaoApi = youdaoApi
            }
            rootWidget.close()
        }
    }
}
