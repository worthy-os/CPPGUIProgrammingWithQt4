TEMPLATE      = app
HEADERS       = projectdialog.h \
                projectlistwidget.h
SOURCES       = main.cpp \
                projectdialog.cpp \
                projectlistwidget.cpp
FORMS         = projectdialog.ui
RESOURCES     = projectchooser.qrc
QT           += qml widgets  gui xml xml
CONFIG       += uitools
