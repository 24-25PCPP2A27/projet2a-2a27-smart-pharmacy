#ifndef CLIENT_H
#define CLIENT_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class client
{

    int total,quantite, numvente;
    QString medicament;
    QDate datee;

public:

    client() {}
    client(int, int, int, QString, QDate);



    int getTotal() { return total; }
    int getQuantite() { return quantite; }
    int getNumvente() { return numvente; }
    QString getMedicament() { return medicament; }
    QDate getDate() { return datee; }


    void setTotal(int t) { total = t; }
    void setQuantite(int q) { quantite = q; }
    void setNumvente(int n) { numvente = n; }
    void setmedicament(QString m) { medicament = m; }
    void setDate(QDate d) { datee = d; }


    bool ajouter();
    QSqlQueryModel *displayClients();
    bool supprimer(int);
    bool modifier(int numvente);
    //bool chercher(int numvente);
};
#endif // CLIENT_H
