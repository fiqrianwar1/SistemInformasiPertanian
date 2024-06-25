#include "formpenjualan.h"
#include "ui_formpenjualan.h"
#include "QMessageBox"

FormPenjualan::FormPenjualan(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormPenjualan)
{
    ui->setupUi(this);

    loadTablePenjualan();
}

FormPenjualan::~FormPenjualan()
{
    delete ui;
}

void FormPenjualan::loadTablePenjualan()
{
    tabelModel = new QSqlQueryModel(this);
    tabelModel->setQuery("SELECT*FROM penjualan ORDER BY kode_pelanggan ASC");
    tabelModel->setHeaderData(0,Qt::Horizontal,QObject::tr("Kode Pelanggan"));
    tabelModel->setHeaderData(1,Qt::Horizontal,QObject::tr("No Faktur"));
    tabelModel->setHeaderData(2,Qt::Horizontal,QObject::tr("Tanggal Faktor"));
    tabelModel->setHeaderData(3,Qt::Horizontal,QObject::tr("Harga Beli"));
    tabelModel->setHeaderData(4,Qt::Horizontal,QObject::tr("Harga Jual"));
    tabelModel->setHeaderData(5,Qt::Horizontal,QObject::tr("Banyak Keluar"));
    tabelModel->setHeaderData(6,Qt::Horizontal,QObject::tr("Kode Barang"));

    ui->tablePenjualan->setModel(tabelModel);
    ui->tablePenjualan->setColumnWidth(0,100);
    ui->tablePenjualan->setColumnWidth(1,250);
    ui->tablePenjualan->setColumnWidth(2,100);
    ui->tablePenjualan->setColumnWidth(3,200);
    ui->tablePenjualan->setColumnWidth(4,200);
    ui->tablePenjualan->setColumnWidth(5,250);
    ui->tablePenjualan->setColumnWidth(6,100);
    ui->tablePenjualan->show();
}

void FormPenjualan::on_pushButton_clicked()
{
    if(ui->kode_PelangganLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Kode Pelanggan Belum Di Isi");
        ui->kode_PelangganLineEdit->setFocus();
    }else if(ui->no_FakturLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "No Faktur Belum Di Isi");
        ui->no_FakturLineEdit->setFocus();
    }else if(ui->tgl_FaktorDateEdit->date().toString("yyyy-MM-dd").isEmpty()){
        QMessageBox::information(this, "warning", "Tanggal Faktor Belum Di Isi");
        ui->tgl_FaktorDateEdit->setFocus();
    }else if(ui->harga_BeliLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Harga Beli Belum Di Isi");
        ui->harga_BeliLineEdit->setFocus();
    }else if(ui->harga_JualLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Harga Jual Belum Di Isi");
        ui->harga_JualLineEdit->setFocus();
    }else if(ui->banyak_KeluarLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Banyak Keluar Belum Di Isi");
        ui->banyak_KeluarLineEdit->setFocus();
    }else if(ui->Kode_BarangLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Kode Barang Belum Di Isi");
        ui->Kode_BarangLineEdit->setFocus();
    }else {
        QSqlQuery duplikat;
        duplikat.prepare("SELECT * FROM penjualan WHERE kode_pelanggan = '"+ui->kode_PelangganLineEdit->text()+"'");
        duplikat.exec();
        if(duplikat.next()){
            QMessageBox::information(this, "warning", "kode_pelanggan sdh terdaftar");
            ui->no_FakturLineEdit->setText(duplikat.value(1).toString());
            ui->tgl_FaktorDateEdit->setDate(duplikat.value(2).toDate());
            ui->harga_BeliLineEdit->setText(duplikat.value(3).toString());
            ui->harga_JualLineEdit->setText(duplikat.value(4).toString());
            ui->banyak_KeluarLineEdit->setText(duplikat.value(5).toString());
            ui->Kode_BarangLineEdit->setText(duplikat.value(6).toString());
        }else{
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
                QMessageBox::information(this, "warning", "Data Berhasil Di simpan");
            }else{
                qDebug()<<sql.lastError().text();
            }
        }
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


void FormPenjualan::on_tablePenjualan_activated(const QModelIndex &index)
{
    int baris = ui->tablePenjualan->currentIndex().row();
    // QMessageBox::information(this, "warning", QString::number(baris));
    ui->kode_PelangganLineEdit->setText(ui->tablePenjualan->model()->index(baris,0).data().toString());
    ui->no_FakturLineEdit->setText(ui->tablePenjualan->model()->index(baris,1).data().toString());
    ui->tgl_FaktorDateEdit->setDate(ui->tablePenjualan->model()->index(baris,2).data().toDate());
    ui->harga_BeliLineEdit->setText(ui->tablePenjualan->model()->index(baris,3).data().toString());
    ui->harga_JualLineEdit->setText(ui->tablePenjualan->model()->index(baris,4).data().toString());
    ui->banyak_KeluarLineEdit->setText(ui->tablePenjualan->model()->index(baris,5).data().toString());
    ui->Kode_BarangLineEdit->setText(ui->tablePenjualan->model()->index(baris,6).data().toString());
}

