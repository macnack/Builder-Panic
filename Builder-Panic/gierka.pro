TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        coin.cpp \
        enemy.cpp \
        floor.cpp \
        game.cpp \
        main.cpp \
        object.cpp \
        objectmanager.cpp \
        player.cpp \
        wall.cpp

CONFIG(debug, debug|release){
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    coin.h \
    common_defs.h \
    enemy.h \
    floor.h \
    object.h \
    objectmanager.h \
    player.h \
    game.h \
    wall.h

DISTFILES += \
    uml.qmodel

