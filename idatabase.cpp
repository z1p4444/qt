#include "idatabase.h"

void IDatabase::ininDatabase()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    QString aFile = "E:/c++/Lab4database.db";
    database.setDatabaseName(aFile);

    if(!database.open()){
        qDebug()<<"failed to open database";
    }else
    {
        qDebug()<<"open database is ok";
    }
}

QString IDatabase::userLogin(QString userName, QString password)
{
    //return "LoginOK";
    QSqlQuery query;
    query.prepare("select username,password from user where username = :USER");
    query.bindValue(":USER",userName);
    query.exec();
    if(query.first()&& query.value("username").isValid()){
        QString passwd = query.value("password").toString();
        if(passwd == password)
        {
            qDebug()<<"login ok";
            return "loginOK";
        }
        else{
            qDebug()<<"wrong password";
            return "wrongPassword";
        }
    }
    else{
        qDebug()<<"no such user";
        return "wrongUsername";
    }



}

IDatabase::IDatabase(QObject *parent)
    : QObject{parent}
{
    ininDatabase();

}
