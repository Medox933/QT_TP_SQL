#include "widget.h"
#include "ui_widget.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtDebug>
#include <QtSql/QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QTableView>
#include <QHBoxLayout>
#include <QWidget>


Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Configuration de la connexion à la base de données
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={MySQL ODBC 8.2 ANSI Driver};DATABASE=jeu;");
    db.setUserName("root");
    //QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");    Commande pour conecter à la base de donnée sur Linux
    //db.setDatabaseName("QtTp");
    //db.setUserName("student");
    db.setPassword("crif2024sn");

    // Vérifier si la connexion a réussi
    if(db.open())
    {
        qDebug() << "La connexion a été établie";
    }
    else
    {
        qDebug() << "La connexion a échoué, désolé : " << db.lastError().text();
    }

    // Connecter le signal "clicked" du bouton "Afficherjoueur" au slot "afficherJoueur"
    connect(ui ->Afficherjoueur, &QPushButton::clicked, this, &Widget::afficherJoueur);

    // Connecter le signal "clicked" du bouton "AjouterNote" au slot "ajouterNote"
    connect(ui ->AjouterNote, &QPushButton::clicked, this, &Widget::ajouterNote);
}

// Fonction pour afficher les joueurs dans le widget tableView
void Widget::afficherJoueur(){
    QSqlQueryModel *model = new QSqlQueryModel();

    // Exécuter la requête SQL pour sélectionner tous les enregistrements de la table "jeux"
    model->setQuery("SELECT * FROM jeux");
    //model->setQuery("SELECT * FROM jeu"); requête pour la récuperer la base de données Pour Linux

    // Afficher les résultats dans le widget tableView
    ui->tableView->setModel(model);
}

// Fonction pour ajouter une note au joueur sélectionné
void Widget::ajouterNote(){
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedIndexes();

    // Vérifier si une cellule est sélectionnée
    if(!selectedIndexes.isEmpty()){
        // Récupérer l'index de la première cellule sélectionnée
        int row = selectedIndexes.first().row();

        // Récupérer l'ID du joueur correspondant à cette ligne
        int idPlayer = ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toInt();

        // Récupérer la note saisie par l'utilisateur
        int note = ui->editNote->text().toInt();

        // Vérifier si la note est inférieure ou égale à 10
        if (note <= 10) {
            // Préparer la requête SQL pour mettre à jour la note du joueur
            QSqlQuery query;
            query.prepare("UPDATE jeux SET note = :note WHERE id = :id");
            //query.prepare("UPDATE jeux SET note = :note WHERE id = :id"); Requête pour Modifier la base de donnée sur Linux
            query.bindValue(":note", note);
            query.bindValue(":id", idPlayer);

            // Exécuter la requête SQL
            query.exec();

            // Rafraîchir le widget tableView pour afficher les modifications
            afficherJoueur();
        }
        else {
            qDebug() << "La note doit être inférieure à 10";
        }
    }
}

Widget::~Widget()
{
    delete ui;
}
