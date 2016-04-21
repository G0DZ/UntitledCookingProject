TEMPLATE = app

QT += qml quick widgets

CONFIG += c++11

SOURCES += main.cpp \
    model/httpconnectmanager.cpp \
    controller/coremanager.cpp \
    model/previewloadermanager.cpp

RESOURCES += qml.qrc \
    images.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
include(../core/core.pri)

DEPENDPATH += ../core
INCLUDEPATH += ../core

HEADERS += \
    model/httpconnectmanager.h \
    controller/coremanager.h \
    model/previewloadermanager.h
