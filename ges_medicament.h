#ifndef GES_MEDICAMENT_H
#define GES_MEDICAMENT_H

#include "medicament.h"
#include "connection.h"
#include <QMainWindow>
#include "ui_ges_medicament.h"  // Make sure this includes the correct UI header

QT_BEGIN_NAMESPACE
namespace Ui { class Ges_Medicament; }  // Use Ui::Ges_Medicament instead of Ui::GesMedicament
QT_END_NAMESPACE

class GesMedicament : public QMainWindow
{
    Q_OBJECT

public:
    explicit GesMedicament(QWidget *parent = nullptr);
    ~GesMedicament();

private slots:
    void on_pushButton_A_clicked();
    void on_pushButton_U_clicked();
    void on_pushButton_D_clicked();

private:
    Ui::Ges_Medicament *ui;  // Use Ui::Ges_Medicament to match the generated UI class
    Medicament Mtmp;
};

#endif // GES_MEDICAMENT_H
