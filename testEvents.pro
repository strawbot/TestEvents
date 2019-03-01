TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    tests.c \
    testcpp.cpp \
    event.cpp

HEADERS += \
    testcpp.h \
    event.h
