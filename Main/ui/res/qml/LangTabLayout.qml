import QtQuick 2.15

import UiBase 1.0
import "qrc:/qml/styles"
import "qrc:/qml"
import "qrc:/js/XFunctions.js" as Functions

Item {
    id: tabContainer
    property int itemWidth: Destiny.dp(72)
    property int animDuration: 300
    property var model

    property int selectedIndex: 0

    signal itemTabClick(int index)

    width: model.length * itemWidth

    ListView {
        id: contentListView
        width: parent.width
        height: parent.height
        orientation: ListView.Horizontal
        boundsBehavior: Flickable.StopAtBounds

        model: parent.model
        delegate: Rectangle {
            width: itemWidth
            height: parent.height
            color: Functions.backgroundColor(itemMouseArea)

            XText {
                id: itemText
                anchors.centerIn: parent
                xStyle: XTextStyleBlack {
                    size: modelData.text.length >= 4 ?  XTextStyle.Size.AssistPrimary : XTextStyle.Size.Content
                }
                singleLine: true
                text: modelData.text
            }

            XMouseArea {
                id: itemMouseArea
                anchors.fill: parent

                onClicked: {
//                    tabContainer.selectedIndex = index
                    console.log("currentIndex", index)
                    modelData.trigger()

                    itemTabClick(index)
                }
            }
        }
    }

    Rectangle {
        id: indicatorRect
        width: itemWidth
        height: Destiny.dp(3)
        anchors.bottom: parent.bottom
        color: "#4284F3"
        x: selectedIndex * itemWidth

        Behavior on x {
            PropertyAnimation { duration: animDuration }
        }
    }
}
