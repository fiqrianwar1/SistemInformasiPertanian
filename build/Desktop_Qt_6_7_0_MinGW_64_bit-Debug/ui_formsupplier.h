/********************************************************************************
** Form generated from reading UI file 'formsupplier.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSUPPLIER_H
#define UI_FORMSUPPLIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Formsupplier
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *nama_supplierLabel;
    QLineEdit *nama_supplierLineEdit;
    QLabel *kode_supplierLabel;
    QLineEdit *kode_supplierLineEdit;
    QLabel *alamat_suppierLabel;
    QLineEdit *alamat_supplierLineEdit;
    QLabel *telp_suppierLabel;
    QLineEdit *telp_supplierLineEdit;
    QLabel *fax_supplierLabel;
    QLineEdit *fax_supplierLineEdit;
    QLabel *email_suppierLabel;
    QLineEdit *email_supplierLineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QTableView *tableSupplier;

    void setupUi(QWidget *Formsupplier)
    {
        if (Formsupplier->objectName().isEmpty())
            Formsupplier->setObjectName("Formsupplier");
        Formsupplier->resize(799, 503);
        formLayoutWidget = new QWidget(Formsupplier);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 70, 311, 171));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        nama_supplierLabel = new QLabel(formLayoutWidget);
        nama_supplierLabel->setObjectName("nama_supplierLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, nama_supplierLabel);

        nama_supplierLineEdit = new QLineEdit(formLayoutWidget);
        nama_supplierLineEdit->setObjectName("nama_supplierLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, nama_supplierLineEdit);

        kode_supplierLabel = new QLabel(formLayoutWidget);
        kode_supplierLabel->setObjectName("kode_supplierLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, kode_supplierLabel);

        kode_supplierLineEdit = new QLineEdit(formLayoutWidget);
        kode_supplierLineEdit->setObjectName("kode_supplierLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, kode_supplierLineEdit);

        alamat_suppierLabel = new QLabel(formLayoutWidget);
        alamat_suppierLabel->setObjectName("alamat_suppierLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, alamat_suppierLabel);

        alamat_supplierLineEdit = new QLineEdit(formLayoutWidget);
        alamat_supplierLineEdit->setObjectName("alamat_supplierLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, alamat_supplierLineEdit);

        telp_suppierLabel = new QLabel(formLayoutWidget);
        telp_suppierLabel->setObjectName("telp_suppierLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, telp_suppierLabel);

        telp_supplierLineEdit = new QLineEdit(formLayoutWidget);
        telp_supplierLineEdit->setObjectName("telp_supplierLineEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, telp_supplierLineEdit);

        fax_supplierLabel = new QLabel(formLayoutWidget);
        fax_supplierLabel->setObjectName("fax_supplierLabel");

        formLayout->setWidget(4, QFormLayout::LabelRole, fax_supplierLabel);

        fax_supplierLineEdit = new QLineEdit(formLayoutWidget);
        fax_supplierLineEdit->setObjectName("fax_supplierLineEdit");

        formLayout->setWidget(4, QFormLayout::FieldRole, fax_supplierLineEdit);

        email_suppierLabel = new QLabel(formLayoutWidget);
        email_suppierLabel->setObjectName("email_suppierLabel");

        formLayout->setWidget(5, QFormLayout::LabelRole, email_suppierLabel);

        email_supplierLineEdit = new QLineEdit(formLayoutWidget);
        email_supplierLineEdit->setObjectName("email_supplierLineEdit");

        formLayout->setWidget(5, QFormLayout::FieldRole, email_supplierLineEdit);

        pushButton = new QPushButton(Formsupplier);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 250, 151, 41));
        pushButton_3 = new QPushButton(Formsupplier);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(170, 300, 151, 41));
        pushButton_4 = new QPushButton(Formsupplier);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(10, 300, 151, 41));
        pushButton_2 = new QPushButton(Formsupplier);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(170, 250, 151, 41));
        tableSupplier = new QTableView(Formsupplier);
        tableSupplier->setObjectName("tableSupplier");
        tableSupplier->setGeometry(QRect(330, 70, 451, 271));

        retranslateUi(Formsupplier);

        QMetaObject::connectSlotsByName(Formsupplier);
    } // setupUi

    void retranslateUi(QWidget *Formsupplier)
    {
        Formsupplier->setWindowTitle(QCoreApplication::translate("Formsupplier", "Form", nullptr));
        nama_supplierLabel->setText(QCoreApplication::translate("Formsupplier", "Nama Supplier", nullptr));
        kode_supplierLabel->setText(QCoreApplication::translate("Formsupplier", "Kode Supplier", nullptr));
        alamat_suppierLabel->setText(QCoreApplication::translate("Formsupplier", "Alamat Supplier", nullptr));
        telp_suppierLabel->setText(QCoreApplication::translate("Formsupplier", "Telp Supplier", nullptr));
        fax_supplierLabel->setText(QCoreApplication::translate("Formsupplier", "Fax Supplier", nullptr));
        email_suppierLabel->setText(QCoreApplication::translate("Formsupplier", "Email Supplier", nullptr));
        pushButton->setText(QCoreApplication::translate("Formsupplier", "SImpan", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Formsupplier", "Cari", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Formsupplier", "Hapus", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Formsupplier", "Ubah", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Formsupplier: public Ui_Formsupplier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSUPPLIER_H
