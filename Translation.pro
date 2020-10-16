TEMPLATE = subdirs

include(config.pri)

SUBDIRS += \
    Main \
#    log4qt \
#    QtJsonSerializer \
    UiBase \
    thirdparty \
#    QtRestClient \
#    QtPromise \



Main.depends = UiBase
#QtRestClient.depends = QtJsonSerializer
