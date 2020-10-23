import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

import UiBase 1.0
import "./styles"

RadioButton {

    style: RadioButtonStyle {
        indicator: Rectangle {
            width: Destiny.dp(20)
            height: Destiny.dp(20)
            radius: Destiny.dp(10)
            border.color: control.activeFocus ? "darkblue" : "gray"
            border.width: 1
            Rectangle {
                anchors.fill: parent
                visible: control.checked
                color: "#555"
                radius: 8
                anchors.margins: 4
            }
        }
        label: XText {
            width: implicitWidth
            height: implicitHeight
            xStyle: XTextStyleBlack { size: XTextStyle.Size.AssistPrimary }
            text: control.text

            XMouseArea {
                anchors.fill: parent
                onClicked: {
                    control.checked = true
                }
            }
        }
        spacing: Destiny.dp(8)
    }
}
