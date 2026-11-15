#include "pokedexwindow.h"
#include "ui_pokedexwindow.h"
#include <map>
#include <string>

PokedexWindow::PokedexWindow(const Pokedex& pokedex, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PokedexWindow)
{
    ui->setupUi(this);

    // Count how many of each Pokemon name were caught
    std::map<std::string, int> counts;
    for (const Pokemon& p : pokedex.getCaught()) {
        counts[p.getName()] += 1;
    }

    // Fill the list
    if (counts.empty()) {
        ui->pokedexList->addItem("No Pokemon caught yet.");
    }
    for (const auto& entry : counts) {
        QString line = QString::fromStdString(entry.first)
                       + " - caught: " + QString::number(entry.second);
        ui->pokedexList->addItem(line);
    }

    connect(ui->backButton, &QPushButton::clicked, this, &QDialog::accept);
}

PokedexWindow::~PokedexWindow()
{
    delete ui;
}
