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
    explicit GesMedicament(QWidget *parent = nullptr);
    ~GesMedicament();
    void showRevenuePieChart();

private slots:
    void on_pushButton_A_clicked();
    void on_pushButton_U_clicked();
    void on_pushButton_D_clicked();
    void on_pushButton_T_clicked();
    void on_pushButton_Recher_clicked();
    void on_pushButton_Export_clicked();
    void on_pushButton_ShowRevenue_clicked();
    void on_pushButton_CheckStock_clicked();
    void goToEmployesPage();

    void on_Clientm_clicked();

private:
    Ui::ges_medicament *ui;
    Medicament Mtmp;        // Temporary Medicament object
    bool sortAscending = true;
    Arduino arduino;
};

#endif // GES_MEDICAMENT_H
