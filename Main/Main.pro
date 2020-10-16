QT       += core gui network
QT       += widgets quick quickwidgets qml script

TEMPLATE = app
TARGET = Translation
CONFIG += c++11

include(../config.pri)
RC_ICONS = "Translation.ico"

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DEFINES += QT_QML_DEBUG_NO_WARNING

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

include(core/core.pri)
include(baidu/baidu.pri)
include(google/google.pri)
include(youdao/youdao.pri)
include(utils/utils.pri)
include(ui/ui.pri)
include(http/http.pri)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../UiBase/release/ -lUiBase
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../UiBase/debug/ -lUiBase
else:unix: LIBS += -L$$OUT_PWD/../UiBase/ -lUiBase

INCLUDEPATH += $$PWD/../UiBase
DEPENDPATH += $$PWD/../UiBase

RESOURCES += \
    resource.qrc
