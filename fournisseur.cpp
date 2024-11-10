#include "fournisseur.h"
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
#include <QByteArray>
#include<map>
#include<QSqlRecord>
#include <QFile>

Fournisseur::Fournisseur()
{
     ID=0;
     nom_fournisseur="";
     adresse="";
     tlf=0;

}
Fournisseur::Fournisseur(int ID,QString nom_fournisseur,QString adresse,int tlf)
{
    this->ID=ID;
    this->nom_fournisseur=nom_fournisseur;
    this->adresse=adresse;
    this->tlf=tlf;

}
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

void Fournisseur::set_ID(int ID)
{
    this->ID=ID;
}
void Fournisseur::set_Nom(QString nom_fournisseur)
{
    this->nom_fournisseur=nom_fournisseur;
}
void Fournisseur::set_adresse(QString adresse)
{
    this->adresse=adresse;
}
void Fournisseur::set_tlf(int tlf)
{
    this->tlf=tlf;
}

bool Fournisseur::Ajouter()
{

    QSqlQuery query;
    QString id_string= QString::number(ID);

          query.prepare("INSERT INTO Fournisseur(ID, nom_fournisseur, adresse, tlf )"
                        "VALUES (:ID, :nom_fournisseur,  :adresse, :tlf)");
          query.bindValue(":ID", id_string);
          query.bindValue(":nom_fournisseur", nom_fournisseur);
          query.bindValue(":adresse", adresse);
          query.bindValue(":tlf", tlf);


         return query.exec();
}


bool Fournisseur::modifier(){
    QSqlQuery query;
    QString id_string= QString::number(ID);
    query.prepare("UPDATE Fournisseur SET ID= :ID, nom_fournisseur= :nom_fournisseur, adresse= :adresse, tlf= :tlf WHERE ID= :ID");
    query.bindValue(":ID",id_string);
    query.bindValue(":nom_fournisseur",nom_fournisseur);
    query.bindValue(":adresse",adresse);
    query.bindValue(":tlf",tlf);

    return query.exec();
}

QSqlQueryModel* Fournisseur::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT * FROM Fournisseur");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_fournisseur"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse_Mail"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("N°Téléphone"));



    return model;
}

bool Fournisseur::supprimer(int id)
{
    QSqlQuery query;

          query.prepare(" Delete from Fournisseur where id=:id");
          query.bindValue(0,id);

         return query.exec();
}

bool Fournisseur::RechercheFournisseurParID(int IDrecherche)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM Fournisseur WHERE id=:IDrecherche");
    query.bindValue(":IDrecherche",IDrecherche);
    query.exec();
    if (!query.first()){
        return false;
    }
    else
    {
        int nID = query.record().indexOf("ID");
        int nNom=query.record().indexOf("nom_fournisseur");
        int nMail=query.record().indexOf("adresse");
        int nTlf=query.record().indexOf("tlf");


        ID=query.value(nID).toInt();
        nom_fournisseur=query.value(nNom).toString();
        adresse=query.value(nMail).toString();
        tlf=query.value(nTlf).toInt();

        return true;
    }

}

QSqlQueryModel * Fournisseur::tri_ID()
{
    QSqlQueryModel *model= new QSqlQueryModel;
    QSqlQuery *q=new QSqlQuery();
    q->prepare("select * from Fournisseur order by id  asc");
    q->exec();
    model->setQuery(*q);
    return  model;
}

QSqlQueryModel * Fournisseur::tri_nom()
{
    QSqlQueryModel *model= new QSqlQueryModel;
    QSqlQuery *q=new QSqlQuery();
    q->prepare("select * from Fournisseur order by nom_fournisseur  asc");
    q->exec();
    model->setQuery(*q);
    return  model;
}
