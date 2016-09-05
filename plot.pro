#-------------------------------------------------
#
# Project created by QtCreator 2016-09-05T09:20:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = plot
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mynetwork.cpp

HEADERS  += mainwindow.h \
    mynetwork.h

FORMS    += mainwindow.ui

QT += network
