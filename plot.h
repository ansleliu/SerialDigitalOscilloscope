#include <qwt_plot.h>
#include <qwt_interval.h>
#include <qwt_system_clock.h>

class QwtPlotCurve;
class QwtPlotMarker;
class QwtPlotDirectPainter;

class Plot: public QwtPlot
{
    Q_OBJECT

public:
    Plot( QWidget * = NULL );
    virtual ~Plot();

    void start();
    //重绘
    virtual void replot();
    //事件过滤器
    virtual bool eventFilter( QObject *, QEvent * );

public Q_SLOTS:
    //设置间隔时间
    void setIntervalLength( double );

protected:
    //显示事件
    virtual void showEvent( QShowEvent * );
    //重绘事件
    virtual void resizeEvent( QResizeEvent * );
    //定时器事件
    virtual void timerEvent( QTimerEvent * );

private:
    //更新曲线
    void updateCurve();
    //增加间隔量
    void incrementInterval();

    QwtPlotMarker *d_origin;
    QwtPlotCurve *d_curve;
    int d_paintedPoints;

    QwtPlotDirectPainter *d_directPainter;

    QwtInterval d_interval;
    int d_timerId;

    QwtSystemClock d_clock;
};
