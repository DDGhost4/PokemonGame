#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "RegionDialog.h" //region button dialog
#include "pokedexwindow.h"
#include <QMessageBox>
#include <QFile>
#include <stdexcept>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , encounter(nullptr)
{
    ui->setupUi(this);

    //PERSISTENCE: load pokedex from file if it exists, if not we start with empty pokedex
    if (QFile::exists("pokedex_save.txt")) {
        try {
            pokedex.load("pokedex_save.txt");
        }
        catch (const std::exception& e) {
            QMessageBox::warning(this, "Load failed",
                                 QString("%1\nStarting with an empty Pokedex.").arg(e.what()));
        }
    }


    ui->statusbar->showMessage("Choose a region to explore.");

    // A region cannot be changed while its wild Pokemon encounter is active.
    connect(ui->Region_Button, &QPushButton::clicked, this, [this]() {
        if (encounter.isActive()) {
            QMessageBox::warning(this, "Encounter in progress",
                                 "Catch the Pokemon or run away before changing regions.");
            return;
        }

        RegionDialog dialog(this);
        if (dialog.exec() != QDialog::Accepted) {
            return;
        }

        if (dialog.chosen == 1) {
            selectedRegion = &forest;
            encounter.setRegion(selectedRegion);
            ui->statusbar->showMessage("Selected Forest. Press Explore to look for Pokemon.");
        } else if (dialog.chosen == 2) {
            selectedRegion = &cave;
            encounter.setRegion(selectedRegion);
            ui->statusbar->showMessage("Selected Cave. Press Explore to look for Pokemon.");
        }
    });

    // The Pokedex button opens a dialog showing the Pokemon that have been caught.
    connect(ui->Pokedex_Button, &QPushButton::clicked, this, [this]() {
        PokedexWindow dialog(pokedex, this);
        dialog.exec();
    });


    // Exploring starts an encounter, or reopens the current one after a failed catch.
    connect(ui->Explore_Button, &QPushButton::clicked, this, [this]() {
        try {
            if (!encounter.isActive()) {
                encounter.start();   //throws logic_error if no region is selected
            }
        }
        catch (const std::logic_error& e) {
            QMessageBox::warning(this, "Explore failure message", e.what());
            return;
        }

        const Pokemon* wildPokemon = encounter.getWildPokemon();
        const Region* encounterRegion = encounter.getRegion();
        if (wildPokemon == nullptr || encounterRegion == nullptr) {
            QMessageBox::warning(this, "Encounter error",
                                 "The active encounter is missing its Pokemon or region.");
            return;
        }

        const QString species = QString::fromStdString(wildPokemon->getName());
        const QString regionName = QString::fromStdString(encounterRegion->getName());
        QMessageBox prompt(this);
        prompt.setWindowTitle("Wild Pokemon encounter");
        prompt.setText(QString("A wild %1 appeared in the %2!").arg(species, regionName));
        QPushButton* catchButton = prompt.addButton("Throw Pokeball", QMessageBox::AcceptRole);
        QPushButton* runButton = prompt.addButton("Run away", QMessageBox::RejectRole);
        prompt.exec();

        if (prompt.clickedButton() == catchButton) {
            switch (encounter.attemptCatch(pokedex)) {
            case CatchResult::Caught:
                //persistence: saves pokedex to file after successful catch
                if (!pokedex.save("pokedex_save.txt")) {
                    QMessageBox::warning(this, "Save failed",
                                         "Could not save your Pokedex.");
                }
                //button message and dialog message for successful catch
                ui->statusbar->showMessage(QString("Caught %1!").arg(species));
                QMessageBox::information(this, "Pokemon caught",
                                         QString("You caught %1!").arg(species));
                break;
                
            case CatchResult::Failed:
                ui->statusbar->showMessage(QString("%1 broke free. The encounter is still active.").arg(species));
                QMessageBox::information(this, "Pokemon escaped the Pokeball",
                                         QString("%1 broke free. Press Explore to try again or run away.").arg(species));
                break;
            case CatchResult::NoActiveEncounter:
                QMessageBox::warning(this, "No active encounter",
                                     "There is no Pokemon to catch right now.");
                break;
            }
        } else if (prompt.clickedButton() == runButton) {
            encounter.flee();
            ui->statusbar->showMessage(QString("You left the %1 encounter.").arg(regionName));
        } else {
            ui->statusbar->showMessage(QString("The encounter with %1 is still active. Press Explore to return.").arg(species));
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}