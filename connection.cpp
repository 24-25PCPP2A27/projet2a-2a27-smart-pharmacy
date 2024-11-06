#include "connection.h"

Connection::Connection(){}

bool Connection::createconnection()
{
db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("CPP_Projet");
db.setUserName("aziz");
db.setPassword("garwachi");

if (db.open()) test=true;
    return  test;
}
void Connection::closeConnection(){db.close();}
