#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<fournisseur.h>
#include<QPropertyAnimation>
#include<QFileDialog>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include "pagem.h"  // Inclure la classe de PageM


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

    void on_email_clicked();

private:
    Ui::MainWindow *ui;
    Fournisseur SP;
    QPropertyAnimation *animation;
    QTimer *timer;
    pageM *page;  // Pointeur vers l'instance de la fenêtre pageM


};

#endif // MAINWINDOW_H
