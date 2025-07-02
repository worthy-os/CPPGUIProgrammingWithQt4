TEMPLATE      = app
QT           += qml widgets  gui xml # QT += script grostig
HEADERS       = diagramwindow.h \
                link.h \
                node.h \
                propertiesdialog.h
SOURCES       = diagramwindow.cpp \
                link.cpp \
                main.cpp \
                node.cpp \
                propertiesdialog.cpp
FORMS         = propertiesdialog.ui
RESOURCES     = resources.qrc
