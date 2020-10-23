import QtQuick 2.12
import QtQuick.Controls 2.5

import UiBase 1.0

import "./"

Rectangle {
    id: talButtonRoot

    property XButtonStyle xStyle : XButtonStyle{ }

    property bool loading: false
    property var text: ""
    property var animDuration: 200
    implicitWidth: contentLayout.width + radius * 2
    width: Math.max(implicitWidth, xStyle.width)
    height: xStyle.height
    radius: xStyle.radius
    border.width: xStyle.borderWidth
    border.color: getBorderColor()
    color: getColor()
    opacity: enabled ? 1 : xStyle.opacityDisabled

    Behavior on color {
        PropertyAnimation { duration: animDuration}
    }

    Behavior on border.color {
        PropertyAnimation { duration: animDuration}
    }

    Behavior on opacity {
        PropertyAnimation { duration: animDuration}
    }

    Item {
        id: contentLayout
        width: leftIcon.width + textContent.width + rightIcon.width + textContent.anchors.leftMargin + rightIcon.anchors.leftMargin
        height: parent.height
        anchors.horizontalCenter: parent.horizontalCenter
        visible: !loading

        Image {
            id: leftIcon
            width: xStyle.iconLeftWidth
            height: xStyle.iconLeftHeight
            source: talButtonRoot.visible ? getIconLeft() : ""
            anchors.verticalCenter: parent.verticalCenter
            visible: source != ""
        }

        Text {
            id: textContent
            width: implicitWidth
            height: implicitHeight
            color: getTextColor()
            text: talButtonRoot.text
            font.pixelSize: talButtonRoot.xStyle.fontPixelSize
            font.bold: talButtonRoot.xStyle.fontBold
            font.italic: talButtonRoot.xStyle.fontItalic
            font.family: talButtonRoot.xStyle.fontFamily
            anchors.left: leftIcon.right
            anchors.leftMargin: leftIcon.source != "" ? Destiny.dp(8) : 0
            wrapMode: Text.Normal
            verticalAlignment: TextInput.AlignVCenter
            elide: Text.ElideRight
            anchors.verticalCenter: parent.verticalCenter

            Behavior on color {
                PropertyAnimation { duration: animDuration}
            }
        }

        Image {
            id: rightIcon
            anchors.left: textContent.right
            anchors.leftMargin: rightIcon.source != "" ? Destiny.dp(8) : 0
            width: xStyle.iconRightWidth
            height: xStyle.iconRightHeight
            source: talButtonRoot.visible ? getIconRight() : ""
            anchors.verticalCenter: parent.verticalCenter
            visible: source != ""
        }
    }

    Item {
        id:loadingLayout
        visible: loading
        width: parent.width
        height: parent.height

        AnimatedImage  {
            height: parent.height - Destiny.dp(2)
            width: height
            smooth: true
            fillMode: Image.PreserveAspectFit
            anchors.centerIn: parent
            visible: parent.visible
            source: visible ? xStyle.loadingSource : ""
            playing: true
            antialiasing: true
        }

    }

    signal clicked();

    XMouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: {
            if(loading) {
                return
            }
            handler.delay(animDuration + 50, function() {
                talButtonRoot.clicked()
            })
        }
    }

    function getColor() {
        var state = mouseArea.status

        if(!enabled) {
            return xStyle.colorDisabled
        }

        if(loading) {
            return xStyle.colorLoading
        }

        if(state === mouseArea.statusHovered) {
            return xStyle.colorHovered
        } else if(state === mouseArea.statusPressed) {
            return xStyle.colorPressed
        } else {
            return xStyle.color
        }
    }

    function getTextColor() {
        var state = mouseArea.status

        if(!enabled) {
            return xStyle.textColorDisabled
        }

        if(state === mouseArea.statusHovered) {
            return xStyle.textColorHovered
        } else if(state === mouseArea.statusPressed) {
            return xStyle.textColorPressed
        } else {
            return xStyle.textColor
        }
    }

    function getBorderColor() {
        var state = mouseArea.status

        if(!enabled) {
            return xStyle.borderColorDisabled
        }

        if(loading) {
            return xStyle.borderColorLoading
        }

        if(state === mouseArea.statusHovered) {
            return xStyle.borderColorHovered
        } else if(state === mouseArea.statusPressed) {
            return xStyle.borderColorPressed
        } else {
            return xStyle.borderColor
        }
    }

    function getIconLeft() {
        if(enabled) {
            return xStyle.iconLeft;
        } else {
            return xStyle.iconLeftDisabled;
        }
    }

    function getIconRight() {
        if(enabled) {
            return xStyle.iconRight;
        } else {
            return xStyle.iconRightDisabled;
        }
    }

    XHandler { id: handler }
}

