#include <iostream>
#include "Encounter.h"

//gui demo
#include <QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[]) //qt entrypoint
{
    QApplication app(argc, argv);

    MainWindow window;  //create main window
    window.show();      //show main window

    return app.exec();
}