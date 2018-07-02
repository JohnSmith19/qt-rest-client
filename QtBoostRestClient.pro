#-------------------------------------------------
#
# Project created by QtCreator 2018-07-02T19:48:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtBoostRestClient
TEMPLATE = app

INCLUDEPATH += /usr/include/boost

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp \
    asioclient.cpp

HEADERS += \
        widget.h \
    asioclient.h

FORMS += \
        widget.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/x86_64-linux-gnu/release/ -lboost_system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/x86_64-linux-gnu/debug/ -lboost_system
else:unix: LIBS += -L$$PWD/../../../../../../usr/lib/x86_64-linux-gnu/ -lboost_system

INCLUDEPATH += $$PWD/../../../../../../usr/lib/x86_64-linux-gnu
DEPENDPATH += $$PWD/../../../../../../usr/lib/x86_64-linux-gnu

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../usr/lib/x86_64-linux-gnu/release/libboost_system.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../usr/lib/x86_64-linux-gnu/debug/libboost_system.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../usr/lib/x86_64-linux-gnu/release/boost_system.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../usr/lib/x86_64-linux-gnu/debug/boost_system.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../../usr/lib/x86_64-linux-gnu/libboost_system.a
