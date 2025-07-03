TEMPLATE      = app
QT            = core network
CONFIG       += console
CONFIG       -= app_bundle
HEADERS       = httpget.h
SOURCES       = httpget.cpp \
                main.cpp
QT           += qml widgets  gui xml xml
CONFIG       += uitools
