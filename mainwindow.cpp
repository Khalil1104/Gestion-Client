#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    refreshTable();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked() {
    int CIN = ui->lineEdit_CIN->text().toInt();
    QString NOM = ui->lineEdit_Nom->text();
    QString PRENOM = ui->lineEdit_Prenom->text();
    QString ADRESSE = ui->lineEdit_adresse_email->text();
    QString DATE_NAISSANCE = ui->lineEdit_numero_de_telephone->text();

    client c(CIN, NOM, PRENOM, ADRESSE, DATE_NAISSANCE);
    bool test =c.ajouter();
    if (test) {
        QMessageBox::information(this, "Ajouter un client", "Client ajouté avec succès.");
        refreshTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du client.");
    }
}

void MainWindow::on_pb_supprimer_clicked() {
    int CIN = ui->lineEdit_CIN->text().toInt();
    if (tmpClient.supprimer(CIN)) {
        QMessageBox::information(this, "Supprimer un client", "Client supprimé avec succès.");
        refreshTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression du client.");
    }
}




void MainWindow::on_pb_modifier_clicked() {
    int CIN = ui->lineEdit_CIN->text().toInt();
    QString NOM = ui->lineEdit_Nom->text();
    QString PRENOM = ui->lineEdit_Prenom->text();
    QString ADRESSE = ui->lineEdit_adresse_email->text();
    QString DATE_NAISSANCE = ui->lineEdit_numero_de_telephone->text();

    client c(CIN, NOM, PRENOM, ADRESSE, DATE_NAISSANCE);
    bool test = c.modifier();

    if (test) {
        QMessageBox::information(this, "Modifier un client", "Client modifié avec succès.");
        refreshTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du client.");
    }
}
void MainWindow::refreshTable() {
    QSqlQueryModel *model = tmpClient.afficher();
    ui->tab_afficher->setModel(model);
}
