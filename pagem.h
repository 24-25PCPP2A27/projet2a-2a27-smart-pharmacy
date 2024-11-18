#ifndef PAGEM_H
#define PAGEM_H
#include "email.h"
#include <QMainWindow>

namespace Ui {
class pageM;
}

class pageM : public QMainWindow
{
    Q_OBJECT

public:
    explicit pageM(QWidget *parent = nullptr);
    ~pageM();

private slots:
    void on_mailing_clicked();

private:
    Ui::pageM *ui;
};

#endif // PAGEM_H
