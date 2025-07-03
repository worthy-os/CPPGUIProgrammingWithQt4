TEMPLATE      = lib
CONFIG       += plugin
HEADERS       = cursorhandler.h \
                cursorplugin.h
SOURCES       = cursorhandler.cpp \
                cursorplugin.cpp
DESTDIR       = $$[QT_INSTALL_PLUGINS]/imageformats
QT           += qml widgets  gui xml xml
CONFIG       += uitools
