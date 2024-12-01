#include "clientwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <connection.h>
#include <QtDebug>
#include <QFileDialog>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Load QSS from resources
    QFile StyleSheetFile(":/Adaptic.qss");
    if (StyleSheetFile.open(QFile::ReadOnly)) {
        QString stylesheet = QLatin1String(StyleSheetFile.readAll());
        a.setStyleSheet(stylesheet);
        qDebug() << "QSS loaded successfully.";
    } else {
        qDebug() << "Failed to load QSS from resources.";
    }

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
