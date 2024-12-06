#include "medicament.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
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
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT QUANTITE_EN_STOCK FROM MEDICAMENT WHERE IDM = :IDM");
    checkQuery.bindValue(":IDM", idm);

    QSqlQuery query;
    query.prepare("UPDATE MEDICAMENT SET LIBELLE = :LIBELLE, QUANTITE_EN_STOCK = :QUANTITE_EN_STOCK, PRIX = :PRIX "
                  "WHERE IDM = :IDM");
    query.bindValue(":IDM", idm);
    query.bindValue(":LIBELLE", libelle);
    query.bindValue(":QUANTITE_EN_STOCK", quantite_en_stock);
    query.bindValue(":PRIX", prix);

    bool result = query.exec();
    return result;
}



QSqlQueryModel* Medicament::afficherParQuantite(bool ascending)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString queryStr = ascending
            ? "SELECT * FROM MEDICAMENT ORDER BY QUANTITE_EN_STOCK ASC"
            : "SELECT * FROM MEDICAMENT ORDER BY QUANTITE_EN_STOCK DESC";

        model->setQuery(queryStr);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDM"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Libelle"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantite en Stock"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
        return model;
}

QSqlQueryModel* Medicament::rechercherParLibelle(const QString &libelle)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM MEDICAMENT WHERE LIBELLE LIKE :libelle");
    query.bindValue(":libelle", "%" + libelle + "%");  // Use wildcards for partial match
    query.exec();

    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Libelle"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Quantite en Stock"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));

    return model;
}

// Email Sending Function
bool sendEmail(const QString &toEmail, const QString &subject, const QString &body) {
    // Configure the network manager
    QNetworkAccessManager *manager = new QNetworkAccessManager();

    // Set up the API endpoint and request headers
    QUrl apiEndpoint("https://api.sendgrid.com/v3/mail/send");
    QNetworkRequest request(apiEndpoint);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", "Bearer CTFE7HUJ3SKXYFPM8NNW7NGV"); // Replace with your API Key

    // Create the JSON payload
    QJsonObject emailData;
    QJsonObject fromObject;
    QJsonObject toObject;
    QJsonArray toArray;
    QJsonObject contentObject;
    QJsonArray contentArray;

    fromObject["email"] = "azizgarwachi0@gmail.com";
    toObject["email"] = toEmail;
    toArray.append(toObject);

    contentObject["type"] = "text/plain";
    contentObject["value"] = body;
    contentArray.append(contentObject);

    emailData["personalizations"] = QJsonArray{
        QJsonObject{
            {"to", toArray}
        }
    };
    emailData["from"] = fromObject;
    emailData["subject"] = subject;
    emailData["content"] = contentArray;

    // Make the POST request
    QNetworkReply *reply = manager->post(request, QJsonDocument(emailData).toJson());

    // Handle the reply asynchronously
    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "Email sent successfully.";
        } else {
            qDebug() << "Failed to send email:" << reply->errorString();
        }
        reply->deleteLater();
    });

    return true; // Return true to indicate the function ran; actual success is determined in the callback.
}
