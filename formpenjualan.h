#ifndef FORMPENJUALAN_H
#define FORMPENJUALAN_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlQueryModel>

namespace Ui {
class FormPenjualan;
}

class FormPenjualan : public QWidget
{
    Q_OBJECT

public:
    explicit FormPenjualan(QWidget *parent = nullptr);
    void loadTablePenjualan();
    ~FormPenjualan();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_tablePenjualan_activated(const QModelIndex &index);

private:
    Ui::FormPenjualan *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
    QSqlRecord cari;
    QSqlQueryModel * tabelModel;
};

#endif // FORMPENJUALAN_H
