#include "ges_medicament.h"
#include "ui_ges_medicament.h"
#include "medicament.h"
#include "connection.h"
#include <QMessageBox>

GesMedicament::GesMedicament(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::Ges_Medicament)
{
    ui->setupUi(this);
    ui->tableView->setModel(Mtmp.afficher());
}

GesMedicament::~GesMedicament()
{
    delete ui;
}

void GesMedicament::on_pushButton_A_clicked()
{
    int idm = ui->lineEdit_IDM_A->text().toInt();
    QString libelle = ui->lineEdit_Libelle_A->text();
    int quantite = ui->lineEdit_Quantite_A->text().toInt();
    double prix = ui->lineEdit_Prix_A->text().toDouble();

    Medicament M(idm, libelle, quantite, prix);

    if (M.ajouter())
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Ajout effectué\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(Mtmp.afficher());  // Refresh the table view
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Ajout non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void GesMedicament::on_pushButton_U_clicked()
{
    int idm = ui->lineEdit_IDM_U->text().toInt();
    QString libelle = ui->lineEdit_Libell_U->text();
    int quantite = ui->lineEdit_Quantite_U->text().toInt();
    double prix = ui->lineEdit_Prix_U->text().toDouble();

    Medicament M(idm, libelle, quantite, prix);

    if (M.modifier())
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Modification effectuée\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(Mtmp.afficher());  // Refresh the table view
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Modification non effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void GesMedicament::on_pushButton_D_clicked()
{
    int idm = ui->lineEdit_IDM_D->text().toInt();
    if (Mtmp.supprimer(idm))
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Suppression effectuée\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(Mtmp.afficher());  // Refresh the table view
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Suppression non effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}
