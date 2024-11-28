#ifndef GES_MEDICAMENT_H
#define GES_MEDICAMENT_H

#include "medicament.h"
#include "connection.h"
#include "arduino.h"
#include <QMainWindow>
#include "ui_ges_medicament.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Ges_Medicament; }
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
    void on_pushButton_AddNotification_clicked();
    void addNotificationRequest(const QString &email, const QString &libelle);
    void on_pushButton_ShowRevenue_clicked();
    void on_pushButton_NextPage_clicked();
    void on_pushButton_BackPage_clicked();
    void on_pushButton_log_clicked();
    void on_pushButton_CheckStock_clicked();

private:
    Ui::Ges_Medicament *ui;
    Medicament Mtmp;
    bool sortAscending = true;
    Arduino arduino;
};

#endif // GES_MEDICAMENT_H
