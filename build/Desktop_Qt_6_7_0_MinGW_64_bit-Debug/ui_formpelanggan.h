/********************************************************************************
** Form generated from reading UI file 'formpelanggan.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPELANGGAN_H
#define UI_FORMPELANGGAN_H

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

class Ui_FormPelanggan
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *kode_pelangganLabel;
    QLineEdit *kode_pelangganLineEdit;
    QLabel *nama_pelangganLabel;
    QLineEdit *nama_pelangganLineEdit;
    QLabel *alamat_pelangganLabel;
    QLineEdit *alamat_pelangganLineEdit;
    QLabel *telp_pelangganLabel;
    QLineEdit *telp_pelangganLineEdit;
    QLabel *fax_pelangganLabel;
    QLineEdit *fax_pelangganLineEdit;
    QLabel *email_palangganLabel;
    QLineEdit *email_palangganLineEdit;
    QLabel *tglLabel;
    QDateEdit *tglDateEdit;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTableView *tablePelanggan;

    void setupUi(QWidget *FormPelanggan)
    {
        if (FormPelanggan->objectName().isEmpty())
            FormPelanggan->setObjectName("FormPelanggan");
        FormPelanggan->resize(800, 470);
        formLayoutWidget = new QWidget(FormPelanggan);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 70, 311, 201));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        kode_pelangganLabel = new QLabel(formLayoutWidget);
        kode_pelangganLabel->setObjectName("kode_pelangganLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, kode_pelangganLabel);

        kode_pelangganLineEdit = new QLineEdit(formLayoutWidget);
        kode_pelangganLineEdit->setObjectName("kode_pelangganLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, kode_pelangganLineEdit);

        nama_pelangganLabel = new QLabel(formLayoutWidget);
        nama_pelangganLabel->setObjectName("nama_pelangganLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, nama_pelangganLabel);

        nama_pelangganLineEdit = new QLineEdit(formLayoutWidget);
        nama_pelangganLineEdit->setObjectName("nama_pelangganLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, nama_pelangganLineEdit);

        alamat_pelangganLabel = new QLabel(formLayoutWidget);
        alamat_pelangganLabel->setObjectName("alamat_pelangganLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, alamat_pelangganLabel);

        alamat_pelangganLineEdit = new QLineEdit(formLayoutWidget);
        alamat_pelangganLineEdit->setObjectName("alamat_pelangganLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, alamat_pelangganLineEdit);

        telp_pelangganLabel = new QLabel(formLayoutWidget);
        telp_pelangganLabel->setObjectName("telp_pelangganLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, telp_pelangganLabel);

        telp_pelangganLineEdit = new QLineEdit(formLayoutWidget);
        telp_pelangganLineEdit->setObjectName("telp_pelangganLineEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, telp_pelangganLineEdit);

        fax_pelangganLabel = new QLabel(formLayoutWidget);
        fax_pelangganLabel->setObjectName("fax_pelangganLabel");

        formLayout->setWidget(4, QFormLayout::LabelRole, fax_pelangganLabel);

        fax_pelangganLineEdit = new QLineEdit(formLayoutWidget);
        fax_pelangganLineEdit->setObjectName("fax_pelangganLineEdit");

        formLayout->setWidget(4, QFormLayout::FieldRole, fax_pelangganLineEdit);

        email_palangganLabel = new QLabel(formLayoutWidget);
        email_palangganLabel->setObjectName("email_palangganLabel");

        formLayout->setWidget(5, QFormLayout::LabelRole, email_palangganLabel);

        email_palangganLineEdit = new QLineEdit(formLayoutWidget);
        email_palangganLineEdit->setObjectName("email_palangganLineEdit");

        formLayout->setWidget(5, QFormLayout::FieldRole, email_palangganLineEdit);

        tglLabel = new QLabel(formLayoutWidget);
        tglLabel->setObjectName("tglLabel");

        formLayout->setWidget(6, QFormLayout::LabelRole, tglLabel);

        tglDateEdit = new QDateEdit(formLayoutWidget);
        tglDateEdit->setObjectName("tglDateEdit");

        formLayout->setWidget(6, QFormLayout::FieldRole, tglDateEdit);

        pushButton_3 = new QPushButton(FormPelanggan);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(170, 330, 151, 41));
        pushButton_4 = new QPushButton(FormPelanggan);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(10, 330, 151, 41));
        pushButton = new QPushButton(FormPelanggan);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 280, 151, 41));
        pushButton_2 = new QPushButton(FormPelanggan);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(170, 280, 151, 41));
        tablePelanggan = new QTableView(FormPelanggan);
        tablePelanggan->setObjectName("tablePelanggan");
        tablePelanggan->setGeometry(QRect(330, 70, 461, 301));

        retranslateUi(FormPelanggan);

        QMetaObject::connectSlotsByName(FormPelanggan);
    } // setupUi

    void retranslateUi(QWidget *FormPelanggan)
    {
        FormPelanggan->setWindowTitle(QCoreApplication::translate("FormPelanggan", "Form", nullptr));
        kode_pelangganLabel->setText(QCoreApplication::translate("FormPelanggan", "Kode Pelanggan", nullptr));
        nama_pelangganLabel->setText(QCoreApplication::translate("FormPelanggan", "Nama Pelanggan", nullptr));
        alamat_pelangganLabel->setText(QCoreApplication::translate("FormPelanggan", "Alamat Pelanggan", nullptr));
        telp_pelangganLabel->setText(QCoreApplication::translate("FormPelanggan", "Telp Pelanggan", nullptr));
        fax_pelangganLabel->setText(QCoreApplication::translate("FormPelanggan", "Fax Pelanggan", nullptr));
        email_palangganLabel->setText(QCoreApplication::translate("FormPelanggan", "Email Palanggan", nullptr));
        tglLabel->setText(QCoreApplication::translate("FormPelanggan", "Tanggal", nullptr));
        pushButton_3->setText(QCoreApplication::translate("FormPelanggan", "Cari", nullptr));
        pushButton_4->setText(QCoreApplication::translate("FormPelanggan", "Hapus", nullptr));
        pushButton->setText(QCoreApplication::translate("FormPelanggan", "SImpan", nullptr));
        pushButton_2->setText(QCoreApplication::translate("FormPelanggan", "Ubah", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormPelanggan: public Ui_FormPelanggan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPELANGGAN_H
