#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include <QTimer>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Medicament
{
private:
    int idm;
    QString libelle;
    int quantite_en_stock;
    double prix;

public:
    Medicament();
    Medicament(int, QString, int, double);

    int getIDM() const { return idm; }
    QString getLibelle() const { return libelle; }
    int getQuantiteEnStock() const { return quantite_en_stock; }
    double getPrix() const { return prix; }

    void setIDM(int id) { idm = id; }
    void setLibelle(const QString &lib) { libelle = lib; }
    void setQuantiteEnStock(int qty) { quantite_en_stock = qty; }
    void setPrix(double pr) { prix = pr; }

    bool ajouter();
    QSqlQueryModel* afficher();
    void refreshModel();
    bool supprimer(int);
    bool modifier();
};

#endif
