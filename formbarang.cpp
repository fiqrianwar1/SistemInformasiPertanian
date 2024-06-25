#include "formbarang.h"
#include "ui_formbarang.h"
#include "QMessageBox"

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

    loadTableBarang();
}

void FormBarang::loadTableBarang()
{
    tabelModel = new QSqlQueryModel(this);
    tabelModel->setQuery("SELECT*FROM barang ORDER BY Kode_barang ASC");
    tabelModel->setHeaderData(0,Qt::Horizontal,QObject::tr("Kode Barang"));
    tabelModel->setHeaderData(1,Qt::Horizontal,QObject::tr("Nama Barang"));
    tabelModel->setHeaderData(2,Qt::Horizontal,QObject::tr("Satuan"));
    tabelModel->setHeaderData(3,Qt::Horizontal,QObject::tr("Harga Beli"));
    tabelModel->setHeaderData(4,Qt::Horizontal,QObject::tr("Harga Jual"));

    ui->tableBarang->setModel(tabelModel);
    ui->tableBarang->setColumnWidth(0,100);
    ui->tableBarang->setColumnWidth(1,250);
    ui->tableBarang->setColumnWidth(2,100);
    ui->tableBarang->setColumnWidth(3,200);
    ui->tableBarang->setColumnWidth(4,200);
    ui->tableBarang->show();
}


FormBarang::~FormBarang()
{
    delete ui;
}

void FormBarang::on_pushButton_clicked()
{
    if(ui->kode_barangLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Kode Barang Belum Di Isi");
        ui->kode_barangLineEdit->setFocus();
    }else if(ui->nama_barangLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Nama Barang Belum Di Isi");
        ui->nama_barangLineEdit->setFocus();
    }else if(ui->satuanComboBox->currentText().isEmpty()){
        QMessageBox::information(this, "warning", "Satuan Belum Di Isi");
        ui->satuanComboBox->setFocus();
    }else if(ui->harga_beliLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Harga Beli Belum Di Isi");
        ui->harga_beliLineEdit->setFocus();
    }else if(ui->harga_jualLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Harga Jual Belum Di Isi");
        ui->harga_jualLineEdit->setFocus();
    }else {
        QSqlQuery duplikat;
        duplikat.prepare("SELECT * FROM barang WHERE Kode_barang = '"+ui->kode_barangLineEdit->text()+"'");
        duplikat.exec();
        if(duplikat.next()){
            QMessageBox::information(this, "warning", "Kode_barang sdh terdaftar");
            ui->nama_barangLineEdit->setText(duplikat.value(1).toString());
            ui->satuanComboBox->setCurrentText(duplikat.value(2).toString());
            ui->harga_beliLineEdit->setText(duplikat.value(3).toString());
            ui->harga_jualLineEdit->setText(duplikat.value(4).toString());
        }else{
            // koneksi.setSatuan(ui->satuanComboBox->currentText());

            QSqlQuery sql (koneksi);
            sql.prepare("INSERT INTO barang (Kode_barang,Nama_barang,Satuan,Harga_beli,Harga_jual)"
                        "VALUE(:Kode_barang,:Nama_barang,:Satuan,:Harga_beli,:Harga_jual)");
            sql.bindValue(":Kode_barang",ui->kode_barangLineEdit->text());
            sql.bindValue(":Nama_barang",ui->nama_barangLineEdit->text());
            sql.bindValue(":Satuan",ui->satuanComboBox->currentText());
            sql.bindValue(":Harga_beli",ui->harga_beliLineEdit->text());
            sql.bindValue(":Harga_jual",ui->harga_jualLineEdit->text());

            if (sql.exec()){
                QMessageBox::information(this, "warning", "Data Berhasil Di simpan");
            }else{
                qDebug()<<sql.lastError().text();
            }
        }
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


void FormBarang::on_tableBarang_activated(const QModelIndex &index)
{
    int baris = ui->tableBarang->currentIndex().row();
    // QMessageBox::information(this, "warning", QString::number(baris));
    ui->kode_barangLineEdit->setText(ui->tableBarang->model()->index(baris,0).data().toString());
    ui->nama_barangLineEdit->setText(ui->tableBarang->model()->index(baris,1).data().toString());
    ui->satuanComboBox->setCurrentText(ui->tableBarang->model()->index(baris,2).data().toString());
    ui->harga_beliLineEdit->setText(ui->tableBarang->model()->index(baris,3).data().toString());
    ui->harga_jualLineEdit->setText(ui->tableBarang->model()->index(baris,4).data().toString());
}
