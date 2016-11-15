#include "SerialSamplingThread.h"
#include "signaldata.h"
#include <qwt_math.h>
#include <QTextStream>

#if QT_VERSION < 0x040600
#define qFastSin(x) ::sin(x)
#endif

SerialSamplingThread::SerialSamplingThread(QObject *parent,
                                           RecvDatabBase *recvData,
                                           const QString &txt) :
    QwtSamplingThread(parent),
    d_frequency( 5.0 ),
    d_amplitude( 20.0 )
{
    i = 0;
    recv = recvData;
    m_file = new QFile(txt);
    if(!m_file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "file open false";
    }
    else
    {
        qDebug() << "file open";
    }
    in.setDevice(m_file);
}

SerialSamplingThread::~SerialSamplingThread()
{
     recv = NULL;
     m_file = NULL;
}

void SerialSamplingThread::sample(double elapsed)
{
    in.flush();
    if ( d_frequency > 0.0 )
    {
        if(!in.atEnd())
        {
            i++;
            float data = in.readLine().toFloat();
            const QPointF s(elapsed,data);
            SignalData::instance().append(s);
            qDebug() << QString("显示第 %1 行数据 %2").arg(i).arg(data);
        }
        else
        {
            usleep(10);
        }
    }
}

double SerialSamplingThread::value(double timeStamp) const
{
    const double v = timeStamp;
    return v;
}
