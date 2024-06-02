#ifndef FORMBARANG_H
#define FORMBARANG_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>

namespace Ui {
class FormBarang;
}

class FormBarang : public QWidget
{
    Q_OBJECT

public:
    explicit FormBarang(QWidget *parent = nullptr);
    ~FormBarang();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::FormBarang *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
    QSqlRecord cari;
};

#endif // FORMBARANG_H
