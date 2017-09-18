TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    tridiagonal.cpp \
    topliz.cpp \
    logerr.cpp \
    exact.cpp \
    lud.cpp

HEADERS += \
    project1_header.h


INCLUDEPATH += LC:\Documents\armadillo-8.100.1\include
LIBS += -L/usr/local/lib
LIBS += -larmadillo -llapack -lblas
