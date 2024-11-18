/********************************************************************************
** Form generated from reading UI file 'pagem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEM_H
#define UI_PAGEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pageM
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *mailing;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *destinataireEmail;
    QLineEdit *objetEmail;
    QLineEdit *bodyEmail;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *pageM)
    {
        if (pageM->objectName().isEmpty())
            pageM->setObjectName("pageM");
        pageM->resize(800, 600);
        centralwidget = new QWidget(pageM);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(100, 50, 621, 461));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 255);"));
        mailing = new QPushButton(groupBox);
        mailing->setObjectName("mailing");
        mailing->setGeometry(QRect(330, 300, 141, 29));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 100, 63, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 170, 63, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 240, 63, 20));
        destinataireEmail = new QLineEdit(groupBox);
        destinataireEmail->setObjectName("destinataireEmail");
        destinataireEmail->setGeometry(QRect(180, 100, 113, 26));
        destinataireEmail->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        objetEmail = new QLineEdit(groupBox);
        objetEmail->setObjectName("objetEmail");
        objetEmail->setGeometry(QRect(190, 170, 113, 26));
        objetEmail->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        bodyEmail = new QLineEdit(groupBox);
        bodyEmail->setObjectName("bodyEmail");
        bodyEmail->setGeometry(QRect(180, 230, 113, 111));
        bodyEmail->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pageM->setCentralWidget(centralwidget);
        menubar = new QMenuBar(pageM);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        pageM->setMenuBar(menubar);
        statusbar = new QStatusBar(pageM);
        statusbar->setObjectName("statusbar");
        pageM->setStatusBar(statusbar);

        retranslateUi(pageM);

        QMetaObject::connectSlotsByName(pageM);
    } // setupUi

    void retranslateUi(QMainWindow *pageM)
    {
        pageM->setWindowTitle(QCoreApplication::translate("pageM", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("pageM", "Email", nullptr));
        mailing->setText(QCoreApplication::translate("pageM", "Send Email", nullptr));
        label->setText(QCoreApplication::translate("pageM", "To :", nullptr));
        label_2->setText(QCoreApplication::translate("pageM", "sujet", nullptr));
        label_3->setText(QCoreApplication::translate("pageM", "contenue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pageM: public Ui_pageM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEM_H
