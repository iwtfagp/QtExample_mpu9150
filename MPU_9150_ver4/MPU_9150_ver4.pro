#-------------------------------------------------
#
# Project created by QtCreator 2015-02-02T13:41:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MPU_9150_ver4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mpu_9150.cpp

HEADERS  += mainwindow.h \
    mpu_9150.h

FORMS    += mainwindow.ui
INCLUDEPATH += $$quote(D:\LIB\Qwt-6.1.2\include)

Release : LIBS += $$quote(D:\LIB\Qwt-6.1.2\lib\qwt.lib)
