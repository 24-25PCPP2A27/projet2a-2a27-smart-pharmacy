QT += core gui sql charts network serialport

SOURCES += \
    arduino.cpp \
    connection.cpp \
    main.cpp \
    ges_medicament.cpp \
    medicament.cpp \

HEADERS += \
    arduino.h \
    connection.h \
    ges_medicament.h \
    medicament.h \

# Paths
INCLUDEPATH += $$PWD/src
DEPENDPATH += $$PWD/src


# Deployment rules (optional)
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    ges_medicament.ui
