#ifndef DIGITALOSCILLOSCOPE_H
#define DIGITALOSCILLOSCOPE_H

#include <QMainWindow>
#include "SerialSamplingThread.h"
#include "qwt_system_clock.h"
#include "RecvDatabBase.h"
#include "QFile"
////////////////////////////////
//
class QTimer;
class QextSerialPort;
class QextSerialEnumerator;

///////////////////////////////
//
class WheelBox;

namespace Ui {
class DigitalOscilloscope;
}

class DigitalOscilloscope : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit DigitalOscilloscope(QWidget *parent = 0);
    ~DigitalOscilloscope();
/////////////////////////////////////////////////////////
//
private:
    void initCOMList();
    void initBaudRateList();
    void initDataBitList();
    void initParityList();
    void initStopBitList();
    void initQueryModel();

//////////////////////////////////////////////////////////
//
private Q_SLOTS:
    void onPortNameChanged(const QString &name);
    void onBaudRateChanged(int idx);
    void onParityChanged(int idx);
    void onDataBitsChanged(int idx);
    void onStopBitsChanged(int idx);
    void onTimeoutChanged(int val);
    void onQueryModeChanged(int idx);
    void onOpenCloseButtonClicked();
    void onReadyRead();
    void onPortAddedOrRemoved();

    void start();
    void setInterval(double val);

    void on_action_Quit_triggered();

    void on_action_Qt_triggered();

    void on_action_About_triggered();

Q_SIGNALS:
    void signalIntervalChanged(double);

public:
    double signalInterval() const;
/////////////////////////////////////////////
//
private:
    Ui::DigitalOscilloscope *ui;
    ///////////////////////////////////
    //
    QTimer *timer;
    QextSerialPort *port;
    QextSerialEnumerator *enumerator;

//    RecvDatabBase *recvDatabase;
    QFile *file;
    QTextStream out;
    ///////////////////////////////////
    //
    WheelBox *d_timerWheel;
//    WheelBox *d_intervalWheel;
//    SerialSamplingThread *samplingThread;
    QwtSystemClock clock;
    double interval;
    double time;
    int line;
};

#endif // DIGITALOSCILLOSCOPE_H
