#include "fournisseur.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QByteArray>
#include <map>
#include <QSqlRecord>
#include <QFile>

// Constructor without status
Fournisseur::Fournisseur()
{
    ID = 0;
    nom_fournisseur = "";
    adresse = "";
    tlf = 0;
    status = "";  // Initialize status as an empty string
}

// Constructor with status
Fournisseur::Fournisseur(int ID, QString nom_fournisseur, QString adresse, int tlf, QString status)
{
    this->ID = ID;
    this->nom_fournisseur = nom_fournisseur;
    this->adresse = adresse;
    this->tlf = tlf;
    this->status = status;  // Set the status
}

// Getters
int Fournisseur::get_ID()
{
    return ID;
}

QString Fournisseur::get_Nom()
{
    return nom_fournisseur;
}

QString Fournisseur::get_adresse()
{
    return adresse;
}

int Fournisseur::get_tlf()
{
    return tlf;
}

QString Fournisseur::get_status()
{
    return status;  // Return the status
}

// Setters
void Fournisseur::set_ID(int ID)
{
    this->ID = ID;
}

void Fournisseur::set_Nom(QString nom_fournisseur)
{
    this->nom_fournisseur = nom_fournisseur;
}

void Fournisseur::set_adresse(QString adresse)
{
    this->adresse = adresse;
}

void Fournisseur::set_tlf(int tlf)
{
    this->tlf = tlf;
}

void Fournisseur::set_status(QString status)
{
    this->status = status;  // Set the status
}

// Method to add a new Fournisseur with status
bool Fournisseur::Ajouter()
{
    QSqlQuery query;
    QString id_string = QString::number(ID);

    query.prepare("INSERT INTO Fournisseur(ID, nom_fournisseur, adresse, tlf, status) "
                  "VALUES (:ID, :nom_fournisseur, :adresse, :tlf, :status)");
    query.bindValue(":ID", id_string);
    query.bindValue(":nom_fournisseur", nom_fournisseur);
    query.bindValue(":adresse", adresse);
    query.bindValue(":tlf", tlf);
    query.bindValue(":status", status);  // Bind the status value

    return query.exec();
}

// Method to modify an existing Fournisseur with status
bool Fournisseur::modifier()
{
    QSqlQuery query;
    QString id_string = QString::number(ID);
    query.prepare("UPDATE Fournisseur SET ID = :ID, nom_fournisseur = :nom_fournisseur, adresse = :adresse, tlf = :tlf, status = :status WHERE ID = :ID");
    query.bindValue(":ID", id_string);
    query.bindValue(":nom_fournisseur", nom_fournisseur);
    query.bindValue(":adresse", adresse);
    query.bindValue(":tlf", tlf);
    query.bindValue(":status", status);  // Bind the status value

    return query.exec();
}

// Method to display all Fournisseurs (including status)
QSqlQueryModel* Fournisseur::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM Fournisseur");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Fournisseur"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Status"));  // Add header for status

    return model;
}

// Method to delete a Fournisseur
bool Fournisseur::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Fournisseur WHERE ID = :id");
    query.bindValue(":id", id);

    return query.exec();
}

// Method to search a Fournisseur by ID
bool Fournisseur::RechercheFournisseurParID(int IDrecherche)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Fournisseur WHERE ID = :IDrecherche");
    query.bindValue(":IDrecherche", IDrecherche);
    query.exec();

    if (!query.first()) {
        return false;
    } else {
        int nID = query.record().indexOf("ID");
        int nNom = query.record().indexOf("nom_fournisseur");
        int nMail = query.record().indexOf("adresse");
        int nTlf = query.record().indexOf("tlf");
        int nStatus = query.record().indexOf("status");  // Index for the status column

        ID = query.value(nID).toInt();
        nom_fournisseur = query.value(nNom).toString();
        adresse = query.value(nMail).toString();
        tlf = query.value(nTlf).toInt();
        status = query.value(nStatus).toString();  // Retrieve the status

        return true;
    }
}

// Sorting Fournisseurs by ID
QSqlQueryModel* Fournisseur::tri_ID()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery *q = new QSqlQuery();
    q->prepare("SELECT * FROM Fournisseur ORDER BY ID ASC");
    q->exec();
    model->setQuery(*q);

    return model;
}

// Sorting Fournisseurs by Name
QSqlQueryModel* Fournisseur::tri_nom()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery *q = new QSqlQuery();
    q->prepare("SELECT * FROM Fournisseur ORDER BY nom_fournisseur ASC");
    q->exec();
    model->setQuery(*q);

    return model;
}

