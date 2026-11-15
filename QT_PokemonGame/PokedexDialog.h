#ifndef POKEDEXDIALOG_H
#define POKEDEXDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

// Separate window for the Pokedex
class PokedexDialog : public QDialog
{
public:
    PokedexDialog(QWidget *parent = nullptr) : QDialog(parent)
    {
        setWindowTitle("Pokedex");
        resize(300, 250);

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(new QLabel("Pokedex"));
        layout->addWidget(new QLabel("No Pokemon have beencaught yet."));

        QPushButton *closeButton = new QPushButton("Back");
        layout->addWidget(closeButton);

        connect(closeButton, &QPushButton::clicked, this, [this]() {
            accept();   // closes this window
        });
    }
};

#endif
