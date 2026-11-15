#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Encounter.h"
#include "Pokedex.h"
#include "Region.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;

    Forest forest;
    Cave cave;
    Pokedex pokedex;
    Encounter encounter;

    Region* selectedRegion = nullptr;
};

#endif // MAINWINDOW_H
