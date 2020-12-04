import QtQuick 2.15
import UiBase 1.0

import "../js/XConst.js" as Const

QtObject {

    /// 主题色
    enum ThemeColor {
        Black, White
    }
    /// 大小
    enum Size {
        TitlePrimary, TitleSecondary, Content, AssistPrimary, AssistSecondary
    }
    /// 颜色等级
    enum ColorLevel {
        L100, L80, L70, L30
    }

    property var theme: XTextStyle.ThemeColor.Black
    property var size: XTextStyle.Size.TitlePrimary
    property var level: XTextStyle.ColorLevel.L100
    property bool fontBold: false

    readonly property real fontOpacity: level === XTextStyle.ColorLevel.L80 ? 0.8 : 1


    function fontFamily() {
        if (fontBold) {
            return Const.DefaultFont;
        } else {
            return Const.DefaultFont;
        }
    }

    function fontPixelSize() {
        if (size === XTextStyle.Size.TitlePrimary) {
            return Destiny.dp(24);
        } else if (size === XTextStyle.Size.TitleSecondary) {
            return Destiny.dp(18);
        } else if (size === XTextStyle.Size.Content) {
            return Destiny.dp(16);
        } else if (size === XTextStyle.Size.AssistPrimary) {
            return Destiny.dp(14);
        } else if (size === XTextStyle.Size.AssistSecondary) {
            return Destiny.dp(12);
        }
        return Destiny.dp(12);
    }

    function fontColor() {
        if (theme === XTextStyle.ThemeColor.Black) {
            if (level === XTextStyle.ColorLevel.L100) {
                return "#2B2B2B";
            } else if (level === XTextStyle.ColorLevel.L80) {
                return "#2B2B2B";
            } else if (level === XTextStyle.ColorLevel.L70) {
                return "#7E7E7E";
            } else if (level === XTextStyle.ColorLevel.L30) {
                return "#B6B6B6";
            }
        } else {
            if (level === XTextStyle.ColorLevel.L100) {
                return "#FFFFFF";
            } else if (level === XTextStyle.ColorLevel.L80) {
                return "#FFFFFF";
            } else if (level === XTextStyle.ColorLevel.L70) {
                return "#909093";
            } else if (level === XTextStyle.ColorLevel.L30) {
                return "#444E55";
            }
        }
        return "#000000";
    }
}
