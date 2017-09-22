TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    jacobi_cyclic.cpp \
    householder.cpp \
    jacobi_max.cpp \
    lanczos.cpp


INCLUDEPATH += /usr/local/include
LIBS += -L/usr/local/lib

SOURCES += main.cpp
LIBS += -larmadillo -llapack -lblas

HEADERS += \
    project2_header.h
