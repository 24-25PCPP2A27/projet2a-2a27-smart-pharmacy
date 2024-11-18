#include "ges_medicament.h"
#include "ui_ges_medicament.h"
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
using namespace QtCharts;

GesMedicament::GesMedicament(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::Ges_Medicament)
{
    ui->setupUi(this);
    ui->tableView->setModel(Mtmp.afficher());
}

GesMedicament::~GesMedicament()
{
    delete ui;
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

void GesMedicament::on_pushButton_Stats_clicked()
{

    if (ui->graphicsView->scene() != nullptr) {
        ui->graphicsView->scene()->clear();
    } else {
        ui->graphicsView->setScene(new QGraphicsScene(this));
    }

    QMap<QString, double> stats = Mtmp.getStatistics();

    QBarSet *set = new QBarSet("Quantité en Stock");
    *set << stats["total"] << stats["average"] << stats["min"] << stats["max"];


    QBarSeries *series = new QBarSeries();
    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des Quantités en Stock");
    chart->setAnimationOptions(QChart::SeriesAnimations);


    QStringList categories;
    categories << "Total" << "Moyenne" << "Minimum" << "Maximum";

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, stats["total"] * 1.1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(521, 401);
    ui->graphicsView->scene()->addWidget(chartView);

    chartView->chart()->resize(521, 401);

    chart->setMargins(QMargins(0, 0, 0, 0));
    chart->legend()->setAlignment(Qt::AlignBottom);
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


void GesMedicament::on_pushButton_Export_Stats_clicked()
{
    QString filePath = "C:/Users/lenovo/OneDrive/Desktop/Qt Creator/Gestion_De_Medicament/sales_statistics.pdf";

    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPagedPaintDevice::A4);
    QPainter painter(&pdfWriter);
    painter.setFont(QFont("Arial", 12));

    int yOffset = 50;
    painter.drawText(200, yOffset, "Statistiques de Ventes");

    yOffset += 30;

    QPixmap chartPixmap = ui->graphicsView->grab();
    QRect targetRect(100, yOffset, pdfWriter.width() - 200, pdfWriter.height() - 150);
    painter.drawPixmap(targetRect, chartPixmap);

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

    if (username == "admin" && password == "pharmaflow") {
        // Credentials are valid, move to the next page
        ui->stackedWidget->setCurrentIndex(1); // Navigate to the next page (index 1)
    } else {
        // Show an error message
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}
