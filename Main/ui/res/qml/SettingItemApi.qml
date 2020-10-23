import QtQuick 2.0
import QtQuick.Controls 2.15

import UiBase 1.0
import "qrc:/qml"
import "qrc:/qml/styles"
import "qrc:/js/XFunctions.js" as Functions

Rectangle {
    anchors.fill: parent

    XText {
        id: destText
        anchors.top: parent.top
        anchors.topMargin: Destiny.dp(24)
        anchors.horizontalCenter: parent.horizontalCenter
        xStyle: XTextStyleBlack { size: XTextStyle.Size.Content }
        text: "Api设置"
    }

    GroupBox {

        Column {

            RadioButton {
                text: "1"
            }
            RadioButton {
                text: "2"
            }
        }
    }
}
