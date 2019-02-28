TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    eventq.cpp \
    tests.c \
    testcpp.cpp

HEADERS += \
    eventcpp.h \
    eventc.h \
    testcpp.h
