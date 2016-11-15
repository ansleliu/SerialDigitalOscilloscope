#ifndef _SIGNAL_DATA_H_
#define _SIGNAL_DATA_H_

#include <qrect.h>

class SignalData
{
public:
    //引例
    static SignalData &instance();

    //添加点
    void append( const QPointF &pos );
    //去除过时的点
    void clearStaleValues( double min );

    int size() const;
    //取采样值
    QPointF value( int index ) const;

    QRectF boundingRect() const;
    //锁定
    void lock();
    //解锁定
    void unlock();

private:
    //构造函数
    SignalData();
    SignalData( const SignalData & );
    //重载=
    SignalData &operator=( const SignalData & );

    virtual ~SignalData();
    //私有变量
    class PrivateData;
    PrivateData *d_data;
};

#endif
