TEMPLATE      = lib
CONFIG       += designer plugin release
HEADERS       = ../iconeditor/iconeditor.h \
                iconeditorplugin.h
SOURCES       = ../iconeditor/iconeditor.cpp \
                iconeditorplugin.cpp
RESOURCES     = iconeditorplugin.qrc
DESTDIR       = $$[QT_INSTALL_PLUGINS]/designer
QT           += qml widgets  gui xml xml
CONFIG       += uitools
