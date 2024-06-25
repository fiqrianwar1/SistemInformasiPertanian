#include "formpembelian.h"
#include "ui_formpembelian.h"
#include "QMessageBox"

FormPembelian::FormPembelian(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormPembelian)
{
    ui->setupUi(this);

    loadTablePembelian();
}

FormPembelian::~FormPembelian()
{
    delete ui;
}

void FormPembelian::loadTablePembelian()
{
    tabelModel = new QSqlQueryModel(this);
    tabelModel->setQuery("SELECT*FROM pembelian ORDER BY no_faktur ASC");
    tabelModel->setHeaderData(0,Qt::Horizontal,QObject::tr("Kode Barang"));
    tabelModel->setHeaderData(1,Qt::Horizontal,QObject::tr("Kode Supplier"));
    tabelModel->setHeaderData(2,Qt::Horizontal,QObject::tr("No Faktur"));
    tabelModel->setHeaderData(3,Qt::Horizontal,QObject::tr("Tanggal Faktur"));
    tabelModel->setHeaderData(4,Qt::Horizontal,QObject::tr("Harga Jual"));
    tabelModel->setHeaderData(5,Qt::Horizontal,QObject::tr("Harga Beli"));
    tabelModel->setHeaderData(6,Qt::Horizontal,QObject::tr("Banyak Keluar"));

    ui->tablePembelian->setModel(tabelModel);
    ui->tablePembelian->setColumnWidth(0,100);
    ui->tablePembelian->setColumnWidth(1,100);
    ui->tablePembelian->setColumnWidth(2,100);
    ui->tablePembelian->setColumnWidth(3,200);
    ui->tablePembelian->setColumnWidth(4,200);
    ui->tablePembelian->setColumnWidth(5,200);
    ui->tablePembelian->setColumnWidth(6,100);
    ui->tablePembelian->show();
}

void FormPembelian::on_pushButton_clicked()
{
    if(ui->kode_barangLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Kode Barang Belum Di Isi");
        ui->kode_barangLineEdit->setFocus();
    }else if(ui->kode_supplierLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Kode Supplier Belum Di Isi");
        ui->kode_supplierLineEdit->setFocus();
    }else if(ui->no_fakturLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "No Faktur Belum Di Isi");
        ui->no_fakturLineEdit->setFocus();
    }else if(ui->tgl_fakturDateEdit->date().toString("yyyy-MM-dd").isEmpty()){
        QMessageBox::information(this, "warning", "Tanggal Faktur Belum Di Isi");
        ui->tgl_fakturDateEdit->setFocus();
    }else if(ui->harga_jualLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Harga Jual Belum Di Isi");
        ui->harga_jualLineEdit->setFocus();
    }else if(ui->harga_beliLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Harga Beli Belum Di Isi");
        ui->harga_beliLineEdit->setFocus();
    }else if(ui->banyak_keluarLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Banyak Keluar Belum Di Isi");
        ui->banyak_keluarLineEdit->setFocus();
    }else {
        QSqlQuery duplikat;
        duplikat.prepare("SELECT * FROM pembelian WHERE no_faktur = '"+ui->no_fakturLineEdit->text()+"'");
        duplikat.exec();
        if(duplikat.next()){
            QMessageBox::information(this, "warning", "no_faktur sdh terdaftar");
            ui->kode_barangLineEdit->setText(duplikat.value(1).toString());
            ui->kode_supplierLineEdit->setText(duplikat.value(2).toString());
            ui->tgl_fakturDateEdit->setDate(duplikat.value(3).toDate());
            ui->harga_jualLineEdit->setText(duplikat.value(4).toString());
            ui->harga_beliLineEdit->setText(duplikat.value(5).toString());
            ui->banyak_keluarLineEdit->setText(duplikat.value(6).toString());
        }else{
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
                QMessageBox::information(this, "warning", "Data Berhasil Di simpan");
            }else{
                qDebug()<<sql.lastError().text();
            }
        }
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


void FormPembelian::on_tablePembelian_activated(const QModelIndex &index)
{
    int baris = ui->tablePembelian->currentIndex().row();
    // QMessageBox::information(this, "warning", QString::number(baris));
    ui->kode_barangLineEdit->setText(ui->tablePembelian->model()->index(baris,0).data().toString());
    ui->kode_supplierLineEdit->setText(ui->tablePembelian->model()->index(baris,1).data().toString());
    ui->no_fakturLineEdit->setText(ui->tablePembelian->model()->index(baris,2).data().toString());
    ui->tgl_fakturDateEdit->setDate(ui->tablePembelian->model()->index(baris,3).data().toDate());
    ui->harga_jualLineEdit->setText(ui->tablePembelian->model()->index(baris,4).data().toString());
    ui->harga_beliLineEdit->setText(ui->tablePembelian->model()->index(baris,5).data().toString());
    ui->banyak_keluarLineEdit->setText(ui->tablePembelian->model()->index(baris,6).data().toString());
}

