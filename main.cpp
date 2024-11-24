#include "clientwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <connection.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //creation moment
    Connection c;
    bool test=c.createconnection();
    clientwindow w;
    if(test)
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
         QObject::tr("connection successful.\n"
                     "click cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
        QObject::tr("connection failed.\n"
                      "click cancel to exit."),QMessageBox::Cancel);
    return a.exec();
}
