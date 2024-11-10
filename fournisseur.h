#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQueryModel>
#include <QImage>



class Fournisseur
{
public:
    Fournisseur();
    Fournisseur(int,QString,QString,int);
    int get_ID();
    QString get_Nom();
    int get_tlf();
    QString get_adresse();
    void set_ID(int);
    void set_Nom(QString);
    void set_adresse(QString);
    void set_tlf(int);
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

};

#endif // FOURNISSEUR_H
