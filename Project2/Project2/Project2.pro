TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    jacobi_cyclic.cpp \
    householder.cpp \
    jacobi_max.cpp \
    lanczos.cpp \
    off_norm.cpp \
    off_max.cpp \
    test-main.cpp \
    test-functions.cpp \
    mat_generate.cpp


INCLUDEPATH += /usr/local/include
LIBS += -L/usr/local/lib


LIBS += -larmadillo -llapack -lblas

HEADERS += \
    project2_header.h \
    test-functions
