#include "mainwindow.h"

#include <QApplication>
#include <QIcon>
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_DisableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_Use96Dpi);
    QApplication a(argc, argv);
    MainWindow w;

    QFont font = qApp->font();
    font.setPixelSize(14);
    qApp->setFont(font);

    // Set default icon of main window
    w.setWindowIcon(QIcon(":/pics/img/icon.png"));
    w.show();

    return a.exec();
}
