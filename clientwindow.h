#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H
#include <client.h>
#include <QMainWindow>
#include "serialhandler.h"
#include <QVector>
#include <QPair>

QT_BEGIN_NAMESPACE
namespace Ui { class ClientWindow; }
QT_END_NAMESPACE

class clientwindow : public QMainWindow
{
    Q_OBJECT

public:
    clientwindow(QWidget *parent = nullptr);
    ~clientwindow();

private slots: // Ensure that these methods are declared as slots
    void on_AddClients_clicked();
    void on_UpdateClients_clicked();
    void on_suppButton_clicked();
    void on_rechercheButton_clicked();
    void on_trierButton_clicked();
    void on_exportButton_clicked();
    void on_statsButton_clicked();
    void handleKeypadInput(char key);
    void on_refrechButton_clicked();

    void on_restockButton_clicked();
    void printAllMedications();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_fournisseur_clicked();

private:

    void displayClients();
    void displayRestockingSuggestions(const QMap<QString, int> &suggestions);

    Ui::ClientWindow *ui;

    client cl;

    SerialHandler *serialHandler;

     QVector<QPair<QString, int>> restockingData; // Vector to store medication and its average days
};
#endif // CLIENTWINDOW_H
