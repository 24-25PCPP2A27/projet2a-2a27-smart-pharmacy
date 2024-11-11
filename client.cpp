#include "client.h"
#include <QtDebug>
#include <QSqlError>

client::client(int total, int quantite, int numvente, QString medicament, QDate datee) {
    this->total = total;
    this->quantite = quantite;
    this->numvente = numvente;
    this->medicament = medicament;
    this->datee = datee;
}

bool client::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO client (numvente, quantite, total, medicament,datee) "
                  "VALUES (:total, :quantite, :numvente, :medicament, :datee)");
    query.bindValue(":numvente", numvente);
    query.bindValue(":quantite", quantite);
    query.bindValue(":total", total);
    query.bindValue(":medicament", medicament);
    query.bindValue(":datee", datee);

    return query.exec();
}

QSqlQueryModel* client::displayClients() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM client");

    // Set header data for better readability in the UI
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Total"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantite"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Numvente"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Medicament"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("datee"));

    return model;
}

bool client::supprimer(int numvente) {
    QSqlQuery query;
    query.prepare("DELETE FROM client WHERE numvente = :numvente");
    query.bindValue(":numvente", numvente);

    return query.exec();
}



bool client::modifier(int numvente) {
    QSqlQuery query;
    query.prepare("UPDATE clients SET numvente = :numvente, quantite = :quantite, "
                  "total = :total, medicament = :medicament, datee = :datee WHERE numvente = :numvente");
    query.bindValue(":numvente", numvente);
    query.bindValue(":quantite", quantite);
    query.bindValue(":total", total);
    query.bindValue(":medicament", medicament);
    query.bindValue(":datee", datee);

    if (!query.exec()) {
        qDebug() << "Update error:" << query.lastError().text(); // This will log any SQL errors
        return false;
    }
    return true;
}
/*
QSqlQueryModel* client::chercher(int numvente) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM clients WHERE numvente = :numvente");
    query.bindValue(":numvente", numvente);

    if (!query.exec()) {
        qDebug() << "Search error:" << query.lastError().text();
    } else {
        model->setQuery(query);
    }

    // Set headers (modify these to match your columns)
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num Vente"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Quantité"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Total"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Medicament"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date"));

    return model;
}
*/

