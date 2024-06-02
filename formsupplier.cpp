#include "formsupplier.h"
#include "ui_formsupplier.h"

Formsupplier::Formsupplier(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Formsupplier)
{
    ui->setupUi(this);
}

Formsupplier::~Formsupplier()
{
    delete ui;
}

void Formsupplier::on_pushButton_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("INSERT INTO suppier (nama_supplier,kode_supplier,alamat_supplier,telp_supplier,fax_supplier,email_supplier)"
                "VALUE (:nama_supplier,:kode_supplier,:alamat_supplier,:telp_supplier,:fax_supplier,:email_supplier)");
    sql.bindValue(":nama_supplier",ui->nama_supplierLineEdit->text());
    sql.bindValue(":kode_supplier",ui->kode_supplierLineEdit->text());
    sql.bindValue(":alamat_supplier",ui->alamat_supplierLineEdit->text());
    sql.bindValue(":telp_supplier",ui->telp_supplierLineEdit->text());
    sql.bindValue(":fax_supplier",ui->fax_supplierLineEdit->text());
    sql.bindValue(":email_supplier",ui->email_supplierLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Simpan";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void Formsupplier::on_pushButton_2_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("UPDATE suppier SET nama_supplier=:nama_supplier, alamat_supplier=:alamat_supplier, telp_supplier=:telp_supplier, "
                "fax_supplier=:fax_supplier, email_supplier=:email_supplier WHERE kode_supplier=:kode_supplier");
    sql.bindValue(":nama_supplier",ui->nama_supplierLineEdit->text());
    sql.bindValue(":kode_supplier",ui->kode_supplierLineEdit->text());
    sql.bindValue(":alamat_supplier",ui->alamat_supplierLineEdit->text());
    sql.bindValue(":telp_supplier",ui->telp_supplierLineEdit->text());
    sql.bindValue(":fax_supplier",ui->fax_supplierLineEdit->text());
    sql.bindValue(":email_supplier",ui->email_supplierLineEdit->text());
    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void Formsupplier::on_pushButton_4_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM suppier WHERE kode_supplier=:kode_supplier");
    sql.bindValue(":kode_supplier",ui->kode_supplierLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void Formsupplier::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    QSqlRecord cari;
    sql.prepare("SELECT * FROM suppier WHERE kode_supplier=:kode_supplier");
    sql.bindValue(":kode_supplier",ui->kode_supplierLineEdit->text());

    if (sql.exec()){
        QSqlRecord cari = sql.record();
        // ui->namaLineEdit->setText(cari.value());
        qDebug()<<cari.value(0).toString();
    }else{
        qDebug()<<sql.lastError().text();
    }
}

