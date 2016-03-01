#-------------------------------------------------
#
# Project created by QtCreator 2016-03-01T10:50:40
#
#-------------------------------------------------

VERSION_MAJOR = 0
VERSION_MINOR = 1
VERSION_BUILD = 1

# The application version
VERSION = 0.4.0.1
QMAKE_TARGET_COMPANY = company
QMAKE_TARGET_PRODUCT = product
QMAKE_TARGET_DESCRIPTION = description
QMAKE_TARGET_COPYRIGHT = copyright

# Define the preprocessor macro to get the application version in our application.
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BesetzungsrechnerQt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    general.h

FORMS    += mainwindow.ui
