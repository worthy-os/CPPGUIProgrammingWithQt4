TEMPLATE      = lib
CONFIG       += plugin
HEADERS       = ../textart/textartinterface.h \
                basiceffectsplugin.h
SOURCES       = basiceffectsplugin.cpp
DESTDIR       = ../textart/plugins
QT           += qml widgets  gui xml xml
CONFIG       += uitools
