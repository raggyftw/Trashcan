#include "gui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUI w; //Creates an object of the GUI class called w
    w.show(); //calls the show method from the GUI class

    return a.exec();
}//End of main
