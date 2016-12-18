#-------------------------------------------------
#
# Project created by QtCreator 2016-05-30T16:46:39
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = YakubovichGame
TEMPLATE = app


SOURCES += main.cpp \
    player.cpp \
    bullet.cpp \
    enemy.cpp \
    game.cpp \
    score.cpp \
    health.cpp \
    effect.cpp

HEADERS  += \
    player.h \
    bullet.h \
    enemy.h \
    game.h \
    score.h \
    health.h \
    effect.h

RESOURCES += \
    res.qrc
