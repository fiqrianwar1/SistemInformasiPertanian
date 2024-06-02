#include "formpelanggan.h"
#include "ui_formpelanggan.h"

FormPelanggan::FormPelanggan(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormPelanggan)
{
    ui->setupUi(this);
}

FormPelanggan::~FormPelanggan()
{
    delete ui;
}

void FormPelanggan::on_pushButton_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("INSERT INTO pelanggan (kode_pelanggan,nama_pelanggan,alamat_pelanggan,telp_pelanggan,fax_pelanggan,email_palanggan,tgl)"
                "VALUE (:kode_pelanggan,:nama_pelanggan,:alamat_pelanggan,:telp_pelanggan,:fax_pelanggan,:email_palanggan,:tgl)");
    sql.bindValue(":kode_pelanggan",ui->kode_pelangganLineEdit->text());
    sql.bindValue(":nama_pelanggan",ui->nama_pelangganLineEdit->text());
    sql.bindValue(":alamat_pelanggan",ui->alamat_pelangganLineEdit->text());
    sql.bindValue(":telp_pelanggan",ui->telp_pelangganLineEdit->text());
    sql.bindValue(":fax_pelanggan",ui->fax_pelangganLineEdit->text());
    sql.bindValue(":email_palanggan",ui->email_palangganLineEdit->text());
    sql.bindValue(":tgl",ui->tglDateEdit->date().toString("yyyy-MM-dd"));

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Simpan";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormPelanggan::on_pushButton_2_clicked()
{
    QSqlQuery sql (koneksi);
    sql.prepare("UPDATE pelanggan SET nama_pelanggan=:nama_pelanggan, alamat_pelanggan=:alamat_pelanggan, telp_pelanggan=:telp_pelanggan, "
                "fax_pelanggan=:fax_pelanggan, email_palanggan=:email_palanggan, tgl=:tgl WHERE kode_pelanggan=:kode_pelanggan");
    sql.bindValue(":kode_pelanggan",ui->kode_pelangganLineEdit->text());
    sql.bindValue(":nama_pelanggan",ui->nama_pelangganLineEdit->text());
    sql.bindValue(":alamat_pelanggan",ui->alamat_pelangganLineEdit->text());
    sql.bindValue(":telp_pelanggan",ui->telp_pelangganLineEdit->text());
    sql.bindValue(":fax_pelanggan",ui->fax_pelangganLineEdit->text());
    sql.bindValue(":email_palanggan",ui->email_palangganLineEdit->text());
    sql.bindValue(":tgl",ui->tglDateEdit->date().toString("yyyy-MM-dd"));

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Ubah";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormPelanggan::on_pushButton_4_clicked()
{
    QSqlQuery sql(koneksi);
    sql.prepare("DELETE FROM pelanggan WHERE kode_pelanggan=:kode_pelanggan");
    sql.bindValue(":kode_pelanggan",ui->kode_pelangganLineEdit->text());

    if (sql.exec()){
        qDebug()<<"Data Berhasil Di Hapus";
    }else{
        qDebug()<<sql.lastError().text();
    }
}


void FormPelanggan::on_pushButton_3_clicked()
{
    QSqlQuery sql(koneksi);
    QSqlRecord cari;
    sql.prepare("SELECT * FROM pelanggan WHERE kode_pelanggan=:kode_pelanggan");
    sql.bindValue(":kode_pelanggan",ui->kode_pelangganLineEdit->text());

    if (sql.exec()){
        QSqlRecord cari = sql.record();
        // ui->namaLineEdit->setText(cari.value());
        qDebug()<<cari.value(0).toString();
    }else{
        qDebug()<<sql.lastError().text();
    }
}

