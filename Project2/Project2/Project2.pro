TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    jacobi_brute.cpp \
    jacobi_cyclic.cpp \
    householder.cpp

INCLUDEPATH += C:\Users\Ola\Documents\armadillo\include

LIBS += -LC:\Users\Ola\Documents\armadillo\examples\lib_win64
    -llapack_win64_MT
    -lblas_win64_MT

HEADERS += \
    project2_header.h
