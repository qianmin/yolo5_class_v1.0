QT       += core gui
QT += concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11

SOURCES += \
        main.cpp \
        yolo5.cpp

HEADERS += \
    yolo5.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

###opencv(MSVC opencv4.15.1)
# 手动添加工程包含（include）目录：
INCLUDEPATH+= D:\software\opencv\opencv\build\include
# 手动添加工程库（lib）目录：
LIBS += -LD:/software/opencv/opencv/build/x64/vc15/lib/ -lopencv_world451
