TEMPLATE      = app
QT            = core network
CONFIG       += console
CONFIG       -= app_bundle
HEADERS       = ftpget.h
SOURCES       = ftpget.cpp \
                main.cpp
QT           += qml widgets  gui xml xml
CONFIG       += uitools
