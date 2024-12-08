#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("CPP_Projet");
db.setUserName("aziz");//inserer nom de l'utilisateur
db.setPassword("garwachi");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;




    return  test;
}
