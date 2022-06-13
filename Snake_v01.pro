QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Button.cpp \
    Fruit.cpp \
    Game.cpp \
    Obstacle.cpp \
    Score.cpp \
    SnakeBody.cpp \
    SnakeHead.cpp \
    main.cpp

HEADERS += \
    Button.h \
    Fruit.h \
    Game.h \
    Score.h \
    SnakeBody.h \
    SnakeHead.h \
    obstacle.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
