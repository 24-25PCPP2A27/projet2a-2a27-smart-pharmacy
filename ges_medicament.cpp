#include "ges_medicament.h"
#include "ui_ges_medicament.h"
#include"main_employes.h"
#include "medicament.h"
#include "connection.h"
#include <QMessageBox>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QPieSeries>
#include <QSqlError>
#include <QGraphicsScene>
#include <QPdfWriter>
#include <QPainter>
#include <QTableView>
#include <QSqlQueryModel>
#include <QHeaderView>
#include <QTextDocument>
#include <QDialog>
using namespace QtCharts;

GesMedicament::GesMedicament(QWidget *parent, Menu *menu, MainWindow *employesPage)
    : QMainWindow(parent),
      ui(new Ui::ges_medicament),
      menuPtr(menu),
      employesPagePtr(employesPage)
{
    ui->setupUi(this);
    ui->tableView->horizontalHeader()->setStyleSheet(
            "QHeaderView::section {"
            "    background-color: rgb(0, 128, 129);"
            "    color: white;"
            "    font-weight: bold;"
            "    border: 0px solid black;"
            "}"
        );
    ui->tableView->verticalHeader()->setVisible(false);
    int connectionStatus = arduino.connect();
    if (connectionStatus == 0) {
        qDebug() << "Arduino connected to port:" << arduino.getPortName();
    } else if (connectionStatus == 1) {
        QMessageBox::critical(this, "Connection Error", "Failed to open Arduino port.");
    } else {
        QMessageBox::critical(this, "Connection Error", "Arduino not found.");
    }

    ui->tableView->setModel(Mtmp.afficher());
    connect(ui->pushButton_ToEmployes, &QPushButton::clicked, this, &GesMedicament::goToEmployesPage);

}


GesMedicament::~GesMedicament()
{
    delete ui;
}

void GesMedicament::setEmployesPage(MainWindow *employesPage)
{
    employesPagePtr = employesPage;
}

void GesMedicament::goToEmployesPage()
{
    if (employesPagePtr) {
        this->hide();            // Hide the current Medicament page
        employesPagePtr->show(); // Show the Employes page
    } else {
        QMessageBox::warning(this, "Navigation Error", "Employes page is not available.");
    }
}


