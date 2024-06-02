#include "formpenjualan.h"
#include "ui_formpenjualan.h"

FormPenjualan::FormPenjualan(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormPenjualan)
{
    ui->setupUi(this);
}

FormPenjualan::~FormPenjualan()
{
    delete ui;
}

void FormPenjualan::on_pushButton_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("INSERT INTO penjualan (kode_pelanggan,no_faktur,tgl_faktor,harga_beli,harga_jual,banyak_keluar,kode_barang)"
                "VALUE (:kode_pelanggan,:no_faktur,:tgl_faktor,:harga_beli,:harga_jual,:banyak_keluar,:kode_barang)");
    sql.bindValue(":kode_pelanggan",ui->kode_PelangganLineEdit->text());
    sql.bindValue(":no_faktur",ui->no_FakturLineEdit->text());
    sql.bindValue(":tgl_faktor",ui->tgl_FaktorDateEdit->date().toString("yyyy-MM-dd"));
    sql.bindValue(":harga_beli",ui->harga_BeliLineEdit->text());
    sql.bindValue(":harga_jual",ui->harga_JualLineEdit->text());
    sql.bindValue(":banyak_keluar",ui->banyak_KeluarLineEdit->text());
    sql.bindValue(":kode_barang",ui->Kode_BarangLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Simpan";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormPenjualan::on_pushButton_2_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("UPDATE penjualan SET no_faktur=:no_faktur, tgl_faktor=:tgl_faktor, harga_beli=:harga_beli, "
                "harga_jual=:harga_jual, banyak_keluar=:banyak_keluar, kode_barang=:kode_barang WHERE kode_pelanggan=:kode_pelanggan");
    sql.bindValue(":kode_pelanggan",ui->kode_PelangganLineEdit->text());
    sql.bindValue(":no_faktur",ui->no_FakturLineEdit->text());
    sql.bindValue(":tgl_faktor",ui->tgl_FaktorDateEdit->date().toString("yyyy-MM-dd"));
    sql.bindValue(":harga_beli",ui->harga_BeliLineEdit->text());
    sql.bindValue(":harga_jual",ui->harga_JualLineEdit->text());
    sql.bindValue(":banyak_keluar",ui->banyak_KeluarLineEdit->text());
    sql.bindValue(":kode_barang",ui->Kode_BarangLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormPenjualan::on_pushButton_4_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM penjualan WHERE kode_pelanggan=:kode_pelanggan");
    sql.bindValue(":kode_pelanggan",ui->kode_PelangganLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormPenjualan::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    QSqlRecord cari;
    sql.prepare("SELECT * FROM penjualan WHERE kode_pelanggan=:kode_pelanggan");
    sql.bindValue(":kode_pelanggan",ui->kode_PelangganLineEdit->text());

    if (sql.exec()){
        QSqlRecord cari = sql.record();
        // ui->namaLineEdit->setText(cari.value());
        qDebug()<<cari.value(0).toString();
    }else{
        qDebug()<<sql.lastError().text();
    }
}

