#include "client.h"
#include <QDebug>

client::client() : CIN(0), NOM(""), PRENOM(""), ADRESSE(""), DATE_NAISSANCE("") {}

client::client(int CIN, QString NOM, QString PRENOM, QString ADRESSE, QString DATE_NAISSANCE)
    : CIN(CIN), NOM(NOM), PRENOM(PRENOM), ADRESSE(ADRESSE), DATE_NAISSANCE(DATE_NAISSANCE) {}

int client::get_CIN() { return CIN; }
QString client::get_NOM() { return NOM; }
QString client::get_PRENOM() { return PRENOM; }
QString client::get_ADRESSE() { return ADRESSE; }
QString client::get_DATE_NAISSANCE() { return DATE_NAISSANCE; }

bool client::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO client (CIN, NOM, PRENOM, ADRESSE, DATE_NAISSANCE) "
                  "VALUES (:CIN, :NOM, :PRENOM, :ADRESSE, :DATE_NAISSANCE)");
    query.bindValue(":CIN", CIN);
    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM", PRENOM);
    query.bindValue(":ADRESSE", ADRESSE);
    query.bindValue(":DATE_NAISSANCE", DATE_NAISSANCE);
    return query.exec();
}

QSqlQueryModel* client::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM client");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date de Naissance"));
    return model;
}

bool client::supprimer(int CIN) {
    QSqlQuery query;
    query.prepare("DELETE FROM client WHERE CIN = :CIN");
    query.bindValue(":CIN", CIN);
    return query.exec();
}

bool client::modifier() {
    QSqlQuery query;
    query.prepare("UPDATE client SET NOM = :NOM, PRENOM = :PRENOM, ADRESSE = :ADRESSE, DATE_NAISSANCE = :DATE_NAISSANCE "
                  "WHERE CIN = :CIN");
    query.bindValue(":CIN", CIN);
    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM", PRENOM);
    query.bindValue(":ADRESSE", ADRESSE);
    query.bindValue(":DATE_NAISSANCE", DATE_NAISSANCE);
    return query.exec();
}
