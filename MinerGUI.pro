#-------------------------------------------------
#
# Project created by QtCreator 2018-08-13T18:52:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MinerGUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog_donate.cpp \
    dialog_cpuminerusage.cpp \
    dialog_cudaminerusage.cpp \
    dialog_extraconfig.cpp \
    dialog_log.cpp \
    dialog_help.cpp

HEADERS  += mainwindow.h \
    dialog_log.h \
    dialog_donate.h \
    dialog_cpuminerusage.h \
    dialog_cudaminerusage.h \
    dialog_extraconfig.h \
    dialog_help.h

FORMS    += mainwindow.ui \
    dialog_log.ui \
    dialog_donate.ui \
    dialog_cpuminerusage.ui \
    dialog_cudaminerusage.ui \
    dialog_extraconfig.ui \
    dialog_help.ui
