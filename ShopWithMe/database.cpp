#include "database.h"
#include <QVector>
#include <QtSql>
#include <QDebug>

DataBase::DataBase()
{
}

DataBase::DataBase(QString pth)
{
    path = pth;
}

bool DataBase::openDataBase()
{

    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName(path);

    if (db.open())
    {
        return true;
    }
    else return false;
}

void DataBase::closeDataBase()
{
    db.close();
}

QVector<QString> DataBase::username_and_passwords()
{
    QVector<QString> Username_and_Password;
    QSqlQuery qry;
    if(qry.exec("select * from Users"))
    {
        while (qry.next())
        {
            Username_and_Password.push_back(qry.value(1).toString());
            Username_and_Password.push_back(qry.value(2).toString());
        }
    }
    return Username_and_Password;
}
