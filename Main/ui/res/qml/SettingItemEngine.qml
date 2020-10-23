import QtQuick 2.0

import UiBase 1.0
import "qrc:/qml"
import "qrc:/qml/styles"
import "qrc:/js/XFunctions.js" as Functions

Rectangle {
    property int currentEngine: viewModel.currentEngine
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
                border.width: currentEngine == modelData.engine ? Destiny.dp(2) : 0
                border.color: currentEngine == modelData.engine ? "#4284F3" : "transparent"
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

    function selectEngine(engine) {
        currentEngine = engine
    }
}
