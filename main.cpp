#include "window.h"
#include "myglwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Window w;
    //w.show();
    MyGLWidget w;
    w.showFullScreen();

    return a.exec();
}
