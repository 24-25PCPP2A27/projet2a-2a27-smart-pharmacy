#include "ges_medicament.h"
#include "main_employes.h"
#include "menu.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test = c.createconnect();

    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("Database Open"),
                                 QObject::tr("Connection successful.\nClick Cancel to exit."),
                                 QMessageBox::Cancel);

        // Create the Menu
        Menu M;

        // Create the Medicament page (initially with nullptr for Employes page)
        GesMedicament *medicamentPage = new GesMedicament(nullptr, &M, nullptr);

        // Create the Employes page, passing the Medicament page pointer
        MainWindow *employesPage = new MainWindow(nullptr, medicamentPage);

        // Set the Employes page pointer in the Medicament page
        medicamentPage->setEmployesPage(employesPage);

        // Pass pointers for navigation from Menu
        QObject::connect(&M, &Menu::pageChanged, [&](int currentPage) {
            if (currentPage == 1) { // Navigate to Employes page
                employesPage->show();
                M.hide(); // Hide the menu
                QObject::connect(employesPage, &MainWindow::destroyed, [&]() { M.show(); });
            }
            else if (currentPage == 2) { // Navigate to Medicament page
                medicamentPage->show();
                M.hide(); // Hide the menu
                QObject::connect(medicamentPage, &GesMedicament::destroyed, [&]() { M.show(); });
            }
        });

        M.show(); // Show the Menu
        return a.exec();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Database Not Open"),
                              QObject::tr("Connection failed.\nClick Cancel to exit."),
                              QMessageBox::Cancel);
        return -1;
    }
}
