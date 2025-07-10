QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    source/simulator.cpp \
    source/xmloperator.cpp \
    source/conditioner.cpp \
    source/main.cpp \
    source/mainwindow.cpp \
    source/settings.cpp

HEADERS += \
    include/conditioner.h \
    include/mainwindow.h \
    include/settings.h \
    include/simulator.h \
    include/structs.h \
    include/xmloperator.h

FORMS += \
    ui/mainwindow.ui \
    ui/settings.ui \
    ui/simulator.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
