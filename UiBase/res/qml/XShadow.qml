import QtQuick 2.0
import QtGraphicalEffects 1.12

import UiBase 1.0

Rectangle {

    property int shadowSamples: 24
    property int shadowVerticalOffset: 4
    property string shadowColor: "#50000000"

    radius: Destiny.dp(8)
    border.width: Destiny.dp(1)
    border.color: "#CDCDCD"

    layer.enabled: true
    layer.effect: DropShadow {
        color: shadowColor
        samples: shadowSamples
        verticalOffset: shadowVerticalOffset
    }
}
