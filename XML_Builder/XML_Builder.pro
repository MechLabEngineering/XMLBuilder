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

win32: INCLUDEPATH += C:/opencv_2_4_0/build/include
win32: DEPENDPATH += C:/opencv_2_4_0/build/include
#win32: INCLUDEPATH += C:/opencv_2_4_0/apps
#win32: DEPENDPATH += C:/opencv_2_4_0/apps
win32: LIBS += -LC:/opencv_2_4_0/mingw_4_4_0/release/lib -lopencv_highgui240.dll
win32: LIBS += -LC:/opencv_2_4_0/mingw_4_4_0/release/lib -lopencv_core240.dll
#win32: LIBS += -LC:/opencv_2_4_0/mingw_4_4_0/release/lib -lopencv_haartraining_engine
win32: LIBS += -LC:/opencv_2_4_0/mingw_4_4_0/release/lib -lopencv_video240.dll
win32: LIBS += -LC:/opencv_2_4_0/mingw_4_4_0/release/lib -lopencv_imgproc240.dll
win32: LIBS += -LC:/opencv_2_4_0/mingw_4_4_0/release/lib -lopencv_features2d240.dll
win32: LIBS += -LC:/opencv_2_4_0/mingw_4_4_0/release/lib -lopencv_flann240.dll
win32: LIBS += -LC:/opencv_2_4_0/mingw_4_4_0/release/lib -lopencv_legacy240.dll
win32: LIBS += -LC:/opencv_2_4_0/mingw_4_4_0/release/lib -lopencv_objdetect240.dll
win32: LIBS += -LC:/opencv_2_4_0/mingw_4_4_0/release/lib -lopencv_calib3d240.dll


#win32: LIBS += -LC:/opencv_2_4_0/build/x86/mingw/lib -lopencv_calib3d240.dll
#win32: LIBS += -LC:/opencv_2_4_0/build/x86/mingw/lib -lopencv_contrib240.dll
#win32: LIBS += -LC:/opencv_2_4_0/build/x86/mingw/lib -lopencv_core240.dll
#win32: LIBS += -LC:/opencv_2_4_0/build/x86/mingw/lib -lopencv_features2d240.dll
#win32: LIBS += -LC:/opencv_2_4_0/build/x86/mingw/lib -lopencv_flann240.dll
#win32: LIBS += -LC:/opencv_2_4_0/build/x86/mingw/lib -lopencv_gpu240.dll
#win32: LIBS += -LC:/opencv_2_4_0/build/x86/mingw/lib -lopencv_highgui240.dll
#win32: LIBS += -LC:/opencv_2_4_0/build/x86/mingw/lib -lopencv_imgproc240.dll
#win32: LIBS += -LC:/opencv_2_4_0/build/x86/mingw/lib -lopencv_legacy240.dll
#win32: LIBS += -LC:/opencv_2_4_0/build/x86/mingw/lib -lopencv_ml240.dll
#win32: LIBS += -LC:/opencv_2_4_0/build/x86/mingw/lib -lopencv_nonfree240.dll
#win32: LIBS += -LC:/opencv_2_4_0/build/x86/mingw/lib -lopencv_objdetect240.dll
#win32: LIBS += -LC:/opencv_2_4_0/build/x86/mingw/lib -lopencv_photo240.dll
#win32: LIBS += -LC:/opencv_2_4_0/build/x86/mingw/lib -lopencv_stitching240.dll
#win32: LIBS += -LC:/opencv_2_4_0/build/x86/mingw/lib -lopencv_video240.dll
#win32: LIBS += -LC:/opencv_2_4_0/build/x86/mingw/lib -lopencv_videostab240.dll
