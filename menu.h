#ifndef MENU_H
#define MENU_H

#include <QMainWindow>

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();
    int getcurrentpage() { return currentpage; }
    void setcurrentpage(int cp) { currentpage = cp; }
    void cp() {Menu M;M.on_Client_clicked();}
    void cm() {Menu M;M.on_Medicament_clicked();}
    void cf() {Menu M;M.on_Fournisseur_clicked();}
    void ce() {Menu M;M.on_Employe_clicked();}

signals:
    void pageChanged(int currentPage);

private slots:
    void on_Client_clicked();
    void on_Medicament_clicked();
    void on_Fournisseur_clicked();
    void on_Employe_clicked();

private:
    Ui::Menu *uis;
    int currentpage = 0;
};

#endif // MENU_H
