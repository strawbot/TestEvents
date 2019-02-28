TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    eventq.cpp \
    tests.c \
    testcpp.cpp

HEADERS += \
    testcpp.h \
    event.hpp \
    event.h
