TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    tests.c \
    testcpp.cpp \
printersHost.c \
    ../SLDV2/TimbreOS/event.cpp

#    action.cpp \
#    queue.c \
#    timeout.c

HEADERS += \
    testcpp.h \
    action.hpp \
    printers.h \
    queue.h \
    timeout.h \
timestamp.h \
    ../SLDV2/TimbreOS/event.h
