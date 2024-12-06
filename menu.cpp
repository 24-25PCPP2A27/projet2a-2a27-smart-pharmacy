#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    uis(new Ui::Menu)
{
    uis->setupUi(this);
}

Menu::~Menu()
{
    delete uis;
}

void Menu::on_Employe_clicked()
{
    currentpage = 1;
    emit pageChanged(currentpage);
}

void Menu::on_Medicament_clicked()
{
    currentpage = 2;
    emit pageChanged(currentpage);
}

void Menu::on_Client_clicked()
{
    currentpage = 3;
    emit pageChanged(currentpage);
}

void Menu::on_Fournisseur_clicked()
{
    currentpage = 4;
    emit pageChanged(currentpage);
}
