QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    backtraking.cpp \
    blocklist.cpp \
    blocknode.cpp \
    graphicview.cpp \
    linkedlist.cpp \
    listback.cpp \
    listid.cpp \
    localserver.cpp \
    main.cpp \
    node.cpp \
    nodeback.cpp \
    nodeid.cpp \
    pathfindinglist.cpp \
    pathfindingnode.cpp \
    widget.cpp

HEADERS += \
    backtraking.h \
    blocklist.h \
    blocknode.h \
    graphicview.h \
    linkedlist.h \
    listback.h \
    listid.h \
    localserver.h \
    node.h \
    nodeback.h \
    nodeid.h \
    pathfindinglist.h \
    pathfindingnode.h \
    widget.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ghost.qrc
