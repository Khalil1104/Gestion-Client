#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect() {
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("projetcpp"); // Nom de la source de données
        db.setUserName("PROJET");        // Nom de l'utilisateur
        db.setPassword("esprit24");      // Mot de passe de l'utilisateur
    }
    return db.open();
}
void Connection::closeConnection(){db.close();}
