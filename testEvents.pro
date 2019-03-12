TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    tests.c \
    testcpp.cpp \
    ../SLDV2/TimbreOS/event.cpp \
    ../SLDV2/TimbreOS/printersHost.c \
    ../SLDV2/TimbreOS/timeout.c \
    ../SLDV2/TimbreOS/queue.c \
    ../SLDV2/TimbreOS/timeEvent.cpp \
    mocks.cpp

HEADERS += \
    testcpp.h \
    test.h

INCLUDEPATH += ../SLDV2/TimbreOS
