QT       += core gui network
QT       += core gui sql
QT += printsupport
 QT += charts
QT += core gui serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connection.cpp \
    email.cpp \
    fournisseur.cpp \
    gestion_fournisseur.cpp \
    main.cpp \
    pagem.cpp

HEADERS += \
    arduino.h \
    connection.h \
    email.h \
    fournisseur.h \
    gestion_fournisseur.h \
    main.h \
    pagem.h

FORMS += \
    gestion_fournisseur.ui \
    pagem.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
