QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    database.cpp \
    findproduct.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    product.cpp \
    register.cpp \
    shoppingcart.cpp

HEADERS += \
    database.h \
    findproduct.h \
    login.h \
    mainwindow.h \
    product.h \
    register.h \
    shoppingcart.h

FORMS += \
    database.ui \
    findproduct.ui \
    login.ui \
    mainwindow.ui \
    product.ui \
    register.ui \
    shoppingcart.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
