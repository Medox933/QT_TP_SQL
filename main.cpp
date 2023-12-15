#include "widget.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtDebug>
#include <QtSql/QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QTableView>
#include <QHBoxLayout>
#include <QWidget>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Widget w;
 /*
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("QtTp");
    db.setUserName("student");
    db.setPassword("crif2024sn");
    if(db.open())
    {
        qDebug()<<"Vous etes maintenant connecte a "<<db.userName();
        QSqlQuery query;
        query.exec("select * FROM `jeu`");
        while (query.next())
        {
            QString id = query.value(0).toString();
            QString nom = query.value(1).toString();
            QString club = query.value(2).toString();
            qDebug()<<"-----------------------------------------------";
            qDebug()<<id<<"\t"<<nom<<"\t"<<club<<"\t";
        }
        qDebug()<<"-----------------------------------------------";
        qDebug()<<"requete ok! : ";
        //db.close();
    }
    else
    {
        qDebug()<<"La connexion a echouee, desole "<<db.lastError().text();
    }
*/
    w.show();
    return a.exec();
}
