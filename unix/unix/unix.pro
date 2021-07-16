#-------------------------------------------------
#
# Project created by QtCreator 2016-06-05T23:24:19
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = unix
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    dialog_2.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    dialog_2.h

FORMS    += mainwindow.ui \
    dialog.ui \
    dialog_2.ui

CONFIG += no_keywords # Python redefines some qt keywords
INCLUDEPATH += /usr/include/python2.7
LIBS += -lpython2.7
