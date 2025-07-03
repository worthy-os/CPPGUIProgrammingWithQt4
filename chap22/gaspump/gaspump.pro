TEMPLATE      = app
HEADERS       = filterdialog.h \
                pumpspreadsheet.h \
                pumpwindow.h \
                scripting.h
SOURCES       = filterdialog.cpp \
                main.cpp \
                pumpspreadsheet.cpp \
                pumpwindow.cpp \
                scripting.cpp
FORMS         = filterdialog.ui
QT           += qml widgets  gui xml xml
CONFIG       += uitools
