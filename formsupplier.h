#ifndef FORMSUPPLIER_H
#define FORMSUPPLIER_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlQueryModel>

namespace Ui {
class Formsupplier;
}

class Formsupplier : public QWidget
{
    Q_OBJECT

public:
    explicit Formsupplier(QWidget *parent = nullptr);
    void loadTableSupplier();
    ~Formsupplier();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_tableSupplier_activated(const QModelIndex &index);

private:
    Ui::Formsupplier *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
    QSqlRecord cari;
    QSqlQueryModel * tabelModel;
};

#endif // FORMSUPPLIER_H
