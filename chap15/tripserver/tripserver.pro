TEMPLATE      = app
QT           += network
HEADERS       = clientsocket.h \
                tripserver.h
SOURCES       = clientsocket.cpp \
                main.cpp \
                tripserver.cpp
QT           += qml widgets  gui xml xml
CONFIG       += uitools
