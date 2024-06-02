#ifndef FORMSUPPLIER_H
#define FORMSUPPLIER_H

#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>

namespace Ui {
class Formsupplier;
}

class Formsupplier : public QWidget
{
    Q_OBJECT

public:
    explicit Formsupplier(QWidget *parent = nullptr);
    ~Formsupplier();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Formsupplier *ui;
    QSqlDatabase koneksi;
    QSqlQuery sql;
    QSqlRecord cari;
};

#endif // FORMSUPPLIER_H
