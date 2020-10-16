import QtQuick 2.0

import UiBase 1.0
import "qrc:/qml"
import "qrc:/qml/styles"
import "qrc:/js/XFunctions.js" as Functions

Rectangle {
    anchors.fill: parent

    XText {
        id: destText
        anchors.left: parent.left
        anchors.leftMargin: Destiny.dp(16)
        anchors.top: parent.top
        anchors.topMargin: Destiny.dp(24)
        xStyle: XTextStyleBlack { size: XTextStyle.Size.AssistPrimary }
        text: "选择翻译引擎"
    }

    Component.onCompleted: {
        console.log(viewModel)
    }
}
