import QtQuick 2.15
import QtQuick.Controls 2.15

import UiBase 1.0
import "qrc:/js/XConst.js" as Const

RadioButton {
    id: control

    property var indicatorSize: Destiny.dp(18)
    property int textSize: Destiny.dp(16)

    font.family: Const.DefaultFont
    font.pixelSize: textSize

    indicator: Rectangle {
        implicitWidth: indicatorSize
        implicitHeight: indicatorSize

        x: control.text ? (control.mirrored ? control.width - width - control.rightPadding : control.leftPadding) : control.leftPadding + (control.availableWidth - width) / 2
        y: control.topPadding + (control.availableHeight - height) / 2

        radius: width / 2
        color: control.down ? control.palette.light : control.palette.base
        border.width: control.visualFocus ? 2 : 1
        border.color: control.visualFocus ? control.palette.highlight : control.palette.mid

        Rectangle {
            x: (parent.width - width) / 2
            y: (parent.height - height) / 2
            width: indicatorSize * 2 / 3
            height: indicatorSize * 2 / 3
            radius: width / 2
            color: control.palette.text
            visible: control.checked
        }
    }

    contentItem: Text {
        leftPadding: control.indicator && !control.mirrored ? control.indicator.width + control.spacing : 0
        rightPadding: control.indicator && control.mirrored ? control.indicator.width + control.spacing : 0

        text: control.text
        font: control.font
        color: control.palette.windowText
    }
}
