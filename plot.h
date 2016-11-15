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
    //�ػ�
    virtual void replot();
    //�¼�������
    virtual bool eventFilter( QObject *, QEvent * );

public Q_SLOTS:
    //���ü��ʱ��
    void setIntervalLength( double );

protected:
    //��ʾ�¼�
    virtual void showEvent( QShowEvent * );
    //�ػ��¼�
    virtual void resizeEvent( QResizeEvent * );
    //��ʱ���¼�
    virtual void timerEvent( QTimerEvent * );

private:
    //��������
    void updateCurve();
    //���Ӽ����
    void incrementInterval();

    QwtPlotMarker *d_origin;
    QwtPlotCurve *d_curve;
    int d_paintedPoints;

    QwtPlotDirectPainter *d_directPainter;

    QwtInterval d_interval;
    int d_timerId;

    QwtSystemClock d_clock;
};
