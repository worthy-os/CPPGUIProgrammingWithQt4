TEMPLATE      = app
HEADERS       = imagewindow.h \
                transactionthread.h
SOURCES       = imagewindow.cpp \
                main.cpp \
                transactionthread.cpp
FORMS         = resizedialog.ui
QT           += qml widgets  gui xml xml
CONFIG       += uitools
