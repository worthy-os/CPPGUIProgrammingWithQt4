TEMPLATE      = app
CONFIG       += console thread
HEADERS       = thread.h \
                threaddialog.h
SOURCES       = main.cpp \
                thread.cpp \
                threaddialog.cpp
QT           += qml widgets  gui xml xml
CONFIG       += uitools
