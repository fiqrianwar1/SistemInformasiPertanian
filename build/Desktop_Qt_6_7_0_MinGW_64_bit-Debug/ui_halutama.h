/********************************************************************************
** Form generated from reading UI file 'halutama.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HALUTAMA_H
#define UI_HALUTAMA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HalUtama
{
public:
    QWidget *centralwidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HalUtama)
    {
        if (HalUtama->objectName().isEmpty())
            HalUtama->setObjectName("HalUtama");
        HalUtama->resize(379, 305);
        centralwidget = new QWidget(HalUtama);
        centralwidget->setObjectName("centralwidget");
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(70, 60, 241, 191));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(formLayoutWidget);
        pushButton->setObjectName("pushButton");

        formLayout->setWidget(0, QFormLayout::FieldRole, pushButton);

        pushButton_2 = new QPushButton(formLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        formLayout->setWidget(1, QFormLayout::FieldRole, pushButton_2);

        pushButton_3 = new QPushButton(formLayoutWidget);
        pushButton_3->setObjectName("pushButton_3");

        formLayout->setWidget(2, QFormLayout::FieldRole, pushButton_3);

        pushButton_4 = new QPushButton(formLayoutWidget);
        pushButton_4->setObjectName("pushButton_4");

        formLayout->setWidget(3, QFormLayout::FieldRole, pushButton_4);

        pushButton_5 = new QPushButton(formLayoutWidget);
        pushButton_5->setObjectName("pushButton_5");

        formLayout->setWidget(4, QFormLayout::FieldRole, pushButton_5);

        HalUtama->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(HalUtama);
        statusbar->setObjectName("statusbar");
        HalUtama->setStatusBar(statusbar);

        retranslateUi(HalUtama);

        QMetaObject::connectSlotsByName(HalUtama);
    } // setupUi

    void retranslateUi(QMainWindow *HalUtama)
    {
        HalUtama->setWindowTitle(QCoreApplication::translate("HalUtama", "HalUtama", nullptr));
        pushButton->setText(QCoreApplication::translate("HalUtama", "Barang", nullptr));
        pushButton_2->setText(QCoreApplication::translate("HalUtama", "Penjualan", nullptr));
        pushButton_3->setText(QCoreApplication::translate("HalUtama", "Pelanggan", nullptr));
        pushButton_4->setText(QCoreApplication::translate("HalUtama", "Supplier", nullptr));
        pushButton_5->setText(QCoreApplication::translate("HalUtama", "Pembelian", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HalUtama: public Ui_HalUtama {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HALUTAMA_H
