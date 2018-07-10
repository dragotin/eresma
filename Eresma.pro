#-------------------------------------------------
#
# Project created by QtCreator 2018-07-08T16:13:30
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = Eresma
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        eresmamainwindow.cpp \
    eresmacanvas.cpp \
    regiontree.cpp \
    iteminfo.cpp \
    ordereditor.cpp \
    hexmap.cpp \
    regiongraphicsitem.cpp \
    region.cpp

HEADERS += \
        eresmamainwindow.h \
    eresmacanvas.h \
    regiontree.h \
    iteminfo.h \
    ordereditor.h \
    hexmap.h \
    regiongraphicsitem.h \
    region.h

FORMS += \
        eresmamainwindow.ui
