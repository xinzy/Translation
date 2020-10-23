import QtQuick 2.12
import QtQuick.Controls 2.5

import UiBase 1.0

Text {
    property bool singleLine: false
    property bool needShowTipElide: false

    id: taltext
    width: Math.min(implicitWidth,parent.width)
    height: implicitHeight
    property XTextStyle xStyle: XTextStyle { }
    font {
        family: xStyle.fontFamily();
        pixelSize: xStyle.fontPixelSize()
        bold: xStyle.fontBold
    }
    color: xStyle.fontColor()
    Keys.enabled: needShowTipElide
    opacity: xStyle.fontOpacity
    verticalAlignment: Text.AlignVCenter
    horizontalAlignment: Text.AlignLeft
    wrapMode: singleLine ? Text.Normal : Text.WrapAnywhere
    elide: Text.ElideRight
}
