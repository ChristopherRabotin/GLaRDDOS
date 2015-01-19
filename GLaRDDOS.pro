#-------------------------------------------------
#
# Project created by QtCreator 2011-08-16T21:51:03
#
#-------------------------------------------------

QT       += core \
            network \
            thread \
            gui

TARGET = GLaRDDOS
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    socketplant.cpp \
    gglarddos.cpp \
    backbone.cpp \
    hordefactory.cpp \
    hordeviairc.cpp \
    hordeviahttp.cpp \
    hordedummy.cpp \
    hordeviafile.cpp

HEADERS += \
    socketplant.h \
    backbone.h \
    gglarddos.h \
    hordefactory.h \
    hordeviairc.h \
    hordeviahttp.h \
    hordedummy.h \
    hordeviafile.h

FORMS += \
    gglarddos.ui
