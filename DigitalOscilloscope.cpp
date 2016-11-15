#include "DigitalOscilloscope.h"
#include "ui_DigitalOscilloscope.h"
#include "SerialPort/qextserialenumerator.h"
#include "SerialPort/qextserialport.h"
#include "wheelbox.h"
#include "QTimer"
#include "signaldata.h"
#include "qwt_global.h"
#include <qthread.h>
#include "qwt_system_clock.h"
#include "PathMgr.h"
#include "QMessageBox"
#include "AboutDialog.h"

DigitalOscilloscope::DigitalOscilloscope(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DigitalOscilloscope)
{
    ui->setupUi(this);
    //////////////////////////////////////////////////////
    //波形显示窗
    line = 0;
    time = 0.0;
    const double intervalLength = 10.0; // seconds
    ui->QwtPlotFrame->setIntervalLength(intervalLength);
    ///////////////////////////////////////////////////////////////
    //调节滑轮
    d_timerWheel = new WheelBox("        时间轴扩展        ",
                                1.0, 100.0, 1.0,
                                ui->d_timerWheel);
    d_timerWheel->setValue(intervalLength);

//    d_intervalWheel = new WheelBox(" Sample Interval  [ms]",
//                                   0.0,20.0, 0.1,
//                                   ui->d_intervalWheel);
//    d_intervalWheel->setValue(10.0);
    interval = 10.0;
    connect(d_timerWheel, SIGNAL(valueChanged(double)),
            ui->QwtPlotFrame,
            SLOT(setIntervalLength( double )));
/*
    connect(d_intervalWheel, SIGNAL( valueChanged(double)),
        SIGNAL( signalIntervalChanged(double)));
    connect(d_intervalWheel, SIGNAL( valueChanged(double)),
        SLOT(setInterval( double )));
*/
    ////////////////////////////////
    //初始化显示
    ui->led->turnOff();
    initCOMList();
    initBaudRateList();
    initDataBitList();
    initParityList();
    initStopBitList();
    initQueryModel();
    ////////////////////////////////////////////////////////////////////////////////
    //串口操作
    timer = new QTimer(this);
    timer->setInterval(10);
    PortSettings settings = {BAUD9600, DATA_8, PAR_NONE, STOP_1, FLOW_OFF, 10};
    port = new QextSerialPort(ui->COMComboBox->currentText(),
                              settings, QextSerialPort::Polling);

    enumerator = new QextSerialEnumerator(this);
    enumerator->setUpNotifications();

    PathManage::createRelExeDir("/RecvDataDB/");
//    QString RecvDataDB = PathManage::makePathStr("/RecvDataDB/RecvDataDB.db");
//    recvDatabase = new RecvDatabBase(RecvDataDB,"RecvDataDB");
//    recvDatabase->clearTable();

    QString currTime;
    currTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss");
    QString RecvDataTXT = PathManage::makePathStr(QString("/RecvDataDB/Recv%1.txt").arg(currTime));
    file = new QFile(RecvDataTXT);
    if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, tr(" 错误 "), tr("\n 文件打开失败！"));
        qDebug() << "file open false";
    }
    else
    {
        qDebug() << "file open";
        out.setDevice(file);
    }
    /////////////////////////////////////////////////////////////
    //采样点获得线程
//    samplingThread = new SerialSamplingThread(this,NULL,RecvDataTXT);
//    samplingThread->setInterval(signalInterval());
//    connect(this, SIGNAL(signalIntervalChanged(double)),
//            samplingThread, SLOT(setInterval(double )));

    ////////////////////////////////////
    //串口信号与槽的关联
    connect(ui->BaudComboBox, SIGNAL(currentIndexChanged(int)), SLOT(onBaudRateChanged(int)));
    connect(ui->ParityBitComboBox, SIGNAL(currentIndexChanged(int)), SLOT(onParityChanged(int)));
    connect(ui->DataBitComboBox, SIGNAL(currentIndexChanged(int)), SLOT(onDataBitsChanged(int)));
    connect(ui->StopComboBox, SIGNAL(currentIndexChanged(int)), SLOT(onStopBitsChanged(int)));
    connect(ui->timeoutBox, SIGNAL(valueChanged(int)), SLOT(onTimeoutChanged(int)));
    connect(ui->QueryModeComBox, SIGNAL(currentIndexChanged(int)), SLOT(onQueryModeChanged(int)));
    connect(ui->COMComboBox, SIGNAL(editTextChanged(QString)), SLOT(onPortNameChanged(QString)));
    connect(ui->OpenCloseButton, SIGNAL(clicked()), SLOT(onOpenCloseButtonClicked()));
    connect(timer, SIGNAL(timeout()), SLOT(onReadyRead()));
    connect(port, SIGNAL(readyRead()),this,SLOT(onReadyRead()));

    connect(enumerator, SIGNAL(deviceDiscovered(QextPortInfo)), SLOT(onPortAddedOrRemoved()));
    connect(enumerator, SIGNAL(deviceRemoved(QextPortInfo)), SLOT(onPortAddedOrRemoved()));
}

