#include "login.h"
#include "ui_login.h"
#include "main_fournisseur.h"
#include "fournisseur.h"
#include <QMessageBox>
#include <QDialog>
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}
void login::on_pushButton_login_clicked()
{

/*
    QString username = ui->nom_login->text();
    QString password = ui->mdp_login->text();
    if(username=="ahmed"&&password=="123") //if(qry.exec( "select * from compte where NOM='"+username +"' PRENOM='"+password +"'")!=true)
    {
        test=true;
        QMessageBox::information(this,"login","nom et prenom valider");
        this->hide();
        MainWindow w;
        w.setModal(true);
        w.exec();


    }
    else
    {
        QMessageBox::information(this,"login","nom et prenom non valider");
    }

    return test;
    */
    close();
            MainWindow *g = new MainWindow();
            g->setWindowTitle("my workspace");
            g->show();

}
