#-------------------------------------------------
#
# Project created by QtCreator 2016-02-23T15:42:55
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = core
TEMPLATE = app

CONFIG += c++11

# Default rules for deployment.
include(core.pri)
FORMS    += mainwindow.ui
SOURCES += main.cpp \
	    mainwindow.cpp
HEADERS  += mainwindow.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libs/QGumboParser/release/ -lQGumboParser
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libs/QGumboParser/debug/ -lQGumboParser
else:unix: LIBS += -L$$OUT_PWD/../libs/QGumboParser/ -lQGumboParser

INCLUDEPATH += $$PWD/../libs/QGumboParser
DEPENDPATH += $$PWD/../libs/QGumboParser

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/QGumboParser/release/libQGumboParser.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/QGumboParser/debug/libQGumboParser.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/QGumboParser/release/QGumboParser.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libs/QGumboParser/debug/QGumboParser.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../libs/QGumboParser/libQGumboParser.a