DigitalOscilloscope::~DigitalOscilloscope()
{
    delete ui;

    port->deleteLater();
    port = NULL;

    if(timer->isActive())
    {
        timer->stop();
    }
    timer->deleteLater();
    timer = NULL;

    enumerator->deleteLater();
    enumerator = NULL;

//    samplingThread->stop();
//    samplingThread->wait(1000);

    d_timerWheel->deleteLater();
    d_timerWheel = NULL;
//    d_intervalWheel->deleteLater();
//    d_intervalWheel = NULL;

//    recvDatabase->clearTable();
//    delete recvDatabase;
//    recvDatabase = NULL;
}

void DigitalOscilloscope::initCOMList()
{
    QList<QextPortInfo> ports = QextSerialEnumerator::getPorts();
    qDebug() << "List of ports:";
    foreach (QextPortInfo info, ports)
    {
        qDebug() << "port name:"       << info.portName;
        qDebug() << "friendly name:"   << info.friendName;
        qDebug() << "physical name:"   << info.physName;
        qDebug() << "enumerator name:" << info.enumName;
        qDebug() << "vendor ID:"       << info.vendorID;
        qDebug() << "product ID:"      << info.productID;

        ////////////////////////////////////////////////////
        //将可用的串口加入到串口列表
        ui->COMComboBox->addItem(info.portName);
    }
}

void DigitalOscilloscope::initBaudRateList()
{
    ui->BaudComboBox->addItem("2400", BAUD2400);
    ui->BaudComboBox->addItem("4800", BAUD4800);
    ui->BaudComboBox->addItem("9600", BAUD9600);
    ui->BaudComboBox->addItem("19200", BAUD19200);
    ui->BaudComboBox->addItem("115200", BAUD115200);
    ui->BaudComboBox->setCurrentIndex(2);
}

void DigitalOscilloscope::initDataBitList()
{
    ui->DataBitComboBox->addItem("5", DATA_5);
    ui->DataBitComboBox->addItem("6", DATA_6);
    ui->DataBitComboBox->addItem("7", DATA_7);
    ui->DataBitComboBox->addItem("8", DATA_8);
    ui->DataBitComboBox->setCurrentIndex(3);
}

void DigitalOscilloscope::initParityList()
{
    ui->ParityBitComboBox->addItem("无", PAR_NONE);
    ui->ParityBitComboBox->addItem("奇", PAR_ODD);
    ui->ParityBitComboBox->addItem("偶", PAR_EVEN);
    ui->ParityBitComboBox->setCurrentIndex(0);
}

void DigitalOscilloscope::initStopBitList()
{
    ui->StopComboBox->addItem("1", STOP_1);
    ui->StopComboBox->addItem("2", STOP_2);
    ui->StopComboBox->setCurrentIndex(0);
}

void DigitalOscilloscope::initQueryModel()
{
    ui->QueryModeComBox->addItem("Polling", QextSerialPort::Polling);
    ui->QueryModeComBox->addItem("EventDriven", QextSerialPort::EventDriven);
    ui->QueryModeComBox->setCurrentIndex(0);
}

void DigitalOscilloscope::onPortNameChanged(const QString &name)
{
    Q_UNUSED(name);
    if (port->isOpen())
    {
        port->close();
//        recvDatabase->clearTable();
        ui->led->turnOff();
//        samplingThread->stop();
//        samplingThread->wait(1000);
    }
}

void DigitalOscilloscope::onBaudRateChanged(int idx)
{
    port->setBaudRate((BaudRateType)ui->BaudComboBox->itemData(idx).toInt());
}

void DigitalOscilloscope::onParityChanged(int idx)
{
    port->setParity((ParityType)ui->ParityBitComboBox->itemData(idx).toInt());
}

