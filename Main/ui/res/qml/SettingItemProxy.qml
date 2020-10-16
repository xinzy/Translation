import QtQuick 2.0

import UiBase 1.0
import "qrc:/qml"
import "qrc:/qml/styles"
import "qrc:/js/XFunctions.js" as Functions

Item {

    XText {
        id: itemText
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: Destiny.dp(24)
        xStyle: XTextStyleBlack { size: XTextStyle.Size.Content }
        text: "代理"
    }
}
