#include "pagem.h"
#include "ui_pagem.h"
#include "email.h"
#include <QMessageBox>

pageM::pageM(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::pageM)
{
    ui->setupUi(this);
}

pageM::~pageM()
{
    delete ui;
}

void pageM::on_mailing_clicked()
{
    QString destinataire = ui->destinataireEmail->text();
    QString objet = ui->objetEmail->text();
    QString corps = ui->bodyEmail->text();

    // Vérification de la validité des champs
    if (destinataire.isEmpty() || objet.isEmpty() || corps.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis avant d'envoyer l'email.");
        return;
    }

    // Appel de la fonction d'envoi d'email
    mailer::sendEmail(destinataire, objet, corps);

    // Supposons que l'envoi est réussi
    QMessageBox::information(this, "Succès", "Email envoyé avec succès.");

    // Vider les champs
    ui->destinataireEmail->clear();
    ui->objetEmail->clear();
    ui->bodyEmail->clear();
}

