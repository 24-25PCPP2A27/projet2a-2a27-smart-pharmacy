#ifndef GES_MEDICAMENT_H
#define GES_MEDICAMENT_H

#include "medicament.h"
#include "connection.h"
#include "arduino.h"
#include "main_employes.h"
#include "menu.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ges_medicament; } // Match the correct UI class name
QT_END_NAMESPACE

class GesMedicament : public QMainWindow
{
    Q_OBJECT

public:
    explicit GesMedicament(QWidget *parent = nullptr, Menu *menu = nullptr, MainWindow *employesPage = nullptr);
    ~GesMedicament();
    void showRevenuePieChart();
    void setEmployesPage(MainWindow *employesPage);

private slots:
    void on_pushButton_A_clicked();
    void on_pushButton_U_clicked();
    void on_pushButton_D_clicked();
    void on_pushButton_T_clicked();
    void on_pushButton_Recher_clicked();
    void on_pushButton_Export_clicked();
    void on_pushButton_AddNotification_clicked();
    void addNotificationRequest(const QString &email, const QString &libelle);
    void on_pushButton_ShowRevenue_clicked();
    void on_pushButton_NextPage_clicked();
    void on_pushButton_BackPage_clicked();
    void on_pushButton_log_clicked();
    void on_pushButton_CheckStock_clicked();
    void goToEmployesPage();

private:
    Ui::ges_medicament *ui;
    Menu *menuPtr;          // Pointer to the Menu instance
    MainWindow *employesPagePtr;
    Medicament Mtmp;        // Temporary Medicament object
    bool sortAscending = true;
    Arduino arduino;
};

#endif // GES_MEDICAMENT_H
