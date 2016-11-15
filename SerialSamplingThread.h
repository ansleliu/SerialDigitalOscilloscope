#ifndef SERIALSAMPLINGTHREAD_H
#define SERIALSAMPLINGTHREAD_H
#include <qwt_sampling_thread.h>
#include "RecvDatabBase.h"
#include "QFile"
class SerialSamplingThread : public QwtSamplingThread
{
    Q_OBJECT
public:
    explicit SerialSamplingThread(QObject *parent = 0,
                                  RecvDatabBase *recvData = NULL,
                                  const QString &txt = "");
    ~SerialSamplingThread();
protected:
    //采样
    virtual void sample(double elapsed);

private:
    //采样值
    virtual double value( double timeStamp ) const;

////////////////////////////////////////////////////
//
private:
    double d_frequency;
    double d_amplitude;
    int i;
    RecvDatabBase *recv;
    QFile *m_file;
    qint64 offset;
    QTextStream in;
};

#endif // SERIALSAMPLINGTHREAD_H
