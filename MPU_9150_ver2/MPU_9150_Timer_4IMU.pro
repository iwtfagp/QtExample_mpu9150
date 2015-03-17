#-------------------------------------------------
#
# Project created by QtCreator 2015-01-26T12:58:53
#
#-------------------------------------------------

QT       += core gui
CONFIG += qwt

TARGET = MPU_9150_Timer_4IMU
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += C:/Qwt-6.1.2/include

Release : LIBS += $$quote(C:\Qwt-6.1.2\lib\qwt.lib)
