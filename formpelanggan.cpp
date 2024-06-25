#include "formpelanggan.h"
#include "ui_formpelanggan.h"
#include "QMessageBox"

FormPelanggan::FormPelanggan(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormPelanggan)
{
    ui->setupUi(this);

    loadTablePelanggan();
}

FormPelanggan::~FormPelanggan()
{
    delete ui;
}

void FormPelanggan::loadTablePelanggan()
{
    tabelModel = new QSqlQueryModel(this);
    tabelModel->setQuery("SELECT*FROM pelanggan ORDER BY kode_pelanggan ASC");
    tabelModel->setHeaderData(0,Qt::Horizontal,QObject::tr("Kode Pelanggan"));
    tabelModel->setHeaderData(1,Qt::Horizontal,QObject::tr("Nama Pelanggan"));
    tabelModel->setHeaderData(2,Qt::Horizontal,QObject::tr("Alamat Pelanggan"));
    tabelModel->setHeaderData(3,Qt::Horizontal,QObject::tr("Telp Pelanggan"));
    tabelModel->setHeaderData(4,Qt::Horizontal,QObject::tr("Fax Pelanggan"));
    tabelModel->setHeaderData(5,Qt::Horizontal,QObject::tr("Email Palanggan"));
    tabelModel->setHeaderData(6,Qt::Horizontal,QObject::tr("Tanggal"));

    ui->tablePelanggan->setModel(tabelModel);
    ui->tablePelanggan->setColumnWidth(0,100);
    ui->tablePelanggan->setColumnWidth(1,200);
    ui->tablePelanggan->setColumnWidth(2,250);
    ui->tablePelanggan->setColumnWidth(3,100);
    ui->tablePelanggan->setColumnWidth(4,100);
    ui->tablePelanggan->setColumnWidth(5,200);
    ui->tablePelanggan->setColumnWidth(6,250);
    ui->tablePelanggan->show();
}

void FormPelanggan::on_pushButton_clicked()
{
    if(ui->kode_pelangganLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Kode Pelanggan Belum Di Isi");
        ui->kode_pelangganLineEdit->setFocus();
    }else if(ui->nama_pelangganLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Nama Pelanggan Belum Di Isi");
        ui->nama_pelangganLineEdit->setFocus();
    }else if(ui->alamat_pelangganLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Alamat Pelanggan Belum Di Isi");
        ui->alamat_pelangganLineEdit->setFocus();
    }else if(ui->telp_pelangganLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Telp Pelanggan Belum Di Isi");
        ui->telp_pelangganLineEdit->setFocus();
    }else if(ui->fax_pelangganLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Fax Pelanggan Belum Di Isi");
        ui->fax_pelangganLineEdit->setFocus();
    }else if(ui->email_palangganLineEdit->text().isEmpty()){
        QMessageBox::information(this, "warning", "Email Palanggan Belum Di Isi");
        ui->email_palangganLineEdit->setFocus();
    }else if(ui->tglDateEdit->date().toString("yyyy-MM-dd").isEmpty()){
        QMessageBox::information(this, "warning", "Tanggal Belum Di Isi");
        ui->tglDateEdit->setFocus();
    }else {
        QSqlQuery duplikat;
        duplikat.prepare("SELECT * FROM penjualan WHERE kode_pelanggan = '"+ui->kode_pelangganLineEdit->text()+"'");
        duplikat.exec();
        if(duplikat.next()){
            QMessageBox::information(this, "warning", "kode_pelanggan sdh terdaftar");
            ui->nama_pelangganLineEdit->setText(duplikat.value(1).toString());
            ui->alamat_pelangganLineEdit->setText(duplikat.value(2).toString());
            ui->telp_pelangganLineEdit->setText(duplikat.value(3).toString());
            ui->fax_pelangganLineEdit->setText(duplikat.value(4).toString());
            ui->email_palangganLineEdit->setText(duplikat.value(5).toString());
            ui->tglDateEdit->setDate(duplikat.value(6).toDate());
        }else{
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
                QMessageBox::information(this, "warning", "Data Berhasil Di simpan");
            }else{
                qDebug()<<sql.lastError().text();
            }
        }
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


void FormPelanggan::on_tablePelanggan_activated(const QModelIndex &index)
{
    int baris = ui->tablePelanggan->currentIndex().row();
    // QMessageBox::information(this, "warning", QString::number(baris));
    ui->kode_pelangganLineEdit->setText(ui->tablePelanggan->model()->index(baris,0).data().toString());
    ui->nama_pelangganLineEdit->setText(ui->tablePelanggan->model()->index(baris,1).data().toString());
    ui->alamat_pelangganLineEdit->setText(ui->tablePelanggan->model()->index(baris,2).data().toString());
    ui->telp_pelangganLineEdit->setText(ui->tablePelanggan->model()->index(baris,3).data().toString());
    ui->fax_pelangganLineEdit->setText(ui->tablePelanggan->model()->index(baris,4).data().toString());
    ui->email_palangganLineEdit->setText(ui->tablePelanggan->model()->index(baris,5).data().toString());
    ui->tglDateEdit->setDate(ui->tablePelanggan->model()->index(baris,6).data().toDate());
}

