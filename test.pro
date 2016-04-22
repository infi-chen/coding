TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    UnitTest.cpp \
    my_stack.cpp \
    clib/my_string.cpp

OTHER_FILES += \
    Makefile

HEADERS += \
    test.h \
    my_stack.h \
    clib/my_string.h

