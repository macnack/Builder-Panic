TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        animation.cpp \
        coin.cpp \
        enemy.cpp \
        entity.cpp \
        game.cpp \
        gameobject.cpp \
        hero.cpp \
        main.cpp \
        object.cpp \
        objectmanager.cpp \
        player.cpp \
        scena.cpp

CONFIG(debug, debug|release){
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    animation.h \
    coin.h \
    common_defs.h \
    enemy.h \
    entity.h \
    gameobject.h \
    hero.h \
    object.h \
    objectmanager.h \
    player.h \
    game.h \
    scena.h

DISTFILES += \
    model_uml.qmodel

