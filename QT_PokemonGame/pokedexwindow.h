#ifndef POKEDEXWINDOW_H
#define POKEDEXWINDOW_H

#include <QDialog>
#include "Pokedex.h"

namespace Ui {
class PokedexWindow;
}

class PokedexWindow : public QDialog
{
    Q_OBJECT

public:
    PokedexWindow(const Pokedex& pokedex, QWidget *parent = nullptr);
    ~PokedexWindow();

private:
    Ui::PokedexWindow *ui;
};

#endif // POKEDEXWINDOW_H
