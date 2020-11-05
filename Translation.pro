TEMPLATE = subdirs

include(config.pri)

SUBDIRS += \
    Main \
    UiBase \
    thirdparty \
    QtJsonSerializer \


Main.depends = UiBase
