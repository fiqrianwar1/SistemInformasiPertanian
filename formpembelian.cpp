#include "formpembelian.h"
#include "ui_formpembelian.h"

FormPembelian::FormPembelian(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormPembelian)
{
    ui->setupUi(this);
}

FormPembelian::~FormPembelian()
{
    delete ui;
}

void FormPembelian::on_pushButton_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("INSERT INTO pembelian (kode_barang,kode_supplier,no_faktur,tgl_faktur,harga_jual,harga_beli,banyak_keluar)"
                "VALUE (:kode_barang,:kode_supplier,:no_faktur,:tgl_faktur,:harga_jual,:harga_beli,:banyak_keluar)");
    sql.bindValue(":kode_barang",ui->kode_barangLineEdit->text());
    sql.bindValue(":kode_supplier",ui->kode_supplierLineEdit->text());
    sql.bindValue(":no_faktur",ui->no_fakturLineEdit->text());
    sql.bindValue(":tgl_faktur",ui->tgl_fakturDateEdit->date().toString("yyyy-MM-dd"));
    sql.bindValue(":harga_jual",ui->harga_jualLineEdit->text());
    sql.bindValue(":harga_beli",ui->harga_beliLineEdit->text());
    sql.bindValue(":banyak_keluar",ui->banyak_keluarLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Simpan";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormPembelian::on_pushButton_2_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("UPDATE pembelian SET kode_barang=:kode_barang, kode_supplier=:kode_supplier, tgl_faktur=:tgl_faktur, harga_jual=:harga_jual, "
                "harga_beli=:harga_beli, banyak_keluar=:banyak_keluar WHERE no_faktur=:no_faktur");
    sql.bindValue(":kode_barang",ui->kode_barangLineEdit->text());
    sql.bindValue(":kode_supplier",ui->kode_supplierLineEdit->text());
    sql.bindValue(":no_faktur",ui->no_fakturLineEdit->text());
    sql.bindValue(":tgl_faktur",ui->tgl_fakturDateEdit->date().toString("yyyy-MM-dd"));
    sql.bindValue(":harga_jual",ui->harga_jualLineEdit->text());
    sql.bindValue(":harga_beli",ui->harga_beliLineEdit->text());
    sql.bindValue(":banyak_keluar",ui->banyak_keluarLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormPembelian::on_pushButton_4_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM pembelian WHERE no_faktur=:no_faktur");
    sql.bindValue(":no_faktur",ui->no_fakturLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormPembelian::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    QSqlRecord cari;
    sql.prepare("SELECT * FROM pembelian WHERE no_faktur=:no_faktur");
    sql.bindValue(":no_faktur",ui->no_fakturLineEdit->text());

    if (sql.exec()){
        QSqlRecord cari = sql.record();
        // ui->namaLineEdit->setText(cari.value());
        qDebug()<<cari.value(0).toString();
    }else{
        qDebug()<<sql.lastError().text();
    }
}

