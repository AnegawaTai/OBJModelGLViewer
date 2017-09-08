#include "widget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <GL/glut.h>
#include "window.h"

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    QApplication a(argc, argv);
    MyWindow window;
    window.resize(window.sizeHint());   // recommonded size for the widget
    int desktopArea = QApplication::desktop()->width() *
            QApplication::desktop()->height();
    int widgetArea = window.width() * window.height();
    if (((float)widgetArea / (float)desktopArea) < 0.75f)
        window.show();
    else
        window.showMaximized();

    return a.exec();
}
