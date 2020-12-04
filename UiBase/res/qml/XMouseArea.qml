import QtQuick 2.15

MouseArea {

    readonly property int statusDefault: 0
    readonly property int statusHovered: 1
    readonly property int statusPressed: 2

    property int status: statusDefault

    hoverEnabled: true

    onPressed: {
        status = statusPressed
    }

    onCanceled: {
        status = statusDefault
    }

    onReleased: {
        status = statusDefault
    }

    onEntered: {
        status = statusHovered
    }

    onExited: {
        status = statusDefault
    }

    function isHovered() {
        return status === statusHovered
    }

    function isPressed() {
        return status === statusPressed
    }
}
