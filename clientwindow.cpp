#include "clientwindow.h"
#include "ui_clientwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QtDebug>
#include <QFileDialog>
#include <QTextDocument>
#include <QPrinter>
#include <QMessageBox>
#include <clientchart.h>
#include <QSqlError>
#include <QDate>
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

void clientwindow::on_AddClients_clicked() {

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

void clientwindow::on_UpdateClients_clicked() {
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
    headers << "Numvente" << "Quantite" << "Total" << "Medicament" << "Date";
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Force the headers to be shown in case they don’t update automatically
    ui->tableWidget->horizontalHeader()->setVisible(true);
    ui->tableWidget->repaint();

    ui->tableWidget->repaint();

}

void clientwindow::on_rechercheButton_clicked() {
    // Retrieve the input from the search line edit
    int numvente = ui->searchLineEdit->text().toInt();

    // Check if the input is valid
    if (numvente == 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid Num Vente.");
        return;
    }

    // Use the chercher function to search for the client
    QSqlQueryModel* model = cl.chercher(numvente);

    // Check if the search returned any results
    if (model->rowCount() == 0) {
        QMessageBox::information(this, "No Results", "No client found with the specified Num Vente.");
        return;
    }

    // Update the table widget with the search results
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(model->rowCount());
    ui->tableWidget->setColumnCount(model->columnCount());

    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QString data = model->data(model->index(row, col)).toString();
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(data));
        }
    }

    // Set the column headers (optional)
    QStringList headers = {"Num Vente", "Quantité", "Total", "Medicament", "Date"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);
}

void clientwindow::on_trierButton_clicked()
{
    // Use the sort function
     QSqlQueryModel* model = cl.trier();

     // Check if the model is valid
     if (model->rowCount() == 0) {
         QMessageBox::information(this, "No Results", "No data available to sort.");
         return;
     }

     // Update the table widget with the sorted data
     ui->tableWidget->clearContents();
     ui->tableWidget->setRowCount(model->rowCount());
     ui->tableWidget->setColumnCount(model->columnCount());

     for (int row = 0; row < model->rowCount(); ++row) {
         for (int col = 0; col < model->columnCount(); ++col) {
             QString data = model->data(model->index(row, col)).toString();
             ui->tableWidget->setItem(row, col, new QTableWidgetItem(data));
         }
     }

     // Set the column headers (optional)
     QStringList headers = {"Num Vente", "Quantité", "Total", "Medicament", "Date"};
     ui->tableWidget->setHorizontalHeaderLabels(headers);
}

void clientwindow::on_exportButton_clicked()
{
    // Step 1: Choose the file path for the PDF
       QString filePath = QFileDialog::getSaveFileName(this, "Save as PDF", "", "*.pdf");
       if (filePath.isEmpty()) {
           return; // User canceled
       }

       // Ensure the file has a .pdf extension
       if (!filePath.endsWith(".pdf", Qt::CaseInsensitive)) {
           filePath += ".pdf";
       }

       // Step 2: Start building HTML content for the table
       QString html;
       html += "<h2>Client Data Export</h2>";
       html += "<table border='1' cellspacing='0' cellpadding='4'>";
       html += "<thead><tr>";
       QStringList headers = {"Num Vente", "Quantité", "Total", "Medicament", "Date"};
       for (const QString &header : headers) {
           html += QString("<th>%1</th>").arg(header);
       }
       html += "</tr></thead>";

       // Populate table rows
       html += "<tbody>";
       for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
           html += "<tr>";
           for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
               QString cellData = ui->tableWidget->item(row, col)->text();
               html += QString("<td>%1</td>").arg(cellData);
           }
           html += "</tr>";
       }
       html += "</tbody></table>";

       // Step 3: Create a QTextDocument and set the HTML content
       QTextDocument document;
       document.setHtml(html);

       // Step 4: Configure the printer and export to PDF
       QPrinter printer(QPrinter::PrinterMode::HighResolution);
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setOutputFileName(filePath);
       document.print(&printer);

       QMessageBox::information(this, "Success", "Client data exported as PDF successfully!");
}
//shows stats
void clientwindow::on_statsButton_clicked() {
    client cl;
    QMap<QString, int> stats = cl.getMedicamentStats();

    clientchart *chartWidget = new clientchart(stats, this);

    QLayout *layout = ui->frame_chart->layout();
    if (!layout) {
        layout = new QVBoxLayout(ui->frame_chart);
        ui->frame_chart->setLayout(layout);
    }

    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != nullptr) {
        delete child->widget();  // Remove previous chart widget
        delete child;
    }

    layout->addWidget(chartWidget);
    chartWidget->show();

    ui->tabWidget->setCurrentWidget(ui->tab_statistics);
}
