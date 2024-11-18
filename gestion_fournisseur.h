#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<fournisseur.h>

#include<QPropertyAnimation>
#include<QFileDialog>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

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



    void on_lineEdit_recherche_textChanged();

    void on_pb_recherche_clicked();

    void on_actionGen_rer_PDF_triggered();

    void on_radioButton_id_clicked();

    void on_radioButton_nom_clicked();



    void on_actionStatistiques_triggered();

    void on_pushButton_2_clicked();

    void on_pb_PDF_clicked();

    void on_pb_STAT_clicked();

    void on_comboBox_activated(int index);

private:
    Ui::MainWindow *ui;
    Fournisseur SP;
    QPropertyAnimation *animation;
    QTimer *timer;
};

#endif // MAINWINDOW_H
