TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

INCLUDEPATH += $$PWD

HEADERS += \
    ability.h \
    alliance.h \
    card.h \
    commander.h \
    effect.h \
    field.h \
    fighter.h \
    hand.h \
    maniac.h \
    modificator.h \
    role.h \
    row.h \
    side.h \
    create_db.h
