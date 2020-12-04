import QtQuick 2.15

import UiBase 1.0
import "qrc:/js/XFunctions.js" as Functions

Rectangle {
    id: buttonRoot

    color: Functions.backgroundColor(mouseArea)

    property int imageWidth: Destiny.dp(24)
    property int imageHeight: Destiny.dp(24)
    property var imageResource
    property int imageRotation: 0

    signal clicked()

    Image {
        id: image
        width: imageWidth
        height: imageHeight
        anchors.centerIn: parent
        rotation: imageRotation
        source: imageResource === undefined ? "" : imageResource
        visible: source !== ""

        Behavior on rotation {
            PropertyAnimation { duration: 300 }
        }
    }

    XMouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: buttonRoot.clicked()
    }
}
