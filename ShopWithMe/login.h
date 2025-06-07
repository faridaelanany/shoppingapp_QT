#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    bool userNamePassword();
    QVector<QString> userPass;
    void set_DB(QVector<QString> db);
    bool validUser;

private slots:
    void on_loginButton_clicked();

    void on_SIGNUPBUTTON_clicked();

    void on_REMEMBERMECHECKBOX_stateChanged(int arg1);

private:
    Ui::Login *ui;
    QVector<QString> DataBase;
};

#endif // LOGIN_H
