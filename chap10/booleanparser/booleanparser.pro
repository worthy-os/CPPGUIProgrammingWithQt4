TEMPLATE      = app
HEADERS       = booleanmodel.h \
                booleanparser.h \
                booleanwindow.h \
                node.h
SOURCES       = booleanmodel.cpp \
                booleanparser.cpp \
                booleanwindow.cpp \
                main.cpp \
                node.cpp
QT           += qml widgets  gui xml xml
CONFIG       += uitools
