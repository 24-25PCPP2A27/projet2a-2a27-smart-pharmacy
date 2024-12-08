#include "main_employes.h"
#include "ui_main_employes.h"
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts>
#include <QIntValidator>
#include<QMessageBox>
#include "employes.h"
#include <iostream>
#include <string>
#include<QPropertyAnimation>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include<QTextDocument>
#include<QtPrintSupport/QPrinter>
#include<QByteArray>
#include <QSqlQuery>
#include <QTime>
#include "ges_medicament.h" // Include the full definition of GesMedicament
#include "clientwindow.h"
#include "ui_clientwindow.h"
#include "gestion_fournisseur.h"
#include "ui_gestion_fournisseur.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    ui->tab_employes->setModel(SP.afficher());

    ui->lineEdit_salaire->setMaxLength(20);
    QValidator *validator = new QIntValidator(1, 99999999, this);
    ui->lineEdit_nomE->setMaxLength(30);
    ui->lineEdit_PrenomE->setMaxLength(30);
    ui->lineEdit_mail->setMaxLength(30);
    ui->lineEdit_ID->setValidator(validator);
    ui->lineEdit_id_sup->setValidator(validator);
    ui->lineEdit_recherche->setValidator(validator);
    ui->lineEdit_salaire->setMaxLength(20);

//ui->pb_pdf_2->setVisible(true);

    //animation
    animation= new QPropertyAnimation(ui->pb_supp, "geometry");
    animation->setDuration(2500);
    animation->setStartValue(QRect(800, 500, 150, 50));
    animation->setEndValue(QRect(ui->pb_supp->geometry()));

    animation->start();



    int ret=A.connect(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getPortName();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getPortName();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getSerial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données). // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
     connect(ui->pushButton_ToMedicament, &QPushButton::clicked, this, &MainWindow::goToMedicamentPage);


}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::goToMedicamentPage()
{
    GesMedicament *M = new GesMedicament(this);
    M->show();
    this->hide();
}
void MainWindow::on_pb_ajouter_clicked()
{

       QString nom_employes=ui->lineEdit_nomE->text();
       QString prenom_employes=ui->lineEdit_PrenomE->text();
       int ID=ui->lineEdit_ID->text().toInt();
       QString mail=ui->lineEdit_mail->text(); //mail
       int salaire=ui->lineEdit_salaire->text().toInt(); //salaire
       QString poste=ui->lineEdit_poste->text();//poste
       int hdt=ui->lineEdit_HDT->text().toInt(); //HDT

        QString idString = QString::number(ID);
        QString salaireString = QString::number(salaire);
        QString hdtString = QString::number(hdt);
    QString name = nom_employes;
    QRegExp regex("\\d");
       // Check if ID is valid (positive integer)
          if (ID <= 0) {
              QMessageBox::critical(nullptr, QObject::tr("Invalid ID"),
                                    QObject::tr("L'ID doit être un nombre entier positif."), QMessageBox::Ok);
              return; // Stop if invalid ID
          }else if (idString.isEmpty() || !idString.toInt()) {
              QMessageBox::critical(nullptr, QObject::tr("Invalid ID"),
                                    QObject::tr("L'ID doit être un nombre entier positif et non un caractère."), QMessageBox::Ok);
              return; // Stop if the ID is invalid
          }
          if (salaireString.isEmpty() || !salaireString.toInt()) {
                        QMessageBox::critical(nullptr, QObject::tr("Invalid salaire"),
                                              QObject::tr("Le salaire doit être un nombre entier positif et non un caractère."), QMessageBox::Ok);
                        return; // Stop if the ID is invalid
                    }
          if (hdtString.isEmpty() || !hdtString.toInt()) {
                        QMessageBox::critical(nullptr, QObject::tr("Invalid HDT"),
                                              QObject::tr("Le heure de travail doit être un nombre entier positif et non un caractère."), QMessageBox::Ok);
                        return; // Stop if the ID is invalid
                    }

          if (name.isEmpty() || regex.indexIn(name) != -1) {
              QMessageBox::critical(nullptr, QObject::tr("Invalid Name"),
                                    QObject::tr("Le nom ne doit pas contenir de chiffres ou vide."), QMessageBox::Ok);
              return; // Stop if the name is invalid
          }

          QRegExp emailRegex("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");
              if (mail.isEmpty()) {
                  QMessageBox::critical(nullptr, QObject::tr("Email vide"),
                                        QObject::tr("L'email ne peut pas être vide."), QMessageBox::Ok);
                  return; // Stop if email is empty
              } else if (!emailRegex.exactMatch(mail)) {
                  QMessageBox::critical(nullptr, QObject::tr("Email invalide"),
                                        QObject::tr("Veuillez entrer un email valide (exemple@example.com)."), QMessageBox::Ok);
                  return; // Stop if email format is invalid
              }
              if (nom_employes.isEmpty()) {
                  QMessageBox::critical(nullptr, QObject::tr("nom vide"),
                                        QObject::tr("Le nom ne peut pas être vide."), QMessageBox::Ok);
                  return; // Stop if nom is empty
              }
              if (prenom_employes.isEmpty()) {
                  QMessageBox::critical(nullptr, QObject::tr("Prenom vide"),
                                        QObject::tr("Le prenom ne peut pas être vide."), QMessageBox::Ok);
                  return; // Stop if prenom is empty
              }

              if (poste.isEmpty()) {
                  QMessageBox::critical(nullptr, QObject::tr("poste vide"),
                                        QObject::tr("Le poste ne peut pas être vide."), QMessageBox::Ok);
                  return; // Stop if poste is empty
              }





          {
          employes Sp(nom_employes,prenom_employes,ID,mail,salaire,poste,hdt);
          Sp.Ajouter();
          ui->tab_employes->setModel(SP.afficher());//refresh
          ui->lineEdit_ID->clear();
          ui->lineEdit_nomE->clear();
          ui->lineEdit_PrenomE->clear();
          ui->lineEdit_mail->clear();
          ui->lineEdit_salaire->clear();
          ui->lineEdit_HDT->clear();
          ui->lineEdit_poste->clear();




          }


}


