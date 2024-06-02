#include "formbarang.h"
#include "ui_formbarang.h"

FormBarang::FormBarang(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormBarang)
{
    ui->setupUi(this);

    QSqlDatabase koneksi = QSqlDatabase::addDatabase("QODBC");
    koneksi.setDatabaseName("dsn_pertanian");
    koneksi.setUserName("root");
    koneksi.setPassword("");

    if(!koneksi.open()){
        qDebug()<<koneksi.lastError().text();
    }else{
        qDebug()<<"Database Terkoneksi";

    }
}

FormBarang::~FormBarang()
{
    delete ui;
}

void FormBarang::on_pushButton_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("INSERT INTO barang (Kode_barang,Nama_barang,Satuan,Harga_beli,Harga_jual)"
                "VALUE (:Kode_barang,:Nama_barang,:Satuan,:Harga_beli,:Harga_jual)");
    sql.bindValue(":Kode_barang",ui->kode_barangLineEdit->text());
    sql.bindValue(":Nama_barang",ui->nama_barangLineEdit->text());
    sql.bindValue(":Satuan",ui->satuanComboBox->currentText());
    sql.bindValue(":Harga_beli",ui->harga_beliLineEdit->text());
    sql.bindValue(":Harga_jual",ui->harga_jualLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Simpan";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormBarang::on_pushButton_2_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("UPDATE barang SET Nama_barang=:Nama_barang, Satuan=:Satuan, Harga_beli=:Harga_beli, "
                "Harga_jual=:Harga_jual WHERE Kode_barang=:Kode_barang");
    sql.bindValue(":Kode_barang",ui->kode_barangLineEdit->text());
    sql.bindValue(":Nama_barang",ui->nama_barangLineEdit->text());
    sql.bindValue(":Satuan",ui->satuanComboBox->currentText());
    sql.bindValue(":Harga_beli",ui->harga_beliLineEdit->text());
    sql.bindValue(":Harga_jual",ui->harga_jualLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormBarang::on_pushButton_4_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM barang WHERE kode_barang=:Kode_barang");
    sql.bindValue(":Kode_barang",ui->kode_barangLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormBarang::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    QSqlRecord cari;
    sql.prepare("SELECT * FROM barang WHERE Kode_barang=:Kode_barang");
    sql.bindValue(":Kode_barang",ui->kode_barangLineEdit->text());

    if (sql.exec()){
        QSqlRecord cari = sql.record();
        // ui->namaLineEdit->setText(cari.value());
        qDebug()<<cari.value(0).toString();
    }else{
        qDebug()<<sql.lastError().text();
    }
}

