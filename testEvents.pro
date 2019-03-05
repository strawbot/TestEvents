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
    mocks.c \
    ../SLDV2/TimbreOS/timeEvent.cpp

HEADERS += \
    testcpp.h \

INCLUDEPATH += ../SLDV2/TimbreOS