void MainWindow::on_pb_supp_clicked()
{
    employes Sp;
    int ID = ui->lineEdit_id_sup->text().toInt();
    Sp.supprimer(ID);
    ui->tab_employes->setModel(SP.afficher());//refrech
}
void MainWindow::on_pb_modifier_clicked()
{
    QString NOM=ui->lineEdit_nomE->text();
    QString PRENOM=ui->lineEdit_PrenomE->text();
    int ID=ui->lineEdit_ID->text().toInt();
    QString MAIL=ui->lineEdit_mail->text(); //mail
    int SALAIRE=ui->lineEdit_salaire->text().toInt(); //salaire
    QString POSTE=ui->lineEdit_poste->text();//poste
    int HDT=ui->lineEdit_HDT->text().toInt(); //HDT
    QString idString = QString::number(ID);
    QString salaireString = QString::number(SALAIRE);
    QString hdtString = QString::number(HDT);

    employes Sp;
    Sp.modifier(NOM, PRENOM,ID, MAIL, SALAIRE, POSTE, HDT);
    ui->tab_employes->setModel(SP.afficher());//refrech
    ui->lineEdit_nomE->clear();
    ui->lineEdit_PrenomE->clear();
    ui->lineEdit_ID->clear();
    ui->lineEdit_mail->clear();
    ui->lineEdit_salaire->clear();
    ui->lineEdit_poste->clear();
    ui->lineEdit_HDT->clear();
}



void MainWindow::on_pb_recherche_clicked() {
    // Retrieve the ID from the search input field `lineEdit_recherche`
    int searchId = ui->lineEdit_recherche->text().toInt();

    // Call the `searchById` function of the `employes` class
    QSqlQueryModel *model = SP.search(searchId);

    // Set the model to the table view to display the results
    ui->tab_employes->setModel(model);

    // Optionally handle cases where no results are found
    if (model->rowCount() == 0) {
        QMessageBox::information(this, "Search", "No employee found with the given ID.");
    }else{
        A.sendData("1");


    }
}
void MainWindow::on_pb_trier_clicked() {
    QSqlQueryModel *model = SP.sortBySalaire();

    ui->tab_employes->setModel(model); // Set the model
    ui->tab_employes->reset();// Forces the view to refresh


    // Set the model to the table view with sorted data



    // Show a message box to inform the user
    QMessageBox::information(this, QObject::tr("Tri"),
                             QObject::tr("Les employés ont été triés par salaire."));
    A.sendData("1");
}
void MainWindow::on_pb_pdf_clicked() {
    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer en tant que PDF", QDir::homePath(), "PDF Files (*.pdf)");
    if (!filePath.isEmpty()) {
        if (!filePath.endsWith(".pdf", Qt::CaseInsensitive)) {
            filePath.append(".pdf");  // Add .pdf extension if missing
        }
        if (SP.exportToPDF(filePath)) {
            QMessageBox::information(this, QObject::tr("Export PDF"),
                                     QObject::tr("Données exportées avec succès en PDF."));
        } else {
            QMessageBox::critical(this, QObject::tr("Erreur d'export PDF"),
                                   QObject::tr("Échec de l'exportation des données en PDF."));
        }
    }
}

void MainWindow::on_pb_showStatsButton_clicked()
{       // Add a stacked widget in your UI file and access it via ui->stackedWidget

    // Create an instance of Employe class
    employes employe;

    // Call the function to generate the pie chart
    employe.statistique();
}
void MainWindow::on_pb_qr_clicked()
{
    QRCodeDialog dialog(this);  // Create an instance of the dialog
    dialog.setWindowTitle("Generate Employee QR Code");
    dialog.exec();  // Show the dialog
}


void MainWindow::on_Ard_button_clicked()
{
     A.sendData("1");
}

void MainWindow::on_pushButton_5_clicked()
{
    clientwindow *E = new clientwindow(this);
    E->show();
    this->hide();
}

void MainWindow::on_pushButton_6_clicked()
{
    gestfour *Me = new gestfour(this);
    Me->show();
    this->hide();
}
