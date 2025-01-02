QT       += core gui
QT += widgets
QT += network
RESOURCES += translations.qrc
TRANSLATIONS += translations/app_zh_CN.ts translations/app_en_US.ts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
RESOURCES += styles.qrc
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    translations.qrc
