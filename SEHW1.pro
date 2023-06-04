QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ./Sources/end.cpp \
    ./Sources/main.cpp \
    ./Sources/mainwindow.cpp \
    ./Sources/method.cpp \
    ./Sources/persinfo.cpp \
    ./Sources/result.cpp \
    ./Sources/welcome.cpp \
    ./Sources/mydialog.cpp \
    ./Sources/choosewindow.cpp \
    ./Sources/relativewindow.cpp \
    ./Sources/global.cpp \
    ./Sources/planwindow.cpp \
    ./Sources/askdialog.cpp
HEADERS += \
    ./Headers/end.h \
    ./Headers/mainwindow.h \
    ./Headers/method.h \
    ./Headers/result.h \
    ./Headers/welcome.h \
    ./Headers/persinfo.h \
    ./Headers/mydialog.h \
    ./Headers/choosewindow.h \
    ./Headers/relativewindow.h \
    ./Headers/planwindow.h \
    ./Headers/askdialog.h

FORMS += \
    ./Forms/end.ui \
    ./Forms/mainwindow.ui \
    ./Forms/result.ui \
    ./Forms/welcome.ui \
    ./Forms/relativewindow.ui \
    ./Forms/choosewindow.ui \
    ./Forms/relativewindow.ui \
    ./Forms/planwindow.ui

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
