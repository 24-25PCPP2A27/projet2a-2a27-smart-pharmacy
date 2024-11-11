#include "clientwindow.h"
#include "ui_clientwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QtDebug>
clientwindow::clientwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    displayClients();
}

clientwindow::~clientwindow()
{
    delete ui;
}

void clientwindow::on_pushButton_onAddClients_clicked() {

    qDebug() << "Ajouter button clicked.";

    // Retrieve inputs from the UI
    QString totalText = ui->totalLineEdit->text();
    QString quantiteText = ui->quantiteLineEdit->text();
    QString numventeText = ui->numventeLineEdit->text();
    QString medicament = ui->medicamentLineEdit->text();
    QDate date = ui->dateEdit->date();


    if (totalText.isEmpty() || quantiteText.isEmpty() || numventeText.isEmpty() || medicament.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
        qDebug() << "Empty field detected.";
        return;
    }


    bool totalIsInt, quantiteIsInt, numventeIsInt;
    int total = totalText.toInt(&totalIsInt);
    int quantite = quantiteText.toInt(&quantiteIsInt);
    int numvente = numventeText.toInt(&numventeIsInt);

    if (!totalIsInt || !quantiteIsInt || !numventeIsInt) {
        QMessageBox::warning(this, "Input Error", "Total, Quantite, and Numvente must be digits.");
        return;
    }



    if (!date.isValid()) {
        QMessageBox::warning(this, "Input Error", "Please provide a valid date.");
        return;
    }


    client newClient(total, quantite, numvente, medicament, date);

    if (newClient.ajouter()) {
        QMessageBox::information(this, "Success", "Client added successfully.");
        displayClients(); // Refresh displayed clients
    } else {
        QMessageBox::warning(this, "Error", "Failed to add client.");
    }

    qDebug() << "Input validation completed.";
}


void clientwindow::on_suppButton_clicked() {
    int numvente = ui->supplineEdit->text().toInt();
    bool test = cl.supprimer(numvente);
    if (test) {
        QMessageBox::information(this, "Success", "Client deleted successfully.");
        displayClients(); // Refresh the displayed clients
    } else {
        QMessageBox::warning(this, "Error", "Failed to delete client.");
    }
}

void clientwindow::on_pushButton_onUpdateClients_clicked() {
    // Get values from UI fields in the update tab
    int numvente = ui->numventeUpdate->text().toInt();
    int quantite = ui->quantiteUpdate->text().toInt();
    int total = ui->totalUpdate->text().toInt();
    QString medicament = ui->medicamentUpdate->text();
    QDate datee = ui->dateUpdate->date();

    // Create a client object and set the new values
    client cl;
    cl.setNumvente(numvente);
    cl.setQuantite(quantite);
    cl.setTotal(total);
    cl.setmedicament(medicament);
    cl.setDate(datee);

    // Attempt the update and provide feedback
    if (cl.modifier(numvente)) {
        QMessageBox::information(this, "Success", "Client updated successfully.");
        displayClients(); // Refresh client list
    } else {
        QMessageBox::warning(this, "Error", "Failed to update client.");
    }

    qDebug() << "numvente:" << numvente
             << "quantite:" << quantite
             << "total:" << total
             << "medicament:" << medicament
             << "date:" << datee;

}


void clientwindow::displayClients() {
    ui->tableWidget->clearContents(); // Clears only the data, keeping headers intact
    ui->tableWidget->setRowCount(0); // Reset row count for fresh data

    client c;
    QSqlQueryModel* model = c.displayClients();

    // Set the number of rows and columns
    int rowCount = model->rowCount();
    int columnCount = model->columnCount();
    ui->tableWidget->setRowCount(rowCount);
    ui->tableWidget->setColumnCount(columnCount);

    // Populate QTableWidget with data from the model
    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem* item = new QTableWidgetItem(model->data(model->index(row, col)).toString());
            ui->tableWidget->setItem(row, col, item);
        }
    }

    // Define the headers manually and check if they display
    QStringList headers;
    headers << "Total" << "Quantite" << "Numvente" << "Medicament" << "Date";
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Force the headers to be shown in case they don’t update automatically
    ui->tableWidget->horizontalHeader()->setVisible(true);
    ui->tableWidget->repaint();

    ui->tableWidget->repaint();

}

void clientwindow::on_pushButton_on_rechercheButton_clicked() {
    int numvente = ui->searchLineEdit->text().toInt();
    if (numvente == 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid number.");
        return;
    }

    // Create and execute the search query
    QSqlQuery query;
    query.prepare("SELECT * FROM clients WHERE numvente = :numvente");
    query.bindValue(":numvente", numvente);
    if (!query.exec()) {
        QMessageBox::warning(this, "Search Error", "Failed to search for client.");
        return;
    }

    // Display the results in the table widget
    ui->tableWidget->setRowCount(0); // Clear previous search results
    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("numvente").toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("quantite").toString()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("total").toString()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("medicament").toString()));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("datee").toString()));
        row++;
    }
    if (row == 0) {
        QMessageBox::information(this, "No Results", "No client found with the specified numvente.");
    }
}



