#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtDebug>
#include <QtSql/QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QTableView>
#include <QHBoxLayout>
#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void afficherJoueur();
    void ajouterNote();

private:
    Ui::Widget *ui;
    QSqlTableModel *model;

};
#endif // WIDGET_H
