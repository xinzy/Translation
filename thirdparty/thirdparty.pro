TEMPLATE = subdirs
SUBDIRS =

include($$PWD/../config.pri)

PREBUILTS = \
    ssl \

QMAKE_EXTRA_TARGETS += qmake_all prebuilts $$PREBUILTS
qmake_all.depends += prebuilts
prebuilts.depends = $$PREBUILTS

ARCH=$$QT_ARCH
equals(ARCH,i386): ARCH=x86
equals(ARCH,x86_64): ARCH=x64

DOT=.

defineReplace(prebuilt) {
    name = $$1
    inc = $$2
    lib = $$3
    bin = $$4
    inc2 = $$basename(inc)
    out = $$OUT_PWD/../$${name}
    !isEmpty(inc) {
        copyinc = && $(MKDIR) $$system_path($$out/$$inc2) && $(COPY_DIR) $$system_path($$PWD/$$name/$$inc) $$system_path($$out/$$inc2)
    }
    !isEmpty(lib) {
        copylib = && $(MKDIR) $$system_path($$out/$$lib) && $(COPY_DIR) $$system_path($$PWD/$$name/$$lib/$$ARCH) $$system_path($$out/$$lib)
    }
    !isEmpty(bin) {
        copybin = && $(COPY_DIR) $$system_path($$PWD/$$name/$$bin/$$ARCH/*) $$system_path($$DESTDIR)
    }
    target = $${name}$${DOT}target = $$out
    commands = $${name}$${DOT}commands = $(MKDIR) $$system_path($$out) $$copyinc $$copylib $$copybin
    return($$target$$escape_expand(\n)$$commands)
}


eval($$prebuilt(ssl,include,,lib))
