#include "formsupplier.h"
#include "ui_formsupplier.h"
#include "QMessageBox"

Formsupplier::Formsupplier(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Formsupplier)
{
    ui->setupUi(this);

    loadTableSupplier();
}

Formsupplier::~Formsupplier()
{
    delete ui;
}

void Formsupplier::loadTableSupplier()
{
    tabelModel = new QSqlQueryModel(this);
    tabelModel->setQuery("SELECT*FROM suppier ORDER BY kode_supplier ASC");
    tabelModel->setHeaderData(0,Qt::Horizontal,QObject::tr("Nama Supplier"));
    tabelModel->setHeaderData(1,Qt::Horizontal,QObject::tr("Kode Supplier"));
    tabelModel->setHeaderData(2,Qt::Horizontal,QObject::tr("Alamat Supplier"));
    tabelModel->setHeaderData(3,Qt::Horizontal,QObject::tr("Telp Supplier"));
    tabelModel->setHeaderData(4,Qt::Horizontal,QObject::tr("Fax Supplier"));
    tabelModel->setHeaderData(5,Qt::Horizontal,QObject::tr("Email Supplier"));

    ui->tableSupplier->setModel(tabelModel);
    ui->tableSupplier->setColumnWidth(0,200);
    ui->tableSupplier->setColumnWidth(1,100);
    ui->tableSupplier->setColumnWidth(2,250);
    ui->tableSupplier->setColumnWidth(3,100);
    ui->tableSupplier->setColumnWidth(4,100);
    ui->tableSupplier->setColumnWidth(5,200);
    ui->tableSupplier->show();
}

void Formsupplier::on_pushButton_clicked()
{
    if(ui->nama_supplierLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Nama Supplier Belum Di Isi");
        ui->nama_supplierLineEdit->setFocus();
    }else if(ui->kode_supplierLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Kode Pelanggan Belum Di Isi");
        ui->kode_supplierLineEdit->setFocus();
    }else if(ui->alamat_supplierLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Alamat Pelanggan Belum Di Isi");
        ui->alamat_supplierLineEdit->setFocus();
    }else if(ui->telp_supplierLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Telp Pelanggan Belum Di Isi");
        ui->telp_supplierLineEdit->setFocus();
    }else if(ui->fax_supplierLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Fax Pelanggan Belum Di Isi");
        ui->fax_supplierLineEdit->setFocus();
    }else if(ui->email_supplierLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Email Supplier Belum Di Isi");
        ui->email_supplierLineEdit->setFocus();
    }else {
        QSqlQuery duplikat;
        duplikat.prepare("SELECT * FROM suppier WHERE kode_supplier = '"+ui->kode_supplierLineEdit->text()+"'");
        duplikat.exec();
        if(duplikat.next()){
            QMessageBox::information(this, "warning", "kode_pelanggan sdh terdaftar");
            ui->nama_supplierLineEdit->setText(duplikat.value(1).toString());
            ui->alamat_supplierLineEdit->setText(duplikat.value(2).toString());
            ui->telp_supplierLineEdit->setText(duplikat.value(3).toString());
            ui->fax_supplierLineEdit->setText(duplikat.value(4).toString());
            ui->email_supplierLineEdit->setText(duplikat.value(5).toString());
        }else{
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
                QMessageBox::information(this, "warning", "Data Berhasil Di simpan");
            }else{
                qDebug()<<sql.lastError().text();
            }
        }
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


void Formsupplier::on_tableSupplier_activated(const QModelIndex &index)
{
    int baris = ui->tableSupplier->currentIndex().row();
    // QMessageBox::information(this, "warning", QString::number(baris));
    ui->nama_supplierLineEdit->setText(ui->tableSupplier->model()->index(baris,0).data().toString());
    ui->kode_supplierLineEdit->setText(ui->tableSupplier->model()->index(baris,1).data().toString());
    ui->alamat_supplierLineEdit->setText(ui->tableSupplier->model()->index(baris,2).data().toString());
    ui->telp_supplierLineEdit->setText(ui->tableSupplier->model()->index(baris,3).data().toString());
    ui->fax_supplierLineEdit->setText(ui->tableSupplier->model()->index(baris,4).data().toString());
    ui->email_supplierLineEdit->setText(ui->tableSupplier->model()->index(baris,5).data().toString());
}

