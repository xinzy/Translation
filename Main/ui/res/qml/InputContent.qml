import QtQuick 2.15
import QtQuick.Controls 2.15

import UiBase 1.0
import "qrc:/qml"
import "qrc:/qml/styles"

Item {
    property string contentText: ""
    property string placeholderText: ""
    property int titleWidth: 0
    property string text: ""
    property bool enableInput: true

    XText {
        id: titleText
        height: implicitHeight
        width: Math.max(titleWidth, implicitWidth)
        anchors.verticalCenter: parent.verticalCenter
        xStyle: XTextStyleBlack { size: XTextStyle.Size.AssistPrimary }
        text: contentText
    }

    TextField {
        id: textField
        height: parent.height
        width: parent.width - titleText.width - anchors.leftMargin
        anchors.left: titleText.right
        anchors.leftMargin: Destiny.dp(8)
        enabled: enableInput
        placeholderText: placeholderText
        text: parent.text

        onTextChanged: parent.text = text
    }
}
