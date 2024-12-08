#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QString>
#include <QSqlQueryModel>
#include <QImage>

class Fournisseur
{
public:
    // Constructors
    Fournisseur();
    Fournisseur(int, QString, QString, int, QString);  // Add status parameter to constructor

    // Getters
    int get_ID();
    QString get_Nom();
    int get_tlf();
    QString get_adresse();
    QString get_status();  // Getter for status

    // Setters
    void set_ID(int);
    void set_Nom(QString);
    void set_adresse(QString);
    void set_tlf(int);
    void set_status(QString);  // Setter for status

    // Database operations
    bool Ajouter();
    bool modifier();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool RechercheFournisseurParID(int IDrecherche);
    QSqlQueryModel *tri_ID();
    QSqlQueryModel *tri_nom();

private:
    int ID;
    QString nom_fournisseur;
    QString adresse;
    int tlf;
    QString status;  // New attribute for status
};

#endif // FOURNISSEUR_H