void DigitalOscilloscope::onDataBitsChanged(int idx)
{
    port->setDataBits((DataBitsType)ui->DataBitComboBox->itemData(idx).toInt());
}

void DigitalOscilloscope::onStopBitsChanged(int idx)
{
    port->setStopBits((StopBitsType)ui->StopComboBox->itemData(idx).toInt());
}

void DigitalOscilloscope::onTimeoutChanged(int val)
{
    port->setTimeout(val);
}

void DigitalOscilloscope::onQueryModeChanged(int idx)
{
    port->setQueryMode((QextSerialPort::QueryMode)ui->QueryModeComBox->itemData(idx).toInt());
}

void DigitalOscilloscope::onOpenCloseButtonClicked()
{
    if (!port->isOpen())
    {
        /////////////////////////////////////////////////////
        //打开串口
        port->setPortName(ui->COMComboBox->currentText());
        port->open(QIODevice::ReadWrite);
        /////////////////////////////////////////////////////
        //打开串口以后的操作
        time = 0.0;
//        recvDatabase->clearTable();
        start();
    }
    else
    {
        port->close();
//        samplingThread->stop();
//        samplingThread->wait(1000);
//        recvDatabase->clearTable();
    }

    //If using polling mode, we need a QTimer
    if (port->isOpen() && port->queryMode() == QextSerialPort::Polling)
    {
        timer->start();
    }
    else
    {
        timer->stop();
    }

    //update led's status
    ui->led->turnOn(port->isOpen());
}

void DigitalOscilloscope::onReadyRead()
{
    QByteArray adData;
    if (port->bytesAvailable())
    {
        adData = port->readAll();
        /////////////////////////////////////////
        //收到的数据
        ui->RecvTextBrowser->moveCursor(QTextCursor::End);
        ui->RecvTextBrowser->insertPlainText(QString::fromLatin1(adData));        
        out << QString::fromLatin1(adData) << "\n";
    }
    //////////////////////////////////
    //处理接收到的数据
    QString RecvStr = adData;
    QStringList RecvData = RecvStr.split(",", QString::SkipEmptyParts);
    for(int i=0;i<RecvData.size();i++)
    {
        line++;
        if(line%200 == 0)
        {
            ui->RecvTextBrowser->clear();
        }
        const int udata = RecvData.at(i).toInt();
        const float recvData = ((float)udata)*3300/4096/1000;
//        qDebug() << QString("收到的数据为：%1 在文件中处在第 %2 行").arg(recvData).arg(line);
        //准备显示接收到的数据
//        const QPointF s(time,recvData);
        const double elapsed = clock.elapsed();
        const QPointF s(elapsed/(interval*100.0),recvData);
        SignalData::instance().append(s);
//        time += 0.005;  //100ms一个数据
    }
}

void DigitalOscilloscope::onPortAddedOrRemoved()
{
    QString current = ui->COMComboBox->currentText();

    ui->COMComboBox->blockSignals(true);
    ui->COMComboBox->clear();
    foreach (QextPortInfo info, QextSerialEnumerator::getPorts())
    {
        ui->COMComboBox->addItem(info.portName);
    }

    ui->COMComboBox->setCurrentIndex(ui->COMComboBox->findText(current));

    ui->COMComboBox->blockSignals(false);
}

void DigitalOscilloscope::start()
{
    ////////////////////////////////////////////////////
    //开始
//    samplingThread->start();
    ui->QwtPlotFrame->start();
    clock.start();
}

void DigitalOscilloscope::setInterval(double val)
{
    interval = val;
}

double DigitalOscilloscope::signalInterval() const
{
    return d_timerWheel->value();
}


void DigitalOscilloscope::on_action_Quit_triggered()
{
    if (QMessageBox::Yes == QMessageBox::information(this,
                                                     "提示信息",
                                                     "您确定要退出吗?",
                                 QMessageBox::Yes | QMessageBox::No))
    {
        QApplication::closeAllWindows();
    }
    else
    {
    }
}

void DigitalOscilloscope::on_action_Qt_triggered()
{
    QApplication::aboutQt();
}

void DigitalOscilloscope::on_action_About_triggered()
{
    AboutDialog *about;
    about = new AboutDialog(this);

    if(about->exec() == QDialog::Rejected)
    {

    }
    about->close();
    about->deleteLater();
    about = NULL;
}
