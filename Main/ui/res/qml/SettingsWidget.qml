import QtQuick 2.15

import UiBase 1.0
import "qrc:/qml"
import "qrc:/qml/styles"
import "qrc:/js/XFunctions.js" as Functions

Rectangle {
    color: "white"

    property int currentSelectedIndex: 0

    Rectangle {
        id: divider
        width: parent.width
        height: Destiny.dp(1)
        color: "#E2E3E4"
    }

    Rectangle {
        id: settingItems
        width: Destiny.dp(160)
        height: parent.height
        anchors.top: divider.bottom
        color: "#FAFAFA"

        Rectangle {
            width: Destiny.dp(1)
            height: parent.height
            anchors.right: parent.right
            color: "#E2E3E4"
        }

        ListView {
            id: settingListView
            width: parent.width
            height: parent.height

            model: viewModel.settings
            delegate: Rectangle {
                width: parent.width
                height: Destiny.dp(64)
                color: index === currentSelectedIndex ? "#FFFFFF" : "#00000000"

                Rectangle {
                    width: parent.width
                    height: Destiny.dp(1)
                    anchors.top: parent.top
                    color: "#E2E3E4"
                    visible: index !== 0 && index === currentSelectedIndex
                }

                Rectangle {
                    width: parent.width
                    height: Destiny.dp(1)
                    anchors.bottom: parent.bottom
                    color: "#E2E3E4"
                    visible: index === currentSelectedIndex
                }

                XText {
                    id: itemText
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: Destiny.dp(24)
                    xStyle: XTextStyleBlack { size: XTextStyle.Size.Content }
                    singleLine: true
                    text: modelData.name
                }

                XMouseArea {
                    anchors.fill: parent
                    onClicked: {
                        currentSelectedIndex = index
                        settingLoader.source = modelData.url
                    }
                }
            }
        }
    }

    Loader {
        id: settingLoader
        width: parent.width - settingItems.width
        height: settingItems.height
        anchors.left: settingItems.right
        anchors.top: divider.bottom
        source: viewModel.settings[0].url
    }

    Component.onCompleted: {
        console.log(viewModel.settings)
    }
}
