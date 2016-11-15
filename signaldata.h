#ifndef _SIGNAL_DATA_H_
#define _SIGNAL_DATA_H_

#include <qrect.h>

class SignalData
{
public:
    //����
    static SignalData &instance();

    //��ӵ�
    void append( const QPointF &pos );
    //ȥ����ʱ�ĵ�
    void clearStaleValues( double min );

    int size() const;
    //ȡ����ֵ
    QPointF value( int index ) const;

    QRectF boundingRect() const;
    //����
    void lock();
    //������
    void unlock();

private:
    //���캯��
    SignalData();
    SignalData( const SignalData & );
    //����=
    SignalData &operator=( const SignalData & );

    virtual ~SignalData();
    //˽�б���
    class PrivateData;
    PrivateData *d_data;
};

#endif
