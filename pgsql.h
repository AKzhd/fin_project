#ifndef PGSQL_H
#define PGSQL_H
#include <QMessageBox>
#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <string>
#include <vector>
#include <QWidget>
#include <QSqlQueryModel>




inline bool createConnection()
{ QSqlDatabase    db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setPassword("postgres");
    db.setPort(5432);
    db.setHostName("127.0.0.1");
    if (!db.open()){
        QMessageBox::warning(0,"Error",db.lastError().text());
        return false;
    }
    else
    {
        QMessageBox::information(0,"Success","The connection to the database is established");
        return true;
    }
}

int addUser(std::string email);//общая проверка
int checkPassword(std::string email,std::string password);
void addChatMessage(std::string email,std::string message);
void addPrivateMessage(std::string email,std::string email_receiver, std::string message);
QString getid(QString Qemail);
QString getQemail(QString Qid);


std::vector<std::string> getUserList();

#endif // PGSQL_H
