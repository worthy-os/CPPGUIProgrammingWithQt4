TEMPLATE      = app
HEADERS       = editor.h \
                mainwindow.h
SOURCES       = editor.cpp \
                main.cpp \
                mainwindow.cpp
RESOURCES     = mdieditor.qrc
QT           += qml widgets  gui xml xml
CONFIG       += uitools
