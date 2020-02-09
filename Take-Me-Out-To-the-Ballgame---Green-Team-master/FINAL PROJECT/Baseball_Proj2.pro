#-------------------------------------------------
#
# Project created by QtCreator 2017-04-03T12:08:57
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Baseball_Proj2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dbmanager.cpp \
    graphs.cpp \
    GraphMST.cpp

HEADERS  += mainwindow.h \
    dbmanager.h \
    stadiumstruct.h \
    graphs.h \
    GraphMST.h

FORMS    += mainwindow.ui

DISTFILES += \
    Project2database.db \
    newFile1.txt

RESOURCES += \
    qdarkstyle/style.qrc
