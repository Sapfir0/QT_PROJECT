#-------------------------------------------------
#
# Project created by QtCreator 2018-05-25T18:34:04
#
#-------------------------------------------------

QT       += core gui
QT += qml
QT += qml quick widgets
 QT += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ku_ti
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
TRANSLATIONS += QtLanguage_ru.ts

CODECFORSRC     = UTF-8

SOURCES += \
        main.cpp \
    secondwindow.cpp \
    time_calculate.cpp \
    function.cpp \
    about_method.cpp \
    settings.cpp \
    QRoundProgressBar.cpp \
    mythread.cpp \
    constructor.cpp \
    popup.cpp \
    testing_window.cpp

HEADERS += \
    secondwindow.h \
    sortings.h \
    requests.h \
    time_calculate.h \
    function.h \
    calculating_time_sort.h \
    about_method.h \
    settings.h \
    QRoundProgressBar.h \
    mythread.h \
    constructor.h \
    create_file_with_levels.h \
    popup.h \
    constructor_functions.h \
    testing_window.h

FORMS += \
    secondwindow.ui \
    time_calculate.ui \
    function.ui \
    about_method.ui \
    settings.ui \
    constructor.ui \
    testing_window.ui

RESOURCES += \
    yahzwhatisit.qrc
