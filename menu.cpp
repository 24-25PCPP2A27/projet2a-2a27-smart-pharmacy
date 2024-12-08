#include "menu.h"
#include "ui_menu.h"
#include "ges_medicament.h"
#include "main_employes.h"
#include"ui_ges_medicament.h"
#include"ui_main_employes.h"
#include "clientwindow.h"
#include "ui_clientwindow.h"

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
    MainWindow *E = new MainWindow(this);
    E->show();
    this->hide();
}

void Menu::on_Medicament_clicked()
{
    GesMedicament *E = new GesMedicament(this);
    E->show();
    this->hide();
}

void Menu::on_Client_clicked()
{
    clientwindow *E = new clientwindow(this);
    E->show();
    this->hide();
}

void Menu::on_Fournisseur_clicked()
{
    currentpage = 4;
    emit pageChanged(currentpage);
}
