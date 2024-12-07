#ifndef CLIENT_H
#define CLIENT_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class client
{

    float total;
    int quantite, numvente;
    QString medicament;
    QDate datee;

public:

    client() {}
    client(float, int, int, QString, QDate);



    float getTotal() { return total; }
    int getQuantite() { return quantite; }
    int getNumvente() { return numvente; }
    QString getMedicament() { return medicament; }
    QDate getDate() { return datee; }


    void setTotal(float t) { total = t; }
    void setQuantite(int q) { quantite = q; }
    void setNumvente(int n) { numvente = n; }
    void setmedicament(QString m) { medicament = m; }
    void setDate(QDate d) { datee = d; }

    bool updateMedicationStock(const QString &medicament, int quantity);
    bool ajouter();
    QSqlQueryModel *displayClients();
    bool supprimer(int);
    bool modifier(int numvente);
    QSqlQueryModel *chercher(int numvente);
    QSqlQueryModel *trier();
    QMap<QString, int> getMedicamentStats();
    QMap<QString, int> calculateRestockingSuggestions(int threshold);
};
#endif // CLIENT_H
