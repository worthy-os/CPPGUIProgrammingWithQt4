TEMPLATE      = app
QT            = core network
CONFIG       += console
CONFIG       -= app_bundle
HEADERS       = spider.h
SOURCES       = main.cpp \
                spider.cpp
QT           += qml widgets  gui xml xml
CONFIG       += uitools
