
#include <QtWidgets/QApplication>
#include "../src/Toast.h"
#include "window.h"


int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Window* window = new Window();
    window->show();
    int r = a.exec();
    delete window;
    return r;
}
