QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    end.cpp \
    main.cpp \
    mainwindow.cpp \
    method.cpp \
    persinfo.cpp \
    result.cpp \
    welcome.cpp \
    mydialog.cpp \
    choosewindow.cpp \
    relativewindow.cpp \
    global.cpp \
    planwindow.cpp
HEADERS += \
    end.h \
    mainwindow.h \
    method.h \
    result.h \
    welcome.h \
    persinfo.h \
    mydialog.h \
    choosewindow.h \
    relativewindow.h \
    planwindow.h

FORMS += \
    end.ui \
    mainwindow.ui \
    result.ui \
    welcome.ui \
    relativewindow.ui \
    choosewindow.ui \
    relativewindow.ui \
    planwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    back.qrc \
    gif.qrc \
    logo.qrc

win32-msvc* {
        QMAKE_CXXFLAGS += /source-charset:utf-8 /execution-charset:utf-8
    }
