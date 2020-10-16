import QtQuick 2.15
import QtQuick.Controls 2.15

import UiBase 1.0
import "qrc:/qml"
import "qrc:/qml/styles"
import "qrc:/js/XFunctions.js" as Functions

Rectangle {
    color: "white"

    property var selectingLangButton

    Rectangle {
        id: divider
        width: parent.width
        height: Destiny.dp(1)

        color: "#E2E3E4"
    }

    Item {
        id: languageSelectItem
        width: parent.width
        height: Destiny.dp(48)

        anchors.top: parent.top
        anchors.topMargin: Destiny.dp(12)

        XImageButton {
            id: exchangeItem
            width: Destiny.dp(48)
            height: Destiny.dp(48)
            anchors.horizontalCenter: parent.horizontalCenter
            radius: Destiny.dp(8)
            imageWidth: Destiny.dp(24)
            imageHeight: Destiny.dp(24)
            imageResource: "qrc:/drawable/exchange.png"
        }

        LangTabLayout {
            id: fromLang
            height: parent.height
            anchors.left: parent.left
            anchors.leftMargin: Destiny.dp(48)

            selectedIndex: viewModel.sourceCommonLangIndex
            model: viewModel.sourceCommonLang

            onSelectedIndexChanged: {
                console.log("onSelectedIndexChanged: ", selectedIndex)
                doTranslate()
            }

            onItemTabClick: {
                viewModel.setSourceCommonLangIndex(index)
                if (selectLangPopup.visible) {
                    selectLangPopup.visible = false
                }
            }
        }

        XImageButton {
            id: fromLangSelect
            width: Destiny.dp(48)
            height: Destiny.dp(48)
            anchors.left: fromLang.right
            anchors.leftMargin: Destiny.dp(24)
            radius: Destiny.dp(8)

            imageWidth: Destiny.dp(24)
            imageHeight: Destiny.dp(24)
            imageResource: "qrc:/drawable/arrow_down.png"

            onClicked: {
                showLangPopup(true)
            }
        }

        LangTabLayout {
            id: toLang
            height: parent.height
            anchors.left: exchangeItem.right
            anchors.leftMargin: Destiny.dp(48)

            selectedIndex: viewModel.targetCommonLangIndex
            model: viewModel.targetCommonLang

            onSelectedIndexChanged: {
                doTranslate()
            }

            onItemTabClick: {
                viewModel.setTargetCommonLangIndex(index)
                if (selectLangPopup.visible) {
                    selectLangPopup.visible = false
                }
            }
        }

        XImageButton {
            id: toLangSelect
            width: Destiny.dp(48)
            height: Destiny.dp(48)
            anchors.left: toLang.right
            anchors.leftMargin: Destiny.dp(24)
            radius: Destiny.dp(8)

            imageWidth: Destiny.dp(24)
            imageHeight: Destiny.dp(24)
            imageResource: "qrc:/drawable/arrow_down.png"

            onClicked: {
                showLangPopup(false)
            }
        }
    }

    Item {
        id: translationContainer
        width: parent.width
        anchors.top: languageSelectItem.bottom
        anchors.bottom: parent.bottom
        anchors.bottomMargin: Destiny.dp(8)

        XImageButton {
            id: translationBtn
            width: Destiny.dp(48)
            height: Destiny.dp(48)
            anchors.centerIn: parent
            radius: Destiny.dp(8)

            imageWidth: Destiny.dp(24)
            imageHeight: Destiny.dp(24)
            imageResource: "qrc:/drawable/translate.png"

            onClicked: {
                doTranslate()
            }
        }

        Rectangle {
            id: sourceLangContainer
            anchors.left: parent.left
            anchors.leftMargin: Destiny.dp(12)
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.right: translationBtn.left
            anchors.rightMargin: Destiny.dp(0)

            radius: Destiny.dp(8)
            border.width: Destiny.dp(1)
            border.color: "#E2E3E4"

            ScrollView {
                anchors.fill: parent

                TextArea {
                    id: sourceLangTextArea
                    anchors.margins: Destiny.dp(8)
                    clip: true
                    font.family: "Microsoft YaHei"
                    selectByMouse: true
                    selectionColor: "#AFE1F7"
                    wrapMode: TextEdit.Wrap
                    mouseSelectionMode: TextEdit.SelectCharacters
                    font.pixelSize: Destiny.sp(16)
                    color: "#2B2B2B"

                    onTextChanged: {
                        handler.delay(1000, function() {
                            viewModel.translate(text)
                        })
                    }
                }
            }
        }

        Rectangle {
            id: targetLangContainer
            anchors.left: translationBtn.right
            anchors.leftMargin: Destiny.dp(0)
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.rightMargin: Destiny.dp(12)

            radius: Destiny.dp(8)
            border.width: Destiny.dp(1)
            border.color: "#E2E3E4"

            ScrollView {
                anchors.fill: parent

                TextArea {
                    id: targetLangTextArea
                    anchors.margins: Destiny.dp(8)
                    focus: false
                    clip: true
                    text: viewModel.displayResult
                    font.family: "Microsoft YaHei"
                    readOnly: true
                    placeholderText: "翻译"
                    selectionColor: "#AFE1F7"
                    selectByMouse: true
                    wrapMode: TextEdit.Wrap
                    mouseSelectionMode: TextEdit.SelectCharacters
                    font.pixelSize: Destiny.sp(16)
                    color: "#2B2B2B"
                }
            }
        }
    }

    XShadow {
        id: selectLangPopup
        height: Destiny.dp(480)
        anchors.top: translationContainer.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.leftMargin: Destiny.dp(12)
        anchors.rightMargin: Destiny.dp(12)
        visible: false

        onVisibleChanged: {
            if (!visible && selectingLangButton) {
                selectingLangButton.imageRotation = 0
            }
        }

        GridView {
            id: langGridView

            anchors.left: parent.left
            anchors.leftMargin: Destiny.dp(12)
            anchors.right: parent.right
            anchors.rightMargin: Destiny.dp(12)
            anchors.top: parent.top
            anchors.topMargin: Destiny.dp(12)
            anchors.bottom: parent.bottom
            anchors.bottomMargin: Destiny.dp(12)

            cellHeight: Destiny.dp(36)
            cellWidth: langGridItemWidth()

            delegate: Item {
                id: itemView
                width: langGridView.cellWidth
                height: langGridView.cellHeight

                Rectangle {
                    id: itemContent
                    anchors.left: parent.left
                    anchors.leftMargin: Destiny.dp(8)
                    anchors.right: parent.right
                    anchors.rightMargin: Destiny.dp(8)
                    width: parent.width - anchors.leftMargin - anchors.rightMargin
                    height: parent.height

                    border.width: itemMouseArea.isPressed() ? Destiny.dp(1) : 0
                    border.color: "#BBBBBB"
                    color: {
                        if (modelData.checked) return "#E8F0FE"
                        if (itemMouseArea.isHovered()) return "#F4F4F4"
                        else if (itemMouseArea.isPressed()) return "#E2E3E4"
                        return "transparent"
                    }

                    Image {
                        id: itemSelectedImg
                        width: Destiny.dp(16)
                        height: Destiny.dp(16)

                        anchors.left: parent.left
                        anchors.leftMargin: Destiny.dp(16)
                        anchors.verticalCenter: parent.verticalCenter
                        source: "qrc:/drawable/lang_checked.png"

                        visible: modelData.checked
                    }

                    XText {
                        id: itemText
                        anchors.left: itemSelectedImg.right
                        anchors.leftMargin: Destiny.dp(12)
                        anchors.verticalCenter: parent.verticalCenter
                        xStyle: XTextStyleBlack { size: XTextStyle.Size.AssistPrimary }
                        text: modelData.text
                    }
                }

                XMouseArea {
                    id: itemMouseArea
                    anchors.fill: parent
                    onClicked: {
                        modelData.trigger()
                        selectLangPopup.visible = false
                        console.log(modelData.text, modelData.iconText, modelData.checked)
                    }
                }
            }
        }
    }

    Item {
        id: settingItem
        width: Destiny.dp(56)
        height: Destiny.dp(24)
        anchors.top: parent.top
        anchors.topMargin: Destiny.dp(12)
        anchors.right: parent.right
        anchors.rightMargin: Destiny.dp(12)

        XImageButton {
            id: settingBtn
            width: Destiny.dp(24)
            height: Destiny.dp(24)
            anchors.right: parent.right
            radius: Destiny.dp(4)

            imageWidth: Destiny.dp(16)
            imageHeight: Destiny.dp(16)
            imageResource: "qrc:/drawable/settings.png"

            onClicked: {
                viewModel.startSetting()
            }
        }

        XImageButton {
            id: engineBtn
            width: Destiny.dp(24)
            height: Destiny.dp(24)
            anchors.right: settingBtn.left
            anchors.rightMargin: Destiny.dp(8)
            radius: Destiny.dp(4)

            imageWidth: Destiny.dp(16)
            imageHeight: Destiny.dp(16)
            imageResource: viewModel.currentEngine.icon

            onClicked: {
                engineSelectionPopup.open()
            }
        }
    }

    Popup {
        id: engineSelectionPopup
        width: Destiny.dp(160)
        height: Destiny.dp(144)
        x: parent.width - Destiny.dp(24) - width
        y: Destiny.dp(40)
        leftInset: Destiny.dp(10)
        rightInset: Destiny.dp(10)
        background: XShadow {}

        ListView {
            id: engineSelectionListView
            width: parent.width
            height: parent.height
            boundsBehavior: Flickable.StopAtBounds

            model: viewModel.translationEngines
            delegate: Rectangle {
                width: parent.width
                height: Destiny.dp(36)
                color: {
                    if (itemSelectionMouseArea.isHovered()) return "#F4F4F4"
                    else if (itemSelectionMouseArea.isPressed()) return "#E2E3E4"
                    return "transparent"
                }

                Image {
                    id: itemSelectionImg
                    width: Destiny.dp(16)
                    height: Destiny.dp(16)
                    anchors.left: parent.left
                    anchors.leftMargin: Destiny.dp(8)
                    anchors.verticalCenter: parent.verticalCenter
                    source: "qrc:/drawable/lang_checked.png"
                    visible: modelData.engine === viewModel.currentEngine.engine
                }

                Image {
                    id: itemSelectionIconImg
                    width: Destiny.dp(20)
                    height: Destiny.dp(20)
                    anchors.left: itemSelectionImg.right
                    anchors.leftMargin: Destiny.dp(12)
                    anchors.verticalCenter: parent.verticalCenter
                    source: modelData.icon
                }

                XText {
                    id: itemSelectionText
                    anchors.left: itemSelectionIconImg.right
                    anchors.leftMargin: Destiny.dp(6)
                    anchors.verticalCenter: parent.verticalCenter
                    xStyle: XTextStyleBlack { size: XTextStyle.Size.AssistPrimary }
                    color: itemSelectionImg.visible ? "#4285F4" : "#2B2B2B"
                    text: modelData.name
                }

                XMouseArea {
                    id: itemSelectionMouseArea
                    anchors.fill: parent
                    onClicked: {
                        engineSelectionPopup.close()
                        viewModel.changeEngine(modelData)
                    }
                }
            }
        }
    }

    XHandler {
        id: handler
    }

    function showLangPopup(isSource) {
        var isVisible = selectLangPopup.visible
        selectLangPopup.visible = !isVisible

        selectingLangButton = isSource ? fromLangSelect : toLangSelect
        selectingLangButton.imageRotation = isVisible ? 0 : 180

        if (isSource) {
            langGridView.model = viewModel.sourceSelectLangs
        } else {
            langGridView.model = viewModel.targetSelectLangs
        }
    }

    function langGridItemWidth() {
        var width = langGridView.width
        var minWidth = Destiny.dp(240)

        if (width < 1000) return width / 3
        else if (width < 1280) return width / 4
        else if (width < 1600) return width / 5
        return width / 6
    }

    function doTranslate() {
        viewModel.translate(sourceLangTextArea.text)
    }
}
