#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class client {
public:
    client();
    client(int, QString, QString, QString, QString);

    int get_CIN();
    QString get_NOM();
    QString get_PRENOM();
    QString get_ADRESSE();
    QString get_DATE_NAISSANCE();

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();

private:
    int CIN;
    QString NOM, PRENOM, ADRESSE, DATE_NAISSANCE;
};

#endif // CLIENT_H
