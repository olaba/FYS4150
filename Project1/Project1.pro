TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /usr/local/include
LIBS += -L/usr/local/lib
LIBS += -larmadillo -llapack -lblas

SOURCES += main.cpp \
    tridiagonal.cpp \
    topliz.cpp \
    logerr.cpp \
    exact.cpp \
    LU.cpp

HEADERS += \
    project1_header.h
