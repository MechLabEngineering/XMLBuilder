#-------------------------------------------------
#
# Project created by QtCreator 2013-04-30T16:55:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = XML_Builder
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    StartWidget.cpp \
    MainWidget.cpp \
    Testbilder.cpp \
    ObjectMaker.cpp \
    TrainCascade.cpp \
    TestClassifier.cpp \
    InfoIOLayout.cpp \
    DrawOnImageLayout.cpp \
#    haartraining.cpp \
#    cvsamples.cpp \
#    cvhaartraining.cpp \
#    cvhaarclassifier.cpp \
#    cvcommon.cpp \
#    cvboost.cpp \
    CreateSamplesMS.cpp

HEADERS  += mainwindow.h \
    StartWidget.h \
    MainWidget.h \
    Testbilder.h \
    ObjectMaker.h \
    TrainCascade.h \
    TestClassifier.h \
    InfoIOLayout.h \
    DrawOnImageLayout.h \
#    highgui.h \
#    cxmisc.h \
#    cxcore.hpp \
#    cxcore.h \
#    cvhaartraining.h \
#    cvclassifier.h \
#    cv.hpp \
#    cv.h \
#    _cvhaartraining.h \
#    _cvcommon.h \
    CreateSamplesMS.h


FORMS    += mainwindow.ui

win32: INCLUDEPATH += ./include
win32: DEPENDPATH += ./include
win32: LIBS += -L./lib -lopencv_highgui240.dll
win32: LIBS += -L./lib -lopencv_core240.dll
win32: LIBS += -L./lib -lopencv_video240.dll
win32: LIBS += -L./lib -lopencv_imgproc240.dll
win32: LIBS += -L./lib -lopencv_features2d240.dll
win32: LIBS += -L./lib -lopencv_flann240.dll
win32: LIBS += -L./lib -lopencv_legacy240.dll
win32: LIBS += -L./lib -lopencv_objdetect240.dll
win32: LIBS += -L./lib -lopencv_calib3d240.dll
