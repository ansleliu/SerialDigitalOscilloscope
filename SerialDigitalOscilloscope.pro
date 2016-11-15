#-------------------------------------------------
#
# Project created by QtCreator 2014-05-18T12:56:33
#
#-------------------------------------------------

QT       += core gui sql

TARGET = SerialDigitalOscilloscope
TEMPLATE = app

DEFINES    += QWT_DLL

SOURCES += main.cpp\
        DigitalOscilloscope.cpp \
    SerialPort/qextserialport_win.cpp \
    SerialPort/qextserialport.cpp \
    SerialPort/qextserialenumerator_win.cpp \
    SerialPort/qextserialenumerator.cpp \
    wheelbox.cpp \
    signaldata.cpp \
    plot.cpp \
    knob.cpp \
    curvedata.cpp \
    hled.cpp \
    SerialSamplingThread.cpp \
    MySQLite.cpp \
    RecvDatabBase.cpp \
    PathMgr.cpp \
    AboutDialog.cpp

HEADERS  += DigitalOscilloscope.h \
    SerialPort/qextserialport_p.h \
    SerialPort/qextserialport_global.h \
    SerialPort/qextserialport.h \
    SerialPort/qextserialenumerator_p.h \
    SerialPort/qextserialenumerator.h \
    wheelbox.h \
    signaldata.h \
    plot.h \
    knob.h \
    curvedata.h \
    hled.h \
    SerialSamplingThread.h \
    MySQLite.h \
    RecvDatabBase.h \
    PathMgr.h \
    AboutDialog.h

FORMS    += DigitalOscilloscope.ui \
    AboutDialog.ui

UI_DIR = ./ui
MOC_DIR = TEMP/moc
RCC_DIR = TEMP/rcc
OBJECTS_DIR = TEMP/obj

win32:LIBS  += -lsetupapi -ladvapi32 -luser32

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/QWT/ -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/QWT/ -lqwtd

INCLUDEPATH += $$PWD/QWT/Qwt
DEPENDPATH += $$PWD/QWT/Qwt

win32 {
    contains(QWT_CONFIG, QwtDll) {
        DEFINES    += QT_DLL QWT_DLL
    }
}

RESOURCES += \
    RC.qrc

OTHER_FILES += \
    MyApp.rc
RC_FILE = MyApp.rc
