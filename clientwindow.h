#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <client.h>
#include <QMainWindow>

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
    void on_pushButton_onAddClients_clicked();
    void on_pushButton_onUpdateClients_clicked();
    void on_suppButton_clicked();
    void on_pushButton_on_rechercheButton_clicked();

private:

    void displayClients();

    Ui::ClientWindow *ui;

    client cl;
};
#endif // MAINWINDOW_H
