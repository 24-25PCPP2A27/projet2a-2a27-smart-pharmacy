#include "log.h"
#include "ui_log.h"
#include "menu.h"
#include"ui_menu.h"
#include"connection.h"
#include <QMessageBox>

Log::Log(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Log)
{
    ui->setupUi(this);
}

Log::~Log()
{
    delete ui;
}

void Log::on_pushButton_log_clicked()
{
    QString username = ui->lineEdit_user->text();
    QString password = ui->lineEdit_pass->text();

    // Ensure database connection is open
    QSqlDatabase db = QSqlDatabase::database(); // Assuming you already set up a connection
    if (!db.isOpen()) {
        QMessageBox::critical(this, "Database Error", "Failed to connect to the database.");
        return;
    }

    // Prepare and execute the query
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM EMPLOYE WHERE NOM = :username AND ID = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        QMessageBox::critical(this, "Query Error", "Failed to execute the query: " + query.lastError().text());
        return;
    }

    // Validate the result
    if (query.next() && query.value(0).toInt() > 0) {
        Menu *Me = new Menu(this);
        Me->show();
        this->hide();
    } else {
        // Show an error message
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
    }
}