void GesMedicament::on_pushButton_A_clicked()
{
    int idm = ui->lineEdit_IDM->text().toInt();
    QString libelle = ui->lineEdit_Libelle->text();
    int quantite = ui->lineEdit_Quantite->text().toInt();
    double prix = ui->lineEdit_Prix->text().toDouble();

    Medicament M(idm, libelle, quantite, prix);

    if (M.ajouter())
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Ajout effectué\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(Mtmp.afficher());  // Refresh the table view
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Ajout non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void GesMedicament::on_pushButton_U_clicked()
{
    int idm = ui->lineEdit_IDM->text().toInt();
    QString libelle = ui->lineEdit_Libelle->text();
    int quantite = ui->lineEdit_Quantite->text().toInt();
    double prix = ui->lineEdit_Prix->text().toDouble();

    Medicament M(idm, libelle, quantite, prix);

    if (M.modifier())
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Modification effectuée\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(Mtmp.afficher());  // Refresh the table view
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Modification non effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void GesMedicament::on_pushButton_D_clicked()
{
    int idm = ui->lineEdit_IDM->text().toInt();
    if (Mtmp.supprimer(idm))
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Suppression effectuée\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(Mtmp.afficher());  // Refresh the table view
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Suppression non effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void GesMedicament::on_pushButton_T_clicked()
{
    sortAscending = !sortAscending;
    ui->tableView->setModel(Mtmp.afficherParQuantite(sortAscending));
}

void GesMedicament::on_pushButton_Recher_clicked()
{
    QString libelle = ui->lineEdit_Recher->text();

    ui->tableView->setModel(Mtmp.rechercherParLibelle(libelle));
}

void GesMedicament::on_pushButton_Export_clicked()
{
    QString filePath = "C:/Users/lenovo/OneDrive/Desktop/Qt Creator/Gestion_De_Medicament/medicaments_list.pdf";
    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPagedPaintDevice::A4);
    pdfWriter.setResolution(300);

    QPainter painter(&pdfWriter);
    painter.setFont(QFont("Arial", 10));


    int xOffset = 30, yOffset = 150;
    int rowHeight = 40;
    int columnWidthIDM = 170;
    int columnWidthLibelle = 250;
    int columnWidthQuantite = 400;
    int columnWidthPrix = 150;

    painter.drawText(xOffset, yOffset - 50, "Liste des Medicaments");
    painter.drawText(xOffset, yOffset, "IDM");
    painter.drawText(xOffset + columnWidthIDM, yOffset, "Libelle");
    painter.drawText(xOffset + columnWidthIDM + columnWidthLibelle, yOffset, "Quantite en Stock");
    painter.drawText(xOffset + columnWidthIDM + columnWidthLibelle + columnWidthQuantite, yOffset, "Prix");

    yOffset += rowHeight;
    painter.drawLine(xOffset, yOffset, xOffset + columnWidthIDM + columnWidthLibelle + columnWidthQuantite + columnWidthPrix, yOffset);
    yOffset += rowHeight;

    QSqlQueryModel *model = Mtmp.afficher();
    int rowCount = model->rowCount();

    for (int row = 0; row < rowCount; ++row) {
        painter.drawText(xOffset, yOffset, model->data(model->index(row, 0)).toString());
        painter.drawText(xOffset + columnWidthIDM, yOffset, model->data(model->index(row, 1)).toString());
        painter.drawText(xOffset + columnWidthIDM + columnWidthLibelle, yOffset, model->data(model->index(row, 2)).toString());
        painter.drawText(xOffset + columnWidthIDM + columnWidthLibelle + columnWidthQuantite, yOffset, model->data(model->index(row, 3)).toString());

        yOffset += rowHeight + 10;

        if (yOffset > pdfWriter.height() - 100) {
            pdfWriter.newPage();
            yOffset = 100;
        }
    }

    painter.end();
    QMessageBox::information(this, "File Saved", "PDF saved to: " + filePath);
}

void GesMedicament::addNotificationRequest(const QString &email, const QString &libelle)
{
    QSqlQuery query;
    query.prepare("SELECT QUANTITE_EN_STOCK FROM MEDICAMENT WHERE LIBELLE = :libelle");
    query.bindValue(":libelle", libelle);

    if (query.exec() && query.next())
    {
        int stock = query.value(0).toInt();
        if (stock == 0)
        {
            // Add to NOTIFICATIONS table
            QSqlQuery insertQuery;
            insertQuery.prepare("INSERT INTO NOTIFICATIONS (EMAIL, MEDICAMENT, NOTIFIED) VALUES (:email, :medicament, 'N')");
            insertQuery.bindValue(":email", email);
            insertQuery.bindValue(":medicament", libelle);

            if (insertQuery.exec())
            {
                QMessageBox::information(this, "Notification Added", "You will be notified when the medication is available.");
            }
            else
            {
                QMessageBox::critical(this, "Error", "Failed to add notification: ");
            }
        }
        else
        {
            QMessageBox::information(this, "Medication Available", "The medication is already in stock.");
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", "Failed to check medication stock: " );
    }
}


void GesMedicament::on_pushButton_AddNotification_clicked()
{
    QString email = ui->lineEdit_Email->text();
    QString libelle = ui->lineEdit_Libelle1->text();

    if (!email.isEmpty() && !libelle.isEmpty())
    {
        addNotificationRequest(email, libelle);
    }
    else
    {
        QMessageBox::warning(this, "Input Error", "Please enter both email and medication name.");
    }
}

void GesMedicament::showRevenuePieChart()
{
    QSqlQuery query;
    query.prepare("SELECT LIBELLE, QUANTITE_EN_STOCK, PRIX FROM MEDICAMENT");

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
        return;
    }

    QtCharts::QPieSeries *series = new QtCharts::QPieSeries();
    double totalRevenue = 0;

    while (query.next()) {
        QString libelle = query.value(0).toString();
        int quantity = query.value(1).toInt();
        double price = query.value(2).toDouble();

        double revenue = quantity * price;
        totalRevenue += revenue;

        series->append(libelle, revenue);
    }

    for (QtCharts::QPieSlice *slice : series->slices()) {
        slice->setLabel(QString("%1: %2").arg(slice->label()).arg(slice->value(), 0, 'f', 2)); // Format to 2 decimal places
    }

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle(QString("Expected Revenues: Total = %1").arg(totalRevenue, 0, 'f', 2));
    chart->setAnimationOptions(QtCharts::QChart::SeriesAnimations);

    chart->setMargins(QMargins(0, 0, 0, 0));
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(525, 405);

    if (ui->graphicsView_2->scene() != nullptr) {
        ui->graphicsView_2->scene()->clear();
    } else {
        ui->graphicsView_2->setScene(new QGraphicsScene(this));
    }
    ui->graphicsView_2->scene()->addWidget(chartView);

    chartView->setFixedSize(525, 405);
}


void GesMedicament::on_pushButton_ShowRevenue_clicked()
{
    showRevenuePieChart();
}

void GesMedicament::on_pushButton_NextPage_clicked()
{
    // Move to the next page in the QStackedWidget
    int currentIndex = ui->stackedWidget->currentIndex();
    int nextIndex = (currentIndex + 1) % ui->stackedWidget->count(); // Wrap around to the first page
    ui->stackedWidget->setCurrentIndex(nextIndex);
}

void GesMedicament::on_pushButton_BackPage_clicked()
{
    // Move to the previous page in the QStackedWidget
    int currentIndex = ui->stackedWidget->currentIndex();
    int prevIndex = (currentIndex - 1 + ui->stackedWidget->count()) % ui->stackedWidget->count(); // Wrap around to the last page
    ui->stackedWidget->setCurrentIndex(prevIndex);
}

void GesMedicament::on_pushButton_log_clicked()
{
    QString username = ui->lineEdit_user->text();
    QString password = ui->lineEdit_pass->text();

    // Ensure database connection is open
    QSqlDatabase db = QSqlDatabase::database(); // Assuming you already set up a connection
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Database Error", "Failed to connect to the database.");
        return;
    }

    // Prepare and execute the query
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM EMPLOYE WHERE NOM = :username AND ID = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        QMessageBox::critical(this, "Query Error", "Failed to execute the query: " + query.lastError().text());
        return;
    }

    // Validate the result
    if (query.next() && query.value(0).toInt() > 0) {
        // Credentials are valid, move to the next page
        ui->stackedWidget->setCurrentIndex(1); // Navigate to the next page (index 1)
    } else {
        // Show an error message
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}

void GesMedicament::on_pushButton_CheckStock_clicked()
{
    int idm = ui->lineEdit_IDM_Check->text().toInt();

    // Query the database for the medicament
    QSqlQuery query;
    query.prepare("SELECT LIBELLE, QUANTITE_EN_STOCK FROM MEDICAMENT WHERE IDM = :IDM");
    query.bindValue(":IDM", idm);

    if (query.exec() && query.next()) {
        QString libelle = query.value(0).toString();
        int stock = query.value(1).toInt();
        QString message;

        if (stock > 0) {
            message = QString("There is %1 of '%2'").arg(stock).arg(libelle);
        } else {
            message = QString("'%1' is out of stock").arg(libelle);
        }

        arduino.sendData(message.toUtf8());
    } else {
        QMessageBox::critical(this, "Error", "Medicament not found.");
    }
}

