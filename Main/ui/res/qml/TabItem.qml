import QtQuick 2.0
import QtQuick.Controls 2.15

import UiBase 1.0
import "qrc:/qml"
import "qrc:/qml/styles"
import "qrc:/js/XConst.js" as Const

TabButton {
    id: control

    background: Rectangle {
        color: control.checked ? "#FFFFFF" :
                    (control.hovered ? "#D8EAF9" : "#F0F0F0")

        border.width: 1
        border.color: "#D9D9D9"

        Rectangle {
            width: parent.width - 2
            height: 1
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            color: parent.color
            visible: control.checked
        }
    }
    hoverEnabled: true
    contentItem: XText {
        width: parent.width
        horizontalAlignment: Text.AlignHCenter
        text: control.text
        xStyle: XTextStyleBlack { size: XTextStyle.Size.AssistPrimary }
    }
}
