#-------------------------------------------------
#
# Project created by QtCreator 2015-06-25T16:27:58
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QMediaPlayer
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    getfile.cpp

HEADERS  += dialog.h \
    getfile.h

FORMS    += dialog.ui \
    getfile.ui
