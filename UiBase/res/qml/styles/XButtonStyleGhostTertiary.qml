import QtQuick 2.0

import UiBase 1.0

import "qrc:/qml"

XButtonStyle {

    loadingSource: "qrc:/drawable/loading.gray.gif"

    color:  "#00FFFFFF"
    colorHovered: "#0AFFFFFF"
    colorPressed: "#00FFFFFF"

    textColor: "#2B2B2B"
    textColorHovered: "#2B2B2B"
    textColorPressed: "#2B2B2B"

    borderColor: "#DCDDDF"
    borderColorHovered:  "#ABABAB"
    borderColorPressed:  "#ABABAB"

    iconLeft: "qrc:/drawable/close.png"
}
