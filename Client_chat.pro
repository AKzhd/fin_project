QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    TcpClient.cpp \
    connect.cpp \
    dialog.cpp \
    logform.cpp \
    main.cpp \
    mainwindow.cpp \
    pgsql.cpp \
    regform.cpp

HEADERS += \
    TcpClient.hpp \
    connect.h \
    dialog.h \
    logform.h \
    mainwindow.h \
    pgsql.h \
    regform.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# RESOURCES += \
#    qml.qrc

FORMS += \
    connect.ui \
    dialog.ui \
    logform.ui \
    mainwindow.ui \
    regform.ui
