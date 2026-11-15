/********************************************************************************
** Form generated from reading UI file 'pokedexwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POKEDEXWINDOW_H
#define UI_POKEDEXWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PokedexWindow
{
public:
    QLabel *titleLabel;
    QListWidget *pokedexList;
    QPushButton *backButton;

    void setupUi(QDialog *PokedexWindow)
    {
        if (PokedexWindow->objectName().isEmpty())
            PokedexWindow->setObjectName("PokedexWindow");
        PokedexWindow->resize(400, 300);
        titleLabel = new QLabel(PokedexWindow);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(160, 10, 71, 30));
        pokedexList = new QListWidget(PokedexWindow);
        pokedexList->setObjectName("pokedexList");
        pokedexList->setGeometry(QRect(20, 55, 360, 185));
        backButton = new QPushButton(PokedexWindow);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(280, 250, 100, 32));

        retranslateUi(PokedexWindow);

        QMetaObject::connectSlotsByName(PokedexWindow);
    } // setupUi

    void retranslateUi(QDialog *PokedexWindow)
    {
        PokedexWindow->setWindowTitle(QCoreApplication::translate("PokedexWindow", "Pokedex", nullptr));
        titleLabel->setText(QCoreApplication::translate("PokedexWindow", "POKEDEX:", nullptr));
        backButton->setText(QCoreApplication::translate("PokedexWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PokedexWindow: public Ui_PokedexWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POKEDEXWINDOW_H
