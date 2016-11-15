/********************************************************************************
** Form generated from reading UI file 'DigitalOscilloscope.ui'
**
** Created: Mon May 19 19:03:27 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIGITALOSCILLOSCOPE_H
#define UI_DIGITALOSCILLOSCOPE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "hled.h"
#include "plot.h"

QT_BEGIN_NAMESPACE

class Ui_DigitalOscilloscope
{
public:
    QAction *action_Quit;
    QAction *action_Qt;
    QAction *action_About;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    Plot *QwtPlotFrame;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *SerialLabel;
    QComboBox *COMComboBox;
    QLabel *BaudRateLabel;
    QComboBox *BaudComboBox;
    QLabel *DataBitLabel;
    QComboBox *DataBitComboBox;
    QLabel *ParityBitLabel;
    QComboBox *ParityBitComboBox;
    QLabel *StopBitLabel;
    QComboBox *StopComboBox;
    QLabel *QueryModelLabel;
    QComboBox *QueryModeComBox;
    QLabel *TimeOutLabel;
    QSpinBox *timeoutBox;
    HLed *led;
    QPushButton *OpenCloseButton;
    QWidget *d_timerWheel;
    QTextBrowser *RecvTextBrowser;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *DigitalOscilloscope)
    {
        if (DigitalOscilloscope->objectName().isEmpty())
            DigitalOscilloscope->setObjectName(QString::fromUtf8("DigitalOscilloscope"));
        DigitalOscilloscope->resize(860, 450);
        DigitalOscilloscope->setMinimumSize(QSize(860, 450));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/RC/Stats2.ico"), QSize(), QIcon::Normal, QIcon::Off);
        DigitalOscilloscope->setWindowIcon(icon);
        action_Quit = new QAction(DigitalOscilloscope);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/RC/Standby.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_Quit->setIcon(icon1);
        action_Qt = new QAction(DigitalOscilloscope);
        action_Qt->setObjectName(QString::fromUtf8("action_Qt"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/RC/qt-logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Qt->setIcon(icon2);
        action_About = new QAction(DigitalOscilloscope);
        action_About->setObjectName(QString::fromUtf8("action_About"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/RC/pic.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_About->setIcon(icon3);
        centralWidget = new QWidget(DigitalOscilloscope);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        QwtPlotFrame = new Plot(centralWidget);
        QwtPlotFrame->setObjectName(QString::fromUtf8("QwtPlotFrame"));
        QwtPlotFrame->setFrameShape(QFrame::NoFrame);
        QwtPlotFrame->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(QwtPlotFrame);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(144, 16777215));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        SerialLabel = new QLabel(groupBox);
        SerialLabel->setObjectName(QString::fromUtf8("SerialLabel"));

        gridLayout->addWidget(SerialLabel, 0, 0, 1, 2);

        COMComboBox = new QComboBox(groupBox);
        COMComboBox->setObjectName(QString::fromUtf8("COMComboBox"));
        COMComboBox->setEditable(true);

        gridLayout->addWidget(COMComboBox, 0, 2, 1, 1);

        BaudRateLabel = new QLabel(groupBox);
        BaudRateLabel->setObjectName(QString::fromUtf8("BaudRateLabel"));

        gridLayout->addWidget(BaudRateLabel, 1, 0, 1, 2);

        BaudComboBox = new QComboBox(groupBox);
        BaudComboBox->setObjectName(QString::fromUtf8("BaudComboBox"));

        gridLayout->addWidget(BaudComboBox, 1, 2, 1, 1);

        DataBitLabel = new QLabel(groupBox);
        DataBitLabel->setObjectName(QString::fromUtf8("DataBitLabel"));

        gridLayout->addWidget(DataBitLabel, 2, 0, 1, 2);

        DataBitComboBox = new QComboBox(groupBox);
        DataBitComboBox->setObjectName(QString::fromUtf8("DataBitComboBox"));

        gridLayout->addWidget(DataBitComboBox, 2, 2, 1, 1);

        ParityBitLabel = new QLabel(groupBox);
        ParityBitLabel->setObjectName(QString::fromUtf8("ParityBitLabel"));

        gridLayout->addWidget(ParityBitLabel, 3, 0, 1, 2);

        ParityBitComboBox = new QComboBox(groupBox);
        ParityBitComboBox->setObjectName(QString::fromUtf8("ParityBitComboBox"));

        gridLayout->addWidget(ParityBitComboBox, 3, 2, 1, 1);

        StopBitLabel = new QLabel(groupBox);
        StopBitLabel->setObjectName(QString::fromUtf8("StopBitLabel"));

        gridLayout->addWidget(StopBitLabel, 4, 0, 1, 2);

        StopComboBox = new QComboBox(groupBox);
        StopComboBox->setObjectName(QString::fromUtf8("StopComboBox"));

        gridLayout->addWidget(StopComboBox, 4, 2, 1, 1);

        QueryModelLabel = new QLabel(groupBox);
        QueryModelLabel->setObjectName(QString::fromUtf8("QueryModelLabel"));

        gridLayout->addWidget(QueryModelLabel, 5, 0, 1, 2);

        QueryModeComBox = new QComboBox(groupBox);
        QueryModeComBox->setObjectName(QString::fromUtf8("QueryModeComBox"));

        gridLayout->addWidget(QueryModeComBox, 5, 2, 1, 1);

        TimeOutLabel = new QLabel(groupBox);
        TimeOutLabel->setObjectName(QString::fromUtf8("TimeOutLabel"));

        gridLayout->addWidget(TimeOutLabel, 6, 0, 1, 2);

        timeoutBox = new QSpinBox(groupBox);
        timeoutBox->setObjectName(QString::fromUtf8("timeoutBox"));
        timeoutBox->setMinimum(-1);
        timeoutBox->setMaximum(10000);
        timeoutBox->setSingleStep(10);
        timeoutBox->setValue(10);

        gridLayout->addWidget(timeoutBox, 6, 2, 1, 1);

        led = new HLed(groupBox);
        led->setObjectName(QString::fromUtf8("led"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(led->sizePolicy().hasHeightForWidth());
        led->setSizePolicy(sizePolicy);
        led->setMinimumSize(QSize(20, 20));
        led->setMaximumSize(QSize(25, 25));

        gridLayout->addWidget(led, 7, 0, 1, 1);

        OpenCloseButton = new QPushButton(groupBox);
        OpenCloseButton->setObjectName(QString::fromUtf8("OpenCloseButton"));

        gridLayout->addWidget(OpenCloseButton, 7, 1, 1, 2);


        verticalLayout->addWidget(groupBox);

        d_timerWheel = new QWidget(centralWidget);
        d_timerWheel->setObjectName(QString::fromUtf8("d_timerWheel"));
        d_timerWheel->setMaximumSize(QSize(144, 86));

        verticalLayout->addWidget(d_timerWheel);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 10);
        horizontalLayout->setStretch(1, 2);

        verticalLayout_2->addLayout(horizontalLayout);

        RecvTextBrowser = new QTextBrowser(centralWidget);
        RecvTextBrowser->setObjectName(QString::fromUtf8("RecvTextBrowser"));
        RecvTextBrowser->setMaximumSize(QSize(16777215, 71));
        RecvTextBrowser->setFrameShape(QFrame::StyledPanel);

        verticalLayout_2->addWidget(RecvTextBrowser);

        verticalLayout_2->setStretch(0, 10);
        verticalLayout_2->setStretch(1, 2);

        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);

        DigitalOscilloscope->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DigitalOscilloscope);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 860, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        DigitalOscilloscope->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action_Quit);
        menu_2->addAction(action_Qt);
        menu_2->addAction(action_About);

        retranslateUi(DigitalOscilloscope);

        QMetaObject::connectSlotsByName(DigitalOscilloscope);
    } // setupUi

    void retranslateUi(QMainWindow *DigitalOscilloscope)
    {
        DigitalOscilloscope->setWindowTitle(QApplication::translate("DigitalOscilloscope", "AnsleDigitalOscilloscope", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("DigitalOscilloscope", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        action_Qt->setText(QApplication::translate("DigitalOscilloscope", "\345\205\263\344\272\216Qt", 0, QApplication::UnicodeUTF8));
        action_About->setText(QApplication::translate("DigitalOscilloscope", "\345\205\263\344\272\216\350\275\257\344\273\266", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DigitalOscilloscope", "\344\270\262\345\217\243\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        SerialLabel->setText(QApplication::translate("DigitalOscilloscope", "\344\270\262    \345\217\243", 0, QApplication::UnicodeUTF8));
        BaudRateLabel->setText(QApplication::translate("DigitalOscilloscope", "\346\263\242 \347\211\271 \347\216\207", 0, QApplication::UnicodeUTF8));
        DataBitLabel->setText(QApplication::translate("DigitalOscilloscope", "\346\225\260 \346\215\256 \344\275\215", 0, QApplication::UnicodeUTF8));
        ParityBitLabel->setText(QApplication::translate("DigitalOscilloscope", "\346\240\241 \351\252\214 \344\275\215", 0, QApplication::UnicodeUTF8));
        StopBitLabel->setText(QApplication::translate("DigitalOscilloscope", "\345\201\234 \346\255\242 \344\275\215", 0, QApplication::UnicodeUTF8));
        QueryModelLabel->setText(QApplication::translate("DigitalOscilloscope", "\346\237\245\350\257\242\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        TimeOutLabel->setText(QApplication::translate("DigitalOscilloscope", "\350\266\205    \346\227\266", 0, QApplication::UnicodeUTF8));
        timeoutBox->setSuffix(QApplication::translate("DigitalOscilloscope", " ms", 0, QApplication::UnicodeUTF8));
        OpenCloseButton->setText(QApplication::translate("DigitalOscilloscope", "\346\211\223\345\274\200/\345\205\263\351\227\255\344\270\262\345\217\243", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("DigitalOscilloscope", "\345\274\200\345\247\213", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("DigitalOscilloscope", "\345\205\263\344\272\216", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DigitalOscilloscope: public Ui_DigitalOscilloscope {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIGITALOSCILLOSCOPE_H
