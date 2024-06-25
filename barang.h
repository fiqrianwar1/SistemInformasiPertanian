#ifndef BARANG_H
#define BARANG_H
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

class barang
{
public:
    barang();
    barang(QString kode_barang, QString nama_barang,
           QString satuan, QString harga_beli, QString harga_jual);

    void setKodeBarang(QString KodeBarang);
    QString getKodebarang();

    void setNamaBarang(QString NamaBarang);
    QString getNamaBarang();

    void setSatuan(QString Satuan);
    QString getSatuan();

    void setHargaBeli(QString HargaBeli);
    QString getHargaBeli();

    void setHargaJual(QString HargaJual);
    QString getHargaJual();
}

private:

    QSqlDatabase koneksiDB;
};

#endif // BARANG_H
