/*#ifndef MAIN_EMPLOYES_H
#define MAIN_EMPLOYES_H


class main_employes
{
public:
    main_employes();
};

#endif // MAIN_EMPLOYES_H
 */


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<employes.h>
#include <QWidget> // Ensure QWidget is included
#include<QPropertyAnimation>
#include<QFileDialog>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include "qrcodedialog.h"
#include "arduino.h"
//#include"ges_medicament.h"

class GesMedicament;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pb_ajouter_clicked();
        void on_pb_supp_clicked();
        void on_pb_modifier_clicked();
        void on_pb_recherche_clicked();
        void on_pb_trier_clicked();
        void on_pb_pdf_clicked();
        void on_pb_showStatsButton_clicked();
        void on_pb_qr_clicked();
        void on_Ard_button_clicked();
        void goToMedicamentPage(); // Slot to navigate to the Medicament page

        void on_pushButton_5_clicked();

        void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    QByteArray data; // variable contenant les données reçues

    Arduino A;
    employes SP;

    QPropertyAnimation *animation;
    QTimer *timer;

};

#endif // MAINWINDOW_H
