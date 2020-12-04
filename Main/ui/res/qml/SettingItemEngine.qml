import QtQuick 2.15
import QtQuick.Controls 2.15

import UiBase 1.0
import "qrc:/qml"
import "qrc:/qml/styles"
import "qrc:/js/XFunctions.js" as Functions

Rectangle {
    property var currentEngine: viewModel.currentEngine
    property var newEngine: viewModel.currentEngine
    anchors.fill: parent

    XText {
        id: destText
        anchors.top: parent.top
        anchors.topMargin: Destiny.dp(24)
        anchors.horizontalCenter: parent.horizontalCenter
        xStyle: XTextStyleBlack { size: XTextStyle.Size.Content }
        text: "选择翻译引擎"
    }

    ListView {
        id: engineListView
        width: Destiny.dp(300)
        height: Destiny.dp(240)
        anchors.top: destText.bottom
        anchors.topMargin: Destiny.dp(24)
        anchors.horizontalCenter: parent.horizontalCenter

        model: viewModel.engines
        delegate: Item {
            width: parent.width
            height: Destiny.dp(56)

            Rectangle {
                width: parent.width
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                anchors.topMargin: Destiny.dp(4)
                anchors.bottomMargin: Destiny.dp(4)

                color: Functions.backgroundColor(itemMouseArea)
                border.width: newEngine === modelData.engine ? Destiny.dp(2) : 0
                border.color: newEngine === modelData.engine ? "#4284F3" : "transparent"
                radius: Destiny.dp(8)

                Behavior on border.color {
                    PropertyAnimation { duration: 300 }
                }
                Behavior on border.width {
                    PropertyAnimation { duration: 300 }
                }

                Image {
                    id: itemIcon
                    width: Destiny.dp(24)
                    height: Destiny.dp(24)

                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: Destiny.dp(16)
                    source: modelData.icon
                }

                XText {
                    id: itemText
                    anchors.left: itemIcon.right
                    anchors.leftMargin: Destiny.dp(12)
                    anchors.verticalCenter: parent.verticalCenter
                    xStyle: XTextStyleBlack { size: XTextStyle.Size.AssistPrimary }
                    text: modelData.name
                }
            }

            XMouseArea {
                id: itemMouseArea
                anchors.fill: parent
                onClicked: {
                    selectEngine(modelData.engine)
                }
            }
        }
    }

    Popup {
        id: dialog
        width: Destiny.dp(320)
        height: Destiny.dp(164)
        y: (parent.height - height) / 2

        background: XShadow { }

        contentItem: Rectangle {
            XText {
                width: parent.width
                height: Destiny.dp(64)
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                xStyle: XTextStyleBlack { size: XTextStyle.Size.Content }
                text: "切换引擎需重启应用，确定要切换吗？"
            }

            SettingButtonBar {
                id: buttonBar
                width: parent.width
                height: Destiny.dp(48)
                anchors.bottom: parent.bottom
                isCancelVisible: false
                onOkBtnClick: {
                    rootWidget.close()
                    viewModel.switchEngine(newEngine)
                }
            }
        }

    }

    XHandler {
        id: handler
    }

    function selectEngine(engine) {
        newEngine = engine
        if (currentEngine !== engine) {
            handler.delay(500, function() {
                dialog.open()
            })
        }
    }
}
