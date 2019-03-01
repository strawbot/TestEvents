TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    tests.c \
    testcpp.cpp \
    event.cpp \
    action.cpp \
    printersHost.c \
    queue.c \
    timeout.c

HEADERS += \
    testcpp.h \
    event.h \
    action.hpp \
    printers.h \
    queue.h \
    timeout.h \
    timestamp.h
