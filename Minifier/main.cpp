#include "mainwindow.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Set default icon of main window
    w.setWindowIcon(QIcon(":/pics/img/icon.png"));
    w.show();

    return a.exec();
}
