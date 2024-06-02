#include "halutama.h"
#include "ui_halutama.h"
#include <qstring.h>

HalUtama::HalUtama(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HalUtama)
{
    ui->setupUi(this);
    barForm = new FormBarang;
    penForm = new FormPenjualan;
    pelForm = new FormPelanggan;
    supForm = new Formsupplier;
    pemForm = new FormPembelian;
}

HalUtama::~HalUtama()
{
    delete ui;
}

void HalUtama::on_pushButton_clicked()
{
    barForm->show();
}


void HalUtama::on_pushButton_2_clicked()
{
    penForm->show();
}


void HalUtama::on_pushButton_3_clicked()
{
    pelForm->show();
}


void HalUtama::on_pushButton_4_clicked()
{
    supForm->show();
}


void HalUtama::on_pushButton_5_clicked()
{
    pemForm->show();
}

