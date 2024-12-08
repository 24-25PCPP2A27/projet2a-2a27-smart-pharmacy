#ifndef GESTFOUR_H
#define GESTFOUR_H

#include <QMainWindow>
#include<fournisseur.h>
#include<QPropertyAnimation>
#include<QFileDialog>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>



namespace Ui {
class gestfour;
}

class gestfour : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestfour(QWidget *parent = nullptr);
    ~gestfour();


private slots:
    void on_pb_ajouter_clicked();
    void on_pb_supp_clicked();
    void on_pb_modifier_clicked();
    void updateCountdown();

    void on_actionNew_triggered();

    void on_actionExit_triggered();




    void on_pb_recherche_clicked();


    void on_radioButton_id_clicked();

    void on_radioButton_nom_clicked();





    void on_pb_PDF_clicked();

    void on_pb_STAT_clicked();


    void on_Search_button_clicked();


    void on_page_email_clicked();

    void on_Medicament_clicked();

    void on_client_clicked();

    void on_employer_clicked();

private:
    Ui::gestfour *ui;
    Fournisseur SP;
    QPropertyAnimation *animation;
    QTimer *timer;



};

#endif // GESTFOUR_H
