/********************************************************************************
** Form generated from reading UI file 'AboutDialog.ui'
**
** Created: Mon May 19 19:03:27 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QLabel *AboutLabel;
    QTextBrowser *TextBrowser;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QString::fromUtf8("AboutDialog"));
        AboutDialog->resize(420, 171);
        AboutDialog->setMaximumSize(QSize(420, 171));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/RC/pic.png"), QSize(), QIcon::Normal, QIcon::Off);
        AboutDialog->setWindowIcon(icon);
        AboutLabel = new QLabel(AboutDialog);
        AboutLabel->setObjectName(QString::fromUtf8("AboutLabel"));
        AboutLabel->setGeometry(QRect(10, 10, 171, 151));
        AboutLabel->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/RC/pic.png")));
        AboutLabel->setScaledContents(true);
        TextBrowser = new QTextBrowser(AboutDialog);
        TextBrowser->setObjectName(QString::fromUtf8("TextBrowser"));
        TextBrowser->setGeometry(QRect(190, 10, 221, 151));

        retranslateUi(AboutDialog);

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "\345\205\263\344\272\216\350\275\257\344\273\266", 0, QApplication::UnicodeUTF8));
        AboutLabel->setText(QString());
        TextBrowser->setHtml(QApplication::translate("AboutDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">            <span style=\" font-weight:600; color:#ff0000;\">\345\205\263\344\272\216\350\275\257\344\273\266</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\275\257\344\273\266\345\220\215\347\247\260\357\274\232AnsleDigitalOscilloscope</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\350\275\257\344\273\266\344\275\234\350\200\205\357\274\232\345\210\230\346\205\247\345\206\233</p>\n"
"<p sty"
                        "le=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\255\246\351\231\242\357\274\232    \351\200\232\344\277\241\345\267\245\347\250\213\345\255\246\351\231\242</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\344\270\223\344\270\232\357\274\232    \351\200\232\344\277\241\345\267\245\347\250\213</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\255\246\346\240\241\357\274\232    \350\245\277\345\256\211\347\224\265\345\255\220\347\247\221\346\212\200\345\244\247\345\255\246</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\227\245\346\234\237\357\274\232    2014.05.20</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0"
                        "; text-indent:0px;\"></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">                          Beta1.0.0</p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
