#include <QtGui/QApplication>
#include "DigitalOscilloscope.h"
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    a.setPalette(Qt::darkGray);
    QApplication::addLibraryPath("./plugins");

    QTextCodec *codec = QTextCodec::codecForName("System");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    DigitalOscilloscope w;
    w.show();

    return a.exec();
}
