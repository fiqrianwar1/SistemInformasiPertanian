/********************************************************************************
** Form generated from reading UI file 'formpenjualan.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPENJUALAN_H
#define UI_FORMPENJUALAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormPenjualan
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLineEdit *kode_PelangganLineEdit;
    QLabel *kode_PelangganLabel;
    QLabel *no_FakturLabel;
    QLineEdit *no_FakturLineEdit;
    QLabel *tgl_FaktorLabel;
    QDateEdit *tgl_FaktorDateEdit;
    QLabel *harga_BeliLabel;
    QLineEdit *harga_BeliLineEdit;
    QLabel *harga_JualLabel;
    QLineEdit *harga_JualLineEdit;
    QLabel *banyak_KeluarLabel;
    QLineEdit *banyak_KeluarLineEdit;
    QLabel *bode_BarangLabel;
    QLineEdit *Kode_BarangLineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTableView *tablePenjualan;

    void setupUi(QWidget *FormPenjualan)
    {
        if (FormPenjualan->objectName().isEmpty())
            FormPenjualan->setObjectName("FormPenjualan");
        FormPenjualan->resize(801, 497);
        formLayoutWidget = new QWidget(FormPenjualan);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(20, 60, 311, 201));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        kode_PelangganLineEdit = new QLineEdit(formLayoutWidget);
        kode_PelangganLineEdit->setObjectName("kode_PelangganLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, kode_PelangganLineEdit);

        kode_PelangganLabel = new QLabel(formLayoutWidget);
        kode_PelangganLabel->setObjectName("kode_PelangganLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, kode_PelangganLabel);

        no_FakturLabel = new QLabel(formLayoutWidget);
        no_FakturLabel->setObjectName("no_FakturLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, no_FakturLabel);

        no_FakturLineEdit = new QLineEdit(formLayoutWidget);
        no_FakturLineEdit->setObjectName("no_FakturLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, no_FakturLineEdit);

        tgl_FaktorLabel = new QLabel(formLayoutWidget);
        tgl_FaktorLabel->setObjectName("tgl_FaktorLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, tgl_FaktorLabel);

        tgl_FaktorDateEdit = new QDateEdit(formLayoutWidget);
        tgl_FaktorDateEdit->setObjectName("tgl_FaktorDateEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, tgl_FaktorDateEdit);

        harga_BeliLabel = new QLabel(formLayoutWidget);
        harga_BeliLabel->setObjectName("harga_BeliLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, harga_BeliLabel);

        harga_BeliLineEdit = new QLineEdit(formLayoutWidget);
        harga_BeliLineEdit->setObjectName("harga_BeliLineEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, harga_BeliLineEdit);

        harga_JualLabel = new QLabel(formLayoutWidget);
        harga_JualLabel->setObjectName("harga_JualLabel");

        formLayout->setWidget(4, QFormLayout::LabelRole, harga_JualLabel);

        harga_JualLineEdit = new QLineEdit(formLayoutWidget);
        harga_JualLineEdit->setObjectName("harga_JualLineEdit");

        formLayout->setWidget(4, QFormLayout::FieldRole, harga_JualLineEdit);

        banyak_KeluarLabel = new QLabel(formLayoutWidget);
        banyak_KeluarLabel->setObjectName("banyak_KeluarLabel");

        formLayout->setWidget(5, QFormLayout::LabelRole, banyak_KeluarLabel);

        banyak_KeluarLineEdit = new QLineEdit(formLayoutWidget);
        banyak_KeluarLineEdit->setObjectName("banyak_KeluarLineEdit");

        formLayout->setWidget(5, QFormLayout::FieldRole, banyak_KeluarLineEdit);

        bode_BarangLabel = new QLabel(formLayoutWidget);
        bode_BarangLabel->setObjectName("bode_BarangLabel");

        formLayout->setWidget(6, QFormLayout::LabelRole, bode_BarangLabel);

        Kode_BarangLineEdit = new QLineEdit(formLayoutWidget);
        Kode_BarangLineEdit->setObjectName("Kode_BarangLineEdit");

        formLayout->setWidget(6, QFormLayout::FieldRole, Kode_BarangLineEdit);

        pushButton_2 = new QPushButton(FormPenjualan);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(180, 270, 151, 41));
        pushButton = new QPushButton(FormPenjualan);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 270, 151, 41));
        pushButton_3 = new QPushButton(FormPenjualan);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(180, 320, 151, 41));
        pushButton_4 = new QPushButton(FormPenjualan);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(20, 320, 151, 41));
        tablePenjualan = new QTableView(FormPenjualan);
        tablePenjualan->setObjectName("tablePenjualan");
        tablePenjualan->setGeometry(QRect(340, 60, 451, 301));

        retranslateUi(FormPenjualan);

        QMetaObject::connectSlotsByName(FormPenjualan);
    } // setupUi

    void retranslateUi(QWidget *FormPenjualan)
    {
        FormPenjualan->setWindowTitle(QCoreApplication::translate("FormPenjualan", "Form", nullptr));
        kode_PelangganLabel->setText(QCoreApplication::translate("FormPenjualan", "Kode Pelanggan", nullptr));
        no_FakturLabel->setText(QCoreApplication::translate("FormPenjualan", "No Faktur", nullptr));
        tgl_FaktorLabel->setText(QCoreApplication::translate("FormPenjualan", "Tanggal Faktor", nullptr));
        harga_BeliLabel->setText(QCoreApplication::translate("FormPenjualan", "Harga Beli", nullptr));
        harga_JualLabel->setText(QCoreApplication::translate("FormPenjualan", "Harga Jual", nullptr));
        banyak_KeluarLabel->setText(QCoreApplication::translate("FormPenjualan", "Banyak Keluar", nullptr));
        bode_BarangLabel->setText(QCoreApplication::translate("FormPenjualan", "Kode Barang", nullptr));
        pushButton_2->setText(QCoreApplication::translate("FormPenjualan", "Ubah", nullptr));
        pushButton->setText(QCoreApplication::translate("FormPenjualan", "SImpan", nullptr));
        pushButton_3->setText(QCoreApplication::translate("FormPenjualan", "Cari", nullptr));
        pushButton_4->setText(QCoreApplication::translate("FormPenjualan", "Hapus", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormPenjualan: public Ui_FormPenjualan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPENJUALAN_H
