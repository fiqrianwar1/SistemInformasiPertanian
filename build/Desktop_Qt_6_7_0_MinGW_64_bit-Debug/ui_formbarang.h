/********************************************************************************
** Form generated from reading UI file 'formbarang.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMBARANG_H
#define UI_FORMBARANG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormBarang
{
public:
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *kode_barangLabel;
    QLineEdit *kode_barangLineEdit;
    QLabel *nama_barangLabel;
    QLineEdit *nama_barangLineEdit;
    QLabel *satuanLabel;
    QComboBox *satuanComboBox;
    QLabel *harga_beliLabel;
    QLineEdit *harga_beliLineEdit;
    QLabel *harga_jualLabel;
    QLineEdit *harga_jualLineEdit;
    QTableView *tableBarang;

    void setupUi(QWidget *FormBarang)
    {
        if (FormBarang->objectName().isEmpty())
            FormBarang->setObjectName("FormBarang");
        FormBarang->resize(797, 509);
        pushButton_3 = new QPushButton(FormBarang);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(170, 230, 151, 41));
        pushButton = new QPushButton(FormBarang);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 180, 151, 41));
        pushButton_4 = new QPushButton(FormBarang);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(10, 230, 151, 41));
        pushButton_2 = new QPushButton(FormBarang);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(170, 180, 151, 41));
        formLayoutWidget = new QWidget(FormBarang);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 30, 311, 141));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        kode_barangLabel = new QLabel(formLayoutWidget);
        kode_barangLabel->setObjectName("kode_barangLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, kode_barangLabel);

        kode_barangLineEdit = new QLineEdit(formLayoutWidget);
        kode_barangLineEdit->setObjectName("kode_barangLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, kode_barangLineEdit);

        nama_barangLabel = new QLabel(formLayoutWidget);
        nama_barangLabel->setObjectName("nama_barangLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, nama_barangLabel);

        nama_barangLineEdit = new QLineEdit(formLayoutWidget);
        nama_barangLineEdit->setObjectName("nama_barangLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, nama_barangLineEdit);

        satuanLabel = new QLabel(formLayoutWidget);
        satuanLabel->setObjectName("satuanLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, satuanLabel);

        satuanComboBox = new QComboBox(formLayoutWidget);
        satuanComboBox->addItem(QString());
        satuanComboBox->addItem(QString());
        satuanComboBox->addItem(QString());
        satuanComboBox->addItem(QString());
        satuanComboBox->setObjectName("satuanComboBox");

        formLayout->setWidget(2, QFormLayout::FieldRole, satuanComboBox);

        harga_beliLabel = new QLabel(formLayoutWidget);
        harga_beliLabel->setObjectName("harga_beliLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, harga_beliLabel);

        harga_beliLineEdit = new QLineEdit(formLayoutWidget);
        harga_beliLineEdit->setObjectName("harga_beliLineEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, harga_beliLineEdit);

        harga_jualLabel = new QLabel(formLayoutWidget);
        harga_jualLabel->setObjectName("harga_jualLabel");

        formLayout->setWidget(4, QFormLayout::LabelRole, harga_jualLabel);

        harga_jualLineEdit = new QLineEdit(formLayoutWidget);
        harga_jualLineEdit->setObjectName("harga_jualLineEdit");

        formLayout->setWidget(4, QFormLayout::FieldRole, harga_jualLineEdit);

        tableBarang = new QTableView(FormBarang);
        tableBarang->setObjectName("tableBarang");
        tableBarang->setGeometry(QRect(330, 30, 461, 241));

        retranslateUi(FormBarang);

        QMetaObject::connectSlotsByName(FormBarang);
    } // setupUi

    void retranslateUi(QWidget *FormBarang)
    {
        FormBarang->setWindowTitle(QCoreApplication::translate("FormBarang", "Form", nullptr));
        pushButton_3->setText(QCoreApplication::translate("FormBarang", "Cari", nullptr));
        pushButton->setText(QCoreApplication::translate("FormBarang", "SImpan", nullptr));
        pushButton_4->setText(QCoreApplication::translate("FormBarang", "Hapus", nullptr));
        pushButton_2->setText(QCoreApplication::translate("FormBarang", "Ubah", nullptr));
        kode_barangLabel->setText(QCoreApplication::translate("FormBarang", "Kode Barang", nullptr));
        nama_barangLabel->setText(QCoreApplication::translate("FormBarang", "Nama Barang", nullptr));
        satuanLabel->setText(QCoreApplication::translate("FormBarang", "Satuan", nullptr));
        satuanComboBox->setItemText(0, QCoreApplication::translate("FormBarang", "I", nullptr));
        satuanComboBox->setItemText(1, QCoreApplication::translate("FormBarang", "II", nullptr));
        satuanComboBox->setItemText(2, QCoreApplication::translate("FormBarang", "III", nullptr));
        satuanComboBox->setItemText(3, QCoreApplication::translate("FormBarang", "IV", nullptr));

        harga_beliLabel->setText(QCoreApplication::translate("FormBarang", "Harga Beli", nullptr));
        harga_jualLabel->setText(QCoreApplication::translate("FormBarang", "Harga Jual", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormBarang: public Ui_FormBarang {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMBARANG_H
