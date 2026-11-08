#include <iostream>
#include "Encounter.h"

//gui demo
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}

/* currently hiding:


int main() {
    Forest forest;
    Cave cave;
    Pokedex dex;
    Encounter enc(&forest);
 
    enc.run(30, dex);          // Forest encounter
    enc.setRegion(&cave);
    enc.run(30, dex);          // Cave encounter
 
    dex.display();
}*/
