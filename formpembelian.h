#ifndef FORMPEMBELIAN_H
#define FORMPEMBELIAN_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>

namespace Ui {
class FormPembelian;
}

class FormPembelian : public QWidget
{
    Q_OBJECT

public:
    explicit FormPembelian(QWidget *parent = nullptr);
    ~FormPembelian();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::FormPembelian *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
    QSqlRecord cari;
};

#endif // FORMPEMBELIAN_H
