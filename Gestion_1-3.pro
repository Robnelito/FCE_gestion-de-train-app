#-------------------------------------------------
#
# Project created by QtCreator 2020-01-06T11:59:44
#
#-------------------------------------------------

QT       += core gui
QT += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gestion_1-3
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


SOURCES += \
        main.cpp \
        gestion_de_train.cpp \
    dialog1.cpp \
    dialog.cpp \
    fonction_pour_train.cpp \
    showtrain.cpp \
    fonction_pour_place.cpp \
    dialog_place.cpp \
    fonction_pour_itineraire.cpp \
    itineraire.cpp \
    fonction_pour_reservation.cpp \
    reservation.cpp \
    fonction_pour_recette.cpp \
    apropos.cpp \
    destination.cpp

HEADERS += \
        gestion_de_train.h \
    train.h \
    dialog1.h \
    dialog.h \
    dialog_place.h \
    itineraire.h \
    reservation.h \
    apropos.h \
    destination.h

FORMS += \
        gestion_de_train.ui \
    dialog1.ui \
    dialog.ui \
    dialog_place.ui \
    itineraire.ui \
    reservation.ui \
    apropos.ui \
    destination.ui

RESOURCES += \
    res.qrc

RC_FILE = icone.rc

