/********************************************************************************
** Form generated from reading UI file 'gestion_fournisseur.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTION_FOURNISSEUR_H
#define UI_GESTION_FOURNISSEUR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionExit;
    QAction *actionGen_rer_PDF;
    QAction *actionStatistiques;
    QWidget *centralWidget;
    QTabWidget *tabSponsor;
    QWidget *tab;
    QGroupBox *groupBox_3;
    QTableView *tab_fournisseur;
    QGroupBox *groupBox;
    QLabel *label_ID;
    QLabel *label_Nom;
    QLabel *label_Adr;
    QLineEdit *lineEdit_ID;
    QLineEdit *lineEdit_Nom;
    QLineEdit *lineEdit_Adr;
    QPushButton *pb_ajouter;
    QLabel *label_Adr_2;
    QLineEdit *lineEdit_tlf;
    QPushButton *pb_modifier;
    QPushButton *pushButton_2;
    QLabel *label_img_2;
    QLabel *label_Adr_5;
    QComboBox *comboBox;
    QLineEdit *lineEdit_id_sup;
    QPushButton *pb_supp;
    QLabel *label;
    QLabel *label_recherche;
    QLineEdit *lineEdit_recherche;
    QPushButton *pb_recherche;
    QLabel *label_recherche_2;
    QRadioButton *radioButton_id;
    QRadioButton *radioButton_nom;
    QLabel *countdown;
    QPushButton *pb_PDF;
    QPushButton *pb_STAT;
    QMenuBar *menuBar;
    QMenu *menuSponsor;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1208, 682);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../design/new icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionNew->setIcon(icon);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../design/close-icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionExit->setIcon(icon1);
        actionGen_rer_PDF = new QAction(MainWindow);
        actionGen_rer_PDF->setObjectName("actionGen_rer_PDF");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../design/pdf_icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionGen_rer_PDF->setIcon(icon2);
        actionStatistiques = new QAction(MainWindow);
        actionStatistiques->setObjectName("actionStatistiques");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../design/stats.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionStatistiques->setIcon(icon3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        tabSponsor = new QTabWidget(centralWidget);
        tabSponsor->setObjectName("tabSponsor");
        tabSponsor->setGeometry(QRect(-10, 30, 1231, 611));
        tabSponsor->setStyleSheet(QString::fromUtf8(""));
        tab = new QWidget();
        tab->setObjectName("tab");
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(30, 10, 1151, 571));
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 238);\n"
"background-color: rgb(233, 255, 254);"));
        tab_fournisseur = new QTableView(groupBox_3);
        tab_fournisseur->setObjectName("tab_fournisseur");
        tab_fournisseur->setGeometry(QRect(480, 150, 501, 261));
        tab_fournisseur->setStyleSheet(QString::fromUtf8(""));
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 30, 461, 491));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        label_ID = new QLabel(groupBox);
        label_ID->setObjectName("label_ID");
        label_ID->setGeometry(QRect(10, 40, 141, 16));
        QFont font;
        font.setFamilies({QString::fromUtf8("OCR A Extended")});
        font.setPointSize(10);
        label_ID->setFont(font);
        label_Nom = new QLabel(groupBox);
        label_Nom->setObjectName("label_Nom");
        label_Nom->setGeometry(QRect(10, 80, 161, 16));
        label_Nom->setFont(font);
        label_Adr = new QLabel(groupBox);
        label_Adr->setObjectName("label_Adr");
        label_Adr->setGeometry(QRect(10, 120, 151, 16));
        label_Adr->setFont(font);
        lineEdit_ID = new QLineEdit(groupBox);
        lineEdit_ID->setObjectName("lineEdit_ID");
        lineEdit_ID->setGeometry(QRect(200, 39, 181, 21));
        lineEdit_ID->setStyleSheet(QString::fromUtf8("border-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 170, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        lineEdit_Nom = new QLineEdit(groupBox);
        lineEdit_Nom->setObjectName("lineEdit_Nom");
        lineEdit_Nom->setGeometry(QRect(200, 79, 181, 21));
        lineEdit_Nom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 207);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 170, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        lineEdit_Nom->setInputMethodHints(Qt::InputMethodHint::ImhLowercaseOnly);
        lineEdit_Adr = new QLineEdit(groupBox);
        lineEdit_Adr->setObjectName("lineEdit_Adr");
        lineEdit_Adr->setGeometry(QRect(200, 119, 181, 21));
        lineEdit_Adr->setMinimumSize(QSize(0, 20));
        lineEdit_Adr->setBaseSize(QSize(0, 0));
        lineEdit_Adr->setStyleSheet(QString::fromUtf8("\n"
"\n"
"border-color: rgb(0, 0, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 170, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        lineEdit_Adr->setInputMethodHints(Qt::InputMethodHint::ImhEmailCharactersOnly);
        pb_ajouter = new QPushButton(groupBox);
        pb_ajouter->setObjectName("pb_ajouter");
        pb_ajouter->setGeometry(QRect(30, 250, 161, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("OCR A Extended")});
        font1.setPointSize(16);
        pb_ajouter->setFont(font1);
        pb_ajouter->setAutoFillBackground(false);
        pb_ajouter->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(35, 170, 102);\n"
""));
        label_Adr_2 = new QLabel(groupBox);
        label_Adr_2->setObjectName("label_Adr_2");
        label_Adr_2->setGeometry(QRect(10, 160, 151, 16));
        label_Adr_2->setFont(font);
        lineEdit_tlf = new QLineEdit(groupBox);
        lineEdit_tlf->setObjectName("lineEdit_tlf");
        lineEdit_tlf->setGeometry(QRect(200, 159, 181, 21));
        lineEdit_tlf->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 170, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        pb_modifier = new QPushButton(groupBox);
        pb_modifier->setObjectName("pb_modifier");
        pb_modifier->setGeometry(QRect(30, 340, 161, 41));
        pb_modifier->setFont(font1);
        pb_modifier->setAutoFillBackground(false);
        pb_modifier->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(35, 170, 102);\n"
""));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(520, 210, 181, 31));
        label_img_2 = new QLabel(groupBox);
        label_img_2->setObjectName("label_img_2");
        label_img_2->setGeometry(QRect(540, 250, 161, 161));
        label_img_2->setStyleSheet(QString::fromUtf8("capacity:10%;"));
        label_Adr_5 = new QLabel(groupBox);
        label_Adr_5->setObjectName("label_Adr_5");
        label_Adr_5->setGeometry(QRect(10, 210, 151, 16));
        label_Adr_5->setFont(font);
        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(200, 200, 82, 28));
        lineEdit_id_sup = new QLineEdit(groupBox_3);
        lineEdit_id_sup->setObjectName("lineEdit_id_sup");
        lineEdit_id_sup->setGeometry(QRect(630, 470, 181, 21));
        lineEdit_id_sup->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 170, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        pb_supp = new QPushButton(groupBox_3);
        pb_supp->setObjectName("pb_supp");
        pb_supp->setGeometry(QRect(850, 460, 131, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("OCR A Extended")});
        font2.setPointSize(12);
        pb_supp->setFont(font2);
        pb_supp->setStyleSheet(QString::fromUtf8("color: rgb(35, 170, 102);"));
        label = new QLabel(groupBox_3);
        label->setObjectName("label");
        label->setGeometry(QRect(550, 470, 41, 20));
        QFont font3;
        font3.setPointSize(9);
        label->setFont(font3);
        label_recherche = new QLabel(groupBox_3);
        label_recherche->setObjectName("label_recherche");
        label_recherche->setGeometry(QRect(540, 110, 131, 16));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("MS Shell Dlg 2")});
        font4.setPointSize(10);
        label_recherche->setFont(font4);
        lineEdit_recherche = new QLineEdit(groupBox_3);
        lineEdit_recherche->setObjectName("lineEdit_recherche");
        lineEdit_recherche->setGeometry(QRect(640, 110, 181, 21));
        lineEdit_recherche->setStyleSheet(QString::fromUtf8("border-color: qconicalgradient(cx:0.5, cy:0.5, angle:0, stop:0 rgba(35, 40, 3, 255), stop:0.16 rgba(136, 106, 22, 255), stop:0.225 rgba(166, 140, 41, 255), stop:0.285 rgba(204, 181, 74, 255), stop:0.345 rgba(235, 219, 102, 255), stop:0.415 rgba(245, 236, 112, 255), stop:0.52 rgba(209, 190, 76, 255), stop:0.57 rgba(187, 156, 51, 255), stop:0.635 rgba(168, 142, 42, 255), stop:0.695 rgba(202, 174, 68, 255), stop:0.75 rgba(218, 202, 86, 255), stop:0.815 rgba(208, 187, 73, 255), stop:0.88 rgba(187, 156, 51, 255), stop:0.935 rgba(137, 108, 26, 255), stop:1 rgba(35, 40, 3, 255));\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 170, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        pb_recherche = new QPushButton(groupBox_3);
        pb_recherche->setObjectName("pb_recherche");
        pb_recherche->setGeometry(QRect(850, 100, 131, 41));
        pb_recherche->setFont(font2);
        pb_recherche->setStyleSheet(QString::fromUtf8("color: rgb(216, 191, 0);\n"
"color: rgb(35, 170, 102);"));
        label_recherche_2 = new QLabel(groupBox_3);
        label_recherche_2->setObjectName("label_recherche_2");
        label_recherche_2->setGeometry(QRect(1000, 170, 131, 16));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("MS Shell Dlg 2")});
        font5.setPointSize(11);
        font5.setBold(true);
        label_recherche_2->setFont(font5);
        label_recherche_2->setStyleSheet(QString::fromUtf8("color: rgb(35, 170, 102);"));
        radioButton_id = new QRadioButton(groupBox_3);
        radioButton_id->setObjectName("radioButton_id");
        radioButton_id->setGeometry(QRect(1000, 200, 97, 20));
        radioButton_id->setFont(font3);
        radioButton_nom = new QRadioButton(groupBox_3);
        radioButton_nom->setObjectName("radioButton_nom");
        radioButton_nom->setGeometry(QRect(1000, 240, 121, 20));
        radioButton_nom->setFont(font3);
        countdown = new QLabel(groupBox_3);
        countdown->setObjectName("countdown");
        countdown->setGeometry(QRect(980, 10, 131, 51));
        pb_PDF = new QPushButton(groupBox_3);
        pb_PDF->setObjectName("pb_PDF");
        pb_PDF->setGeometry(QRect(990, 320, 131, 41));
        pb_PDF->setFont(font2);
        pb_PDF->setStyleSheet(QString::fromUtf8("color: rgb(35, 170, 102);"));
        pb_STAT = new QPushButton(groupBox_3);
        pb_STAT->setObjectName("pb_STAT");
        pb_STAT->setGeometry(QRect(990, 380, 131, 41));
        pb_STAT->setFont(font2);
        pb_STAT->setStyleSheet(QString::fromUtf8("color: rgb(35, 170, 102);"));
        tabSponsor->addTab(tab, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1208, 25));
        menuSponsor = new QMenu(menuBar);
        menuSponsor->setObjectName("menuSponsor");
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuSponsor->menuAction());
        menuSponsor->addSeparator();
        menuSponsor->addAction(actionNew);
        menuSponsor->addAction(actionExit);

        retranslateUi(MainWindow);

        tabSponsor->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Sponsors", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionGen_rer_PDF->setText(QCoreApplication::translate("MainWindow", "Gen\303\251rer PDF", nullptr));
        actionStatistiques->setText(QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        groupBox_3->setTitle(QString());
        groupBox->setTitle(QString());
        label_ID->setText(QCoreApplication::translate("MainWindow", "ID _Fournissuer:", nullptr));
        label_Nom->setText(QCoreApplication::translate("MainWindow", "Nom_Fournisseur:", nullptr));
        label_Adr->setText(QCoreApplication::translate("MainWindow", "Adresse Mail :", nullptr));
        lineEdit_Adr->setPlaceholderText(QCoreApplication::translate("MainWindow", "exemple@gmail.com", nullptr));
        pb_ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_Adr_2->setText(QCoreApplication::translate("MainWindow", "N\302\260 T\303\251l\303\251phone : ", nullptr));
        pb_modifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "S\303\251l\303\251ctionnez une image", nullptr));
        label_img_2->setText(QString());
        label_Adr_5->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "active", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "inactive", nullptr));

        lineEdit_id_sup->setText(QString());
        pb_supp->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ID :", nullptr));
        label_recherche->setText(QCoreApplication::translate("MainWindow", "ID :", nullptr));
        pb_recherche->setText(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        label_recherche_2->setText(QCoreApplication::translate("MainWindow", "Tri :", nullptr));
        radioButton_id->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        radioButton_nom->setText(QCoreApplication::translate("MainWindow", "Nom soci\303\251t\303\251", nullptr));
        countdown->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pb_PDF->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        pb_STAT->setText(QCoreApplication::translate("MainWindow", "STATS", nullptr));
        tabSponsor->setTabText(tabSponsor->indexOf(tab), QCoreApplication::translate("MainWindow", "Fournisseur", nullptr));
        menuSponsor->setTitle(QCoreApplication::translate("MainWindow", "foursn", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTION_FOURNISSEUR_H
