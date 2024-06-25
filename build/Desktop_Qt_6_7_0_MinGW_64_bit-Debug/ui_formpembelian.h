/********************************************************************************
** Form generated from reading UI file 'formpembelian.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPEMBELIAN_H
#define UI_FORMPEMBELIAN_H

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

class Ui_FormPembelian
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *kode_barangLabel;
    QLineEdit *kode_barangLineEdit;
    QLabel *kode_supplierLabel;
    QLineEdit *kode_supplierLineEdit;
    QLabel *no_fakturLabel;
    QLineEdit *no_fakturLineEdit;
    QLabel *tgl_fakturLabel;
    QLabel *harga_jualLabel;
    QLineEdit *harga_jualLineEdit;
    QLabel *harga_beliLabel;
    QLineEdit *harga_beliLineEdit;
    QLabel *banyak_keluarLabel;
    QLineEdit *banyak_keluarLineEdit;
    QDateEdit *tgl_fakturDateEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QTableView *tablePembelian;

    void setupUi(QWidget *FormPembelian)
    {
        if (FormPembelian->objectName().isEmpty())
            FormPembelian->setObjectName("FormPembelian");
        FormPembelian->resize(800, 382);
        formLayoutWidget = new QWidget(FormPembelian);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(9, 29, 311, 201));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        kode_barangLabel = new QLabel(formLayoutWidget);
        kode_barangLabel->setObjectName("kode_barangLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, kode_barangLabel);

        kode_barangLineEdit = new QLineEdit(formLayoutWidget);
        kode_barangLineEdit->setObjectName("kode_barangLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, kode_barangLineEdit);

        kode_supplierLabel = new QLabel(formLayoutWidget);
        kode_supplierLabel->setObjectName("kode_supplierLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, kode_supplierLabel);

        kode_supplierLineEdit = new QLineEdit(formLayoutWidget);
        kode_supplierLineEdit->setObjectName("kode_supplierLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, kode_supplierLineEdit);

        no_fakturLabel = new QLabel(formLayoutWidget);
        no_fakturLabel->setObjectName("no_fakturLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, no_fakturLabel);

        no_fakturLineEdit = new QLineEdit(formLayoutWidget);
        no_fakturLineEdit->setObjectName("no_fakturLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, no_fakturLineEdit);

        tgl_fakturLabel = new QLabel(formLayoutWidget);
        tgl_fakturLabel->setObjectName("tgl_fakturLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, tgl_fakturLabel);

        harga_jualLabel = new QLabel(formLayoutWidget);
        harga_jualLabel->setObjectName("harga_jualLabel");

        formLayout->setWidget(4, QFormLayout::LabelRole, harga_jualLabel);

        harga_jualLineEdit = new QLineEdit(formLayoutWidget);
        harga_jualLineEdit->setObjectName("harga_jualLineEdit");

        formLayout->setWidget(4, QFormLayout::FieldRole, harga_jualLineEdit);

        harga_beliLabel = new QLabel(formLayoutWidget);
        harga_beliLabel->setObjectName("harga_beliLabel");

        formLayout->setWidget(5, QFormLayout::LabelRole, harga_beliLabel);

        harga_beliLineEdit = new QLineEdit(formLayoutWidget);
        harga_beliLineEdit->setObjectName("harga_beliLineEdit");

        formLayout->setWidget(5, QFormLayout::FieldRole, harga_beliLineEdit);

        banyak_keluarLabel = new QLabel(formLayoutWidget);
        banyak_keluarLabel->setObjectName("banyak_keluarLabel");

        formLayout->setWidget(6, QFormLayout::LabelRole, banyak_keluarLabel);

        banyak_keluarLineEdit = new QLineEdit(formLayoutWidget);
        banyak_keluarLineEdit->setObjectName("banyak_keluarLineEdit");

        formLayout->setWidget(6, QFormLayout::FieldRole, banyak_keluarLineEdit);

        tgl_fakturDateEdit = new QDateEdit(formLayoutWidget);
        tgl_fakturDateEdit->setObjectName("tgl_fakturDateEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, tgl_fakturDateEdit);

        pushButton_2 = new QPushButton(FormPembelian);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(170, 240, 151, 41));
        pushButton_3 = new QPushButton(FormPembelian);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(170, 290, 151, 41));
        pushButton = new QPushButton(FormPembelian);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 240, 151, 41));
        pushButton_4 = new QPushButton(FormPembelian);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(10, 290, 151, 41));
        tablePembelian = new QTableView(FormPembelian);
        tablePembelian->setObjectName("tablePembelian");
        tablePembelian->setGeometry(QRect(330, 30, 461, 301));

        retranslateUi(FormPembelian);

        QMetaObject::connectSlotsByName(FormPembelian);
    } // setupUi

    void retranslateUi(QWidget *FormPembelian)
    {
        FormPembelian->setWindowTitle(QCoreApplication::translate("FormPembelian", "Form", nullptr));
        kode_barangLabel->setText(QCoreApplication::translate("FormPembelian", "Kode Barang", nullptr));
        kode_supplierLabel->setText(QCoreApplication::translate("FormPembelian", "Kode Supplier", nullptr));
        no_fakturLabel->setText(QCoreApplication::translate("FormPembelian", "No Faktur", nullptr));
        tgl_fakturLabel->setText(QCoreApplication::translate("FormPembelian", "Tanggal Faktur", nullptr));
        harga_jualLabel->setText(QCoreApplication::translate("FormPembelian", "Harga Jual", nullptr));
        harga_beliLabel->setText(QCoreApplication::translate("FormPembelian", "Harga Beli", nullptr));
        banyak_keluarLabel->setText(QCoreApplication::translate("FormPembelian", "Banyak Keluar", nullptr));
        pushButton_2->setText(QCoreApplication::translate("FormPembelian", "Ubah", nullptr));
        pushButton_3->setText(QCoreApplication::translate("FormPembelian", "Cari", nullptr));
        pushButton->setText(QCoreApplication::translate("FormPembelian", "SImpan", nullptr));
        pushButton_4->setText(QCoreApplication::translate("FormPembelian", "Hapus", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormPembelian: public Ui_FormPembelian {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPEMBELIAN_H
