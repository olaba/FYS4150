TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    tridiagonal.cpp \
    topliz.cpp \
    logerr.cpp \
    lu.cpp \
    exact.cpp

HEADERS += \
    project1_header.h