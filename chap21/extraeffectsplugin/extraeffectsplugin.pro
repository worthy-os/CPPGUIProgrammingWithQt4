TEMPLATE      = lib
CONFIG       += plugin
HEADERS       = ../textart/textartinterface.h \
                extraeffectsplugin.h
SOURCES       = extraeffectsplugin.cpp
DESTDIR       = ../textart/plugins
QT           += qml widgets  gui xml xml
CONFIG       += uitools
