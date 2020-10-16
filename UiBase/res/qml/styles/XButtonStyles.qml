import QtQuick 2.0

import UiBase 1.0
import "qrc:/qml"

QtObject {

    property int largeWidth: Destiny.dp(256)
    property int largeHeight: Destiny.dp(64)
    property int largeFontPixelSize: Destiny.dp(18)

    property int mediumWidth: Destiny.dp(180)
    property int mediumHeight: Destiny.dp(48)
    property int mediumFontPixelSize: Destiny.dp(16)

    property int smallWidth: Destiny.dp(84)
    property int smallHeight: Destiny.dp(40)
    property int smallFontPixelSize: Destiny.dp(16)

    property XButtonStyle primaryLarge: XButtonStyle {
        width: largeWidth
        height: largeHeight
        fontPixelSize: largeFontPixelSize

        loadingSource: "qrc:/drawable/loading.white.gif"

        color:  "#008FFF"
        colorHovered: "#1799FF"
        colorPressed: "#0065B4"

        textColor: "#FFFFFF"
        textColorHovered: "#FFFFFF"
        textColorPressed: "#FFFFFF"

        borderColor: "#00000000"
        borderColorHovered:  "#00000000"
        borderColorPressed:  "#00000000"

    }


    property XButtonStyle primaryMedium: XButtonStyle {
        width: mediumWidth
        height: mediumHeight
        fontPixelSize: mediumFontPixelSize

        loadingSource: "qrc:/drawable/loading.white.gif"

        color:  "#008FFF"
        colorHovered: "#1799FF"
        colorPressed: "#0065B4"

        textColor: "#FFFFFF"
        textColorHovered: "#FFFFFF"
        textColorPressed: "#FFFFFF"

        borderColor: "#00000000"
        borderColorHovered:  "#00000000"
        borderColorPressed:  "#00000000"
    }


    property XButtonStyle primarySmall: XButtonStyle {

        width: smallWidth
        height: smallHeight
        fontPixelSize: smallFontPixelSize

        loadingSource: "qrc:/drawable/loading.white.gif"

        color:  "#008FFF"
        colorHovered: "#1799FF"
        colorPressed: "#0065B4"

        textColor: "#FFFFFF"
        textColorHovered: "#FFFFFF"
        textColorPressed: "#FFFFFF"

        borderColor: "#00000000"
        borderColorHovered:  "#00000000"
        borderColorPressed:  "#00000000"
    }


    property XButtonStyle secondaryLarge: XButtonStyle {
        width: largeWidth
        height: largeHeight
        fontPixelSize: largeFontPixelSize


        loadingSource: "qrc:/drawable/loading.gray.gif"



        color:  "#E9EAEE"
        colorHovered: "#DFDFDF"
        colorPressed: "#C2C2C2"

        textColor: "#2B2B2B"
        textColorHovered: "#2B2B2B"
        textColorPressed: "#2B2B2B"

        borderColor: "#00000000"
        borderColorHovered:  "#00000000"
        borderColorPressed:  "#00000000"


    }

    property XButtonStyle secondaryMedium: XButtonStyle {
        width: mediumWidth
        height: mediumHeight
        fontPixelSize: mediumFontPixelSize

        loadingSource: "qrc:/drawable/loading.gray.gif"


        color:  "#E9EAEE"
        colorHovered: "#DFDFDF"
        colorPressed: "#C2C2C2"

        textColor: "#2B2B2B"
        textColorHovered: "#2B2B2B"
        textColorPressed: "#2B2B2B"

        borderColor: "#00000000"
        borderColorHovered:  "#00000000"
        borderColorPressed:  "#00000000"

    }


    property XButtonStyle secondarySmall: XButtonStyle {

        width: smallWidth
        height: smallHeight
        fontPixelSize: smallFontPixelSize

        loadingSource: "qrc:/drawable/loading.gray.gif"


        color:  "#E9EAEE"
        colorHovered: "#DFDFDF"
        colorPressed: "#C2C2C2"

        textColor: "#2B2B2B"
        textColorHovered: "#2B2B2B"
        textColorPressed: "#2B2B2B"

        borderColor: "#00000000"
        borderColorHovered:  "#00000000"
        borderColorPressed:  "#00000000"

    }

    property XButtonStyle secondaryGoastLarge: XButtonStyle {
        width: largeWidth
        height: largeHeight
        fontPixelSize: largeFontPixelSize

        loadingSource: "qrc:/drawable/loading.gray.gif"


        color:  "#00000000"
        colorHovered: "#444E55"
        colorPressed: "#31393E"

        textColor: "#2B2B2B"
        textColorHovered: "#FFFFFF"
        textColorPressed: "#FFFFFF"

        borderColor: "#444E55"
        borderColorHovered:  "#00444E55"
        borderColorPressed:  "#00444E55"

    }


    property XButtonStyle secondaryGoastMedium: XButtonStyle {
        width: mediumWidth
        height: mediumHeight
        fontPixelSize: mediumFontPixelSize

        loadingSource: "qrc:/drawable/loading.gray.gif"


        color:  "#00000000"
        colorHovered: "#444E55"
        colorPressed: "#31393E"

        textColor: "#2B2B2B"
        textColorHovered: "#FFFFFF"
        textColorPressed: "#FFFFFF"

        borderColor: "#444E55"
        borderColorHovered:  "#00000000"
        borderColorPressed:  "#00000000"

    }


    property XButtonStyle secondaryGoastSmall: XButtonStyle {

        width: smallWidth
        height: smallHeight
        fontPixelSize: smallFontPixelSize

        loadingSource: "qrc:/drawable/loading.gray.gif"


        color:  "#00000000"
        colorHovered: "#444E55"
        colorPressed: "#31393E"

        textColor: "#2B2B2B"
        textColorHovered: "#FFFFFF"
        textColorPressed: "#FFFFFF"

        borderColor: "#444E55"
        borderColorHovered:  "#00000000"
        borderColorPressed:  "#00000000"
    }


    property XButtonStyle primaryGoastLarge: XButtonStyle {
        width: largeWidth
        height: largeHeight
        fontPixelSize: largeFontPixelSize

        loadingSource: "qrc:/drawable/loading.white.gif"


        color:  "#00FFFFFF"
        colorHovered: "#15FFFFFF"
        colorPressed: "#31FFFFFF"

        textColor: "#FFFFFF"
        textColorHovered: "#FFFFFF"
        textColorPressed: "#FFFFFF"

        borderColor: "#FFFFFFFF"
        borderColorHovered:  "#FFFFFFFF"
        borderColorPressed:  "#FFFFFFFF"

    }


    property XButtonStyle primaryGoastMedium: XButtonStyle {
        width: mediumWidth
        height: mediumHeight
        fontPixelSize: mediumFontPixelSize

        loadingSource: "qrc:/drawable/loading.white.gif"


        color:  "#00FFFFFF"
        colorHovered: "#15FFFFFF"
        colorPressed: "#31FFFFFF"

        textColor: "#FFFFFF"
        textColorHovered: "#FFFFFF"
        textColorPressed: "#FFFFFF"

        borderColor: "#FFFFFFFF"
        borderColorHovered:  "#FFFFFFFF"
        borderColorPressed:  "#FFFFFFFF"

    }


    property XButtonStyle primaryGoastSmall: XButtonStyle {

        width: smallWidth
        height: smallHeight
        fontPixelSize: smallFontPixelSize

        loadingSource: "qrc:/drawable/loading.white.gif"


        color:  "#00FFFFFF"
        colorHovered: "#15FFFFFF"
        colorPressed: "#31FFFFFF"

        textColor: "#FFFFFF"
        textColorHovered: "#FFFFFF"
        textColorPressed: "#FFFFFF"

        borderColor: "#FFFFFFFF"
        borderColorHovered:  "#FFFFFFFF"
        borderColorPressed:  "#FFFFFFFF"

    }



    property XButtonStyle tertiaryLarge: XButtonStyle {
        width: largeWidth
        height: largeHeight
        fontPixelSize: largeFontPixelSize

        loadingSource: "qrc:/drawable/loading.white.gif"

        color:  "#31F5F7FB"
        colorHovered: "#79FFFFFF"
        colorPressed: "#79EFF0F3"

        textColor: "#2B2B2B"
        textColorHovered: "#2B2B2B"
        textColorPressed: "#2B2B2B"

        borderColor: "#00000000"
        borderColorHovered:  "#00000000"
        borderColorPressed:  "#00000000"

    }


    property XButtonStyle tertiaryMedium: XButtonStyle {
        width: mediumWidth
        height: mediumHeight
        fontPixelSize: mediumFontPixelSize

        loadingSource: "qrc:/drawable/loading.white.gif"

        color:  "#31F5F7FB"
        colorHovered: "#79FFFFFF"
        colorPressed: "#79EFF0F3"

        textColor: "#2B2B2B"
        textColorHovered: "#2B2B2B"
        textColorPressed: "#2B2B2B"

        borderColor: "#00000000"
        borderColorHovered:  "#00000000"
        borderColorPressed:  "#00000000"

    }


    property XButtonStyle tertiarySmall: XButtonStyle {

        width: smallWidth
        height: smallHeight
        fontPixelSize: smallFontPixelSize


        loadingSource: "qrc:/drawable/loading.white.gif"


        color:  "#31F5F7FB"
        colorHovered: "#79FFFFFF"
        colorPressed: "#79EFF0F3"

        textColor: "#2B2B2B"
        textColorHovered: "#2B2B2B"
        textColorPressed: "#2B2B2B"

        borderColor: "#00000000"
        borderColorHovered:  "#00000000"
        borderColorPressed:  "#00000000"

    }



    property XButtonStyle successLarge: XButtonStyle {
        width: largeWidth
        height: largeHeight
        fontPixelSize: largeFontPixelSize

        loadingSource: "qrc:/drawable/loading.white.gif"


        color:  "#07AA6E"
        colorHovered: "#11C381"
        colorPressed: "#04774D"

        textColor: "#FFFFFF"
        textColorHovered: "#FFFFFF"
        textColorPressed: "#FFFFFF"

        borderColor: "#00000000"
        borderColorHovered:  "#00000000"
        borderColorPressed:  "#00000000"

    }


    property XButtonStyle successMedium: XButtonStyle {
        width: mediumWidth
        height: mediumHeight
        fontPixelSize: mediumFontPixelSize

        loadingSource: "qrc:/drawable/loading.white.gif"


        color:  "#07AA6E"
        colorHovered: "#11C381"
        colorPressed: "#04774D"

        textColor: "#FFFFFF"
        textColorHovered: "#FFFFFF"
        textColorPressed: "#FFFFFF"

        borderColor: "#00000000"
        borderColorHovered:  "#00000000"
        borderColorPressed:  "#00000000"

    }


    property XButtonStyle successSmall: XButtonStyle {

        width: smallWidth
        height: smallHeight
        fontPixelSize: smallFontPixelSize

        loadingSource: "qrc:/drawable/loading.white.gif"


        color:  "#07AA6E"
        colorHovered: "#11C381"
        colorPressed: "#04774D"

        textColor: "#FFFFFF"
        textColorHovered: "#FFFFFF"
        textColorPressed: "#FFFFFF"

        borderColor: "#00000000"
        borderColorHovered:  "#00000000"
        borderColorPressed:  "#00000000"
    }



    property XButtonStyle errorLarge: XButtonStyle {
        width: largeWidth
        height: largeHeight
        fontPixelSize: largeFontPixelSize

        loadingSource: "qrc:/drawable/loading.white.gif"

        color:  "#FF4D5B"
        colorHovered: "#FF626E"
        colorPressed: "#B2353F"

        textColor: "#FFFFFF"
        textColorHovered: "#FFFFFF"
        textColorPressed: "#FFFFFF"

        borderColor: "#00000000"
        borderColorHovered:  "#00000000"
        borderColorPressed:  "#00000000"

    }


    property XButtonStyle errorMedium: XButtonStyle {
        width: mediumWidth
        height: mediumHeight
        fontPixelSize: mediumFontPixelSize

        loadingSource: "qrc:/drawable/loading.white.gif"


        color:  "#FF4D5B"
        colorHovered: "#FF626E"
        colorPressed: "#B2353F"

        textColor: "#FFFFFF"
        textColorHovered: "#FFFFFF"
        textColorPressed: "#FFFFFF"

        borderColor: "#00000000"
        borderColorHovered:  "#00000000"
        borderColorPressed:  "#00000000"

    }


    property XButtonStyle errorSmall: XButtonStyle {

        width: smallWidth
        height: smallHeight
        fontPixelSize: smallFontPixelSize

        loadingSource: "qrc:/drawable/loading.white.gif"


        color:  "#FF4D5B"
        colorHovered: "#FF626E"
        colorPressed: "#B2353F"

        textColor: "#FFFFFF"
        textColorHovered: "#FFFFFF"
        textColorPressed: "#FFFFFF"

        borderColor: "#00000000"
        borderColorHovered:  "#00000000"
        borderColorPressed:  "#00000000"
    }




    property XButtonStyle warningLarge: XButtonStyle {
        width: largeWidth
        height: largeHeight
        fontPixelSize: largeFontPixelSize

        loadingSource: "qrc:/drawable/loading.white.gif"


        color:  "#FE9400"
        colorHovered: "#FFB041"
        colorPressed: "#CE9A0A"

        textColor: "#FFFFFF"
        textColorHovered: "#FFFFFF"
        textColorPressed: "#FFFFFF"

        borderColor: "#00000000"
        borderColorHovered:  "#00000000"
        borderColorPressed:  "#00000000"

    }


    property XButtonStyle warningMedium: XButtonStyle {
        width: mediumWidth
        height: mediumHeight
        fontPixelSize: mediumFontPixelSize

        loadingSource: "qrc:/drawable/loading.white.gif"

        color:  "#FE9400"
        colorHovered: "#FFB041"
        colorPressed: "#CE9A0A"

        textColor: "#FFFFFF"
        textColorHovered: "#FFFFFF"
        textColorPressed: "#FFFFFF"

        borderColor: "#00000000"
        borderColorHovered:  "#00000000"
        borderColorPressed:  "#00000000"

    }


    property XButtonStyle warningSmall: XButtonStyle {

        width: smallWidth
        height: smallHeight
        fontPixelSize: smallFontPixelSize

        loadingSource: "qrc:/drawable/loading.white.gif"


        color:  "#FE9400"
        colorHovered: "#FFB041"
        colorPressed: "#CE9A0A"

        textColor: "#FFFFFF"
        textColorHovered: "#FFFFFF"
        textColorPressed: "#FFFFFF"

        borderColor: "#00000000"
        borderColorHovered:  "#00000000"
        borderColorPressed:  "#00000000"
    }


    property XButtonStyle tertiaryGoastLarge: XButtonStyle {
        width: largeWidth
        height: largeHeight
        fontPixelSize: largeFontPixelSize

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


    property XButtonStyle tertiaryGoastMedium: XButtonStyle {
        width: mediumWidth
        height: mediumHeight
        fontPixelSize: mediumFontPixelSize

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


    property XButtonStyle tertiaryGoastSmall: XButtonStyle {

        width: smallWidth
        height: smallHeight
        fontPixelSize: smallFontPixelSize

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



    property XButtonStyle demoIconButtonRightLarge: XButtonStyle {
        width: largeWidth
        height: largeHeight
        fontPixelSize: largeFontPixelSize

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

        iconRight: "qrc:/drawable/close.png"
    }


    property XButtonStyle demoIconButtonRightMedium: XButtonStyle {
        width: mediumWidth
        height: mediumHeight
        fontPixelSize: mediumFontPixelSize

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

        iconRight: "qrc:/drawable/close.png"

    }


    property XButtonStyle demoIconButtonRightSmall: XButtonStyle {

        width: smallWidth
        height: smallHeight
        fontPixelSize: smallFontPixelSize

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

        iconRight: "qrc:/drawable/close.png"

    }



}
