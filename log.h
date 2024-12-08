#ifndef LOG_H
#define LOG_H

#include <QMainWindow>

namespace Ui {
class Log;
}

class Log : public QMainWindow
{
    Q_OBJECT

public:
    explicit Log(QWidget *parent = nullptr);
    ~Log();

private slots:
    void on_pushButton_log_clicked();


private:
    Ui::Log *ui;
};

#endif // LOG_H
