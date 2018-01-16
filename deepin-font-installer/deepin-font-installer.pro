######################################################################
# Automatically generated by qmake (3.0) ?? 12? 20 11:40:37 2017
######################################################################

QT += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = deepin-font-installer

CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget glib-2.0 freetype2 fontconfig

INCLUDEPATH += $$PWD/../libdeepin-font-installer
LIBS += -L$$OUT_PWD/../libdeepin-font-installer -ldeepin-font-installer
DEFINES += QT_MESSAGELOGCONTEXT

# Input
HEADERS += homepage.h \
	   listitem.h \
	   mainwindow.h \
	   multifilepage.h \
	   singlefilepage.h \
	   utils.h \
    listwidget.h

SOURCES += homepage.cpp \
	   listitem.cpp \
	   main.cpp \
	   mainwindow.cpp \
	   multifilepage.cpp \
	   singlefilepage.cpp \
	   utils.cpp \
    listwidget.cpp

RESOURCES += deepin-font-installer.qrc

isEmpty(BINDIR):BINDIR=/usr/bin
isEmpty(APPDIR):APPDIR=/usr/share/applications
isEmpty(DSRDIR):DSRDIR=/usr/share/deepin-font-installer

target.path = $$INSTROOT$$BINDIR

desktop.path = $$INSTROOT$$APPDIR
desktop.files = $$PWD/../deepin-font-installer.desktop

policy.path = /usr/share/polkit-1/actions
policy.files = com.deepin.pkexec.font-install.policy com.deepin.pkexec.font-uninstall.policy

INSTALLS += target desktop policy
