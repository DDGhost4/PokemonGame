#ifndef REGIONDIALOG_H
#define REGIONDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

// Small window with a button 1 and a button 2
class RegionDialog : public QDialog
{
public:
    int chosen = 0;   // 0 = nothing picked, 1 = region 1, 2 = region 2

    RegionDialog(QWidget *parent = nullptr) : QDialog(parent)
    {
        setWindowTitle("Region Selection");

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(new QLabel("Choose a region:"));

        QPushButton *button1 = new QPushButton("1");
        QPushButton *button2 = new QPushButton("2");
        layout->addWidget(button1);
        layout->addWidget(button2);

        connect(button1, &QPushButton::clicked, this, [this]() {
            chosen = 1;
            accept();   // closes this window
        });
        connect(button2, &QPushButton::clicked, this, [this]() {
            chosen = 2;
            accept();
        });
    }
};

#endif
