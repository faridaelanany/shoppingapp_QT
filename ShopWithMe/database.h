#ifndef DATABASE_H
#define DATABASE_H

#include <QDialog>
#include <QtSql>
#include <QVector>
#include <QMessageBox>
class DataBase
{
private:
    QString path;

public:
    DataBase();
    DataBase(QString pth);
    QSqlDatabase db;
    bool openDataBase();
    QVector<QString> username_and_passwords();
    void closeDataBase();
};

#endif // DATABASE_H

