#-------------------------------------------------
#
# Project created by QtCreator 2014-10-16T22:19:52
#
#-------------------------------------------------

QT       += core xml

QT       -= gui

TARGET = ConvertToDba
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SUBDIRS += tests

SOURCES += main.cpp \
    readanimelist.cpp \
    writetodbaformat.cpp

HEADERS += \
    readanimelist.h \
    writetodbaformat.h
