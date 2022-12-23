QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cutbox.cpp \
    cutellipsoid.cpp \
    cutsphere.cpp \
    cutvoxel.cpp \
    figurageometrica.cpp \
    main.cpp \
    mainwindow.cpp \
    plotter.cpp \
    putbox.cpp \
    putellipsoid.cpp \
    putsphere.cpp \
    putvoxel.cpp \
    sculptor.cpp \
    setcolor.cpp

HEADERS += \
    Voxel.h \
    cutbox.h \
    cutellipsoid.h \
    cutsphere.h \
    cutvoxel.h \
    figurageometrica.h \
    mainwindow.h \
    plotter.h \
    putbox.h \
    putellipsoid.h \
    putsphere.h \
    putvoxel.h \
    sculptor.h \
    setcolor.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
