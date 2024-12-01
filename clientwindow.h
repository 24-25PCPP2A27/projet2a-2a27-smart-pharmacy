#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <client.h>
#include <QMainWindow>
#include "serialhandler.h"

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

private:

    void displayClients();

    Ui::ClientWindow *ui;

    client cl;

    SerialHandler *serialHandler;
};
#endif // MAINWINDOW_H
