#ifndef HALUTAMA_H
#define HALUTAMA_H

#include <QMainWindow>
#include <formbarang.h>
#include <formpenjualan.h>
#include <formpelanggan.h>
#include <formsupplier.h>
#include <formpembelian.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class HalUtama;
}
QT_END_NAMESPACE

class HalUtama : public QMainWindow
{
    Q_OBJECT

public:
    HalUtama(QWidget *parent = nullptr);
    ~HalUtama();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::HalUtama *ui;
    FormBarang *barForm;
    FormPenjualan *penForm;
    FormPelanggan *pelForm;
    Formsupplier *supForm;
    FormPembelian *pemForm;
};
#endif // HALUTAMA_H
