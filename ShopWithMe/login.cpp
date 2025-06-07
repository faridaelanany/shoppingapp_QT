#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include <QMessageBox>
#include <QtSql>
#include "register.h"


Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::set_DB(QVector<QString> db)
{
    DataBase = db;
}

bool Login::userNamePassword()
{
    QString username = ui->usernamelineedit->text();
    QString password = ui->LineEditPassword->text();

    for (int i = 0; i < DataBase.size(); i += 2)
    {
        if (username == DataBase[i] && password == DataBase[i + 1])
            return true;
    }
    return false;
}

void Login::on_loginButton_clicked()
{
    bool validUser = this->userNamePassword();
    if (validUser)
    {
        accept(); // Accept the dialog if credentials are valid
    }
    else
    {
        QMessageBox::information(this, "Error", "Incorrect username or password");
        ui->usernamelineedit->clear();
        ui->LineEditPassword->clear();
    }
}

void Login::on_SIGNUPBUTTON_clicked()
{
    hide();
    Register *registerDialog = new Register(this);
    registerDialog->show();

}

void Login::on_REMEMBERMECHECKBOX_stateChanged(int state)
{
    if (state == Qt::Checked)
    {
        // Get username and password
        QString username = ui->usernamelineedit->text();
        QString password = ui->LineEditPassword->text();

        // Add username and password to your data
        DataBase.append(username);
        DataBase.append(password);
    }
}

