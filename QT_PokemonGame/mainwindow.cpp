#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "RegionDialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // region button open the selection window, then come back here
    connect(ui->Region_Button, &QPushButton::clicked, this, [this]() {
        RegionDialog dialog(this);
        dialog.exec();   // waits until the selection window closes

        if (dialog.chosen == 1) {
            selectedRegion = &forest;
            ui->statusbar->showMessage("Selected Region 1");
        } else if (dialog.chosen == 2) {
            selectedRegion = &cave;
            ui->statusbar->showMessage("Selected Region 2");
        }
    });

    // input validation demo (success or failure)
    connect(ui->Explore_Button, &QPushButton::clicked, this, [this]() {
        if (selectedRegion == nullptr) {
            QMessageBox::warning(this, "Explore failure message",
                                 "Choose a region before exploring.");
        } else {
            QMessageBox::information(this, "Explore success message",
                                     "You explored Region");
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}