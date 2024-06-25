#ifndef FORMPEMBELIAN_H
#define FORMPEMBELIAN_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QSqlQueryModel>

namespace Ui {
class FormPembelian;
}

class FormPembelian : public QWidget
{
    Q_OBJECT

public:
    explicit FormPembelian(QWidget *parent = nullptr);
    void loadTablePembelian();
    ~FormPembelian();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_tablePembelian_activated(const QModelIndex &index);

private:
    Ui::FormPembelian *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
    QSqlRecord cari;
    QSqlQueryModel * tabelModel;
};

#endif // FORMPEMBELIAN_H
