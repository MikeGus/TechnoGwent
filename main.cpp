#include <QApplication>
#include <QDesktopWidget>
#include "testproxy.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TestProxy pr;
    QSize windowSize = a.desktop()->geometry().size();
    pr.init(windowSize.width(), windowSize.height());

    return a.exec();
}
