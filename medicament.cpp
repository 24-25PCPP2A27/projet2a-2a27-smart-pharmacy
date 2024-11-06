#include "medicament.h"

Medicament::Medicament() : idm(0), libelle(""), quantite_en_stock(0), prix(0.0)
{}

Medicament::Medicament(int id, QString lib, int quantite, double pr)
    : idm(id), libelle(lib), quantite_en_stock(quantite), prix(pr)
{}

bool Medicament::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO MEDICAMENT (IDM, LIBELLE, QUANTITE_EN_STOCK, PRIX) "
                  "VALUES (:IDM, :LIBELLE, :QUANTITE_EN_STOCK, :PRIX)");
    query.bindValue(":IDM", QString::number(idm));
    query.bindValue(":LIBELLE", libelle);
    query.bindValue(":QUANTITE_EN_STOCK", quantite_en_stock);
    query.bindValue(":PRIX", prix);
    return query.exec();
}

QSqlQueryModel * Medicament::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM MEDICAMENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Libelle"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantite en Stock"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
    return model;
}

bool Medicament::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM MEDICAMENT WHERE IDM = :IDM");
    query.bindValue(":IDM", QString::number(id));
    return query.exec();
}

bool Medicament::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE MEDICAMENT SET LIBELLE = :LIBELLE, QUANTITE_EN_STOCK = :QUANTITE_EN_STOCK, PRIX = :PRIX "
                  "WHERE IDM = :IDM");
    query.bindValue(":IDM", QString::number(idm));
    query.bindValue(":LIBELLE", libelle);
    query.bindValue(":QUANTITE_EN_STOCK", quantite_en_stock);
    query.bindValue(":PRIX", prix);
    return query.exec();
}
