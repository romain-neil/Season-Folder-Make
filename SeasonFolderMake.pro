QT += widgets gui network

DEFINES += QT_DEPRECATED_WARNINGS

TRANSLATIONS += $$PWD/translations/sfm_fr.ts \
    $$PWD/translations/sfm_es.ts

CONFIG += c++17

SOURCES += \
        aboutdialog.cpp \
        core.cpp \
        foldercreatethread.cpp \
        main.cpp \
        fenprincipale.cpp \
        verifyupdatethread.cpp

HEADERS += \
        aboutdialog.h \
        core.h \
        fenprincipale.h \
        foldercreatethread.h \
        verifyupdatethread.h

RESOURCES += \
    rsc.qrc
