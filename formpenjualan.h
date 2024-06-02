#ifndef FORMPENJUALAN_H
#define FORMPENJUALAN_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>

namespace Ui {
class FormPenjualan;
}

class FormPenjualan : public QWidget
{
    Q_OBJECT

public:
    explicit FormPenjualan(QWidget *parent = nullptr);
    ~FormPenjualan();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::FormPenjualan *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
    QSqlRecord cari;
};

#endif // FORMPENJUALAN_H
