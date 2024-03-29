#ifndef PGSQL_H
#define PGSQL_H

#include <QMessageBox>
#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QWidget>
#include <QMainWindow>
#include <QSql>
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

inline bool createTables()
{
    QSqlQuery query;
     query.exec("CREATE TABLE Registration_DATA ("
               "id_USER SERIAL,"
               "Email character varying(200) NOT NULL,"
               "status character varying(100) CHECK (status IN ('active', 'inactive')) default 'active');");

     query.exec("CREATE TABLE Authorization_DATA ("
               "id SERIAL, id_USER integer NOT NULL, "
               "Password character varying(200) default NULL);");

     query.exec("CREATE TABLE History_DATA ("
               "id_Message SERIAL,id_Sender integer NOT NULL, "
               "Message text NOT NULL,SEND_ON date Default current_date);");

     query.exec("CREATE TABLE History_private_DATA ("
               "id_Message SERIAL,id_Sender integer NOT NULL, id_Receiver integer NOT NULL, "
               "Message text NOT NULL,SEND_ON date Default current_date);");

     query.exec("CREATE OR REPLACE FUNCTION auto_id() "
               "RETURNS TRIGGER AS $auto_id$ "
               "BEGIN "
               "   INSERT INTO authorization_data (id_user) "
               "   (SELECT registration_data.id_user FROM registration_data "
               "   LEFT OUTER JOIN authorization_data ON registration_data.id_user = authorization_data.id_user "
               "   WHERE authorization_data.id IS NULL); "
               "   RETURN NEW; "
               "END; "
               "$auto_id$ LANGUAGE plpgsql;");

     query.exec("CREATE TRIGGER auto_id AFTER INSERT OR UPDATE ON registration_data "
               "FOR EACH ROW EXECUTE PROCEDURE auto_id();");

     query.exec("CREATE OR REPLACE FUNCTION delete_id() RETURNS TRIGGER AS $delete_id_authorization_data$ \
            BEGIN \
              DELETE FROM authorization_data \
              WHERE id IN (SELECT authorization_data.id_user \
                           FROM authorization_data \
                           LEFT OUTER JOIN registration_data ON authorization_data.id_user = registration_data.id_user \
                           WHERE registration_data.status='inactive'); \
              RETURN NEW; \
            END; \
            $delete_id_authorization_data$ LANGUAGE plpgsql;");
     query.exec("CREATE TRIGGER delete_id AFTER UPDATE ON registration_data FOR EACH ROW EXECUTE PROCEDURE delete_id();");
     query.exec("ALTER TABLE registration_data ADD CONSTRAINT id_user PRIMARY KEY (id_user);");
     query.exec("ALTER TABLE authorization_data ADD CONSTRAINT id PRIMARY KEY (id);");
     query.exec("ALTER TABLE history_data ADD CONSTRAINT id_message PRIMARY KEY (id_message);");
     query.exec("ALTER TABLE history_private_data ADD CONSTRAINT id_message PRIMARY KEY (id_message);");
     query.exec("ALTER TABLE authorization_data ADD FOREIGN KEY (id_user) REFERENCES registration_data (id_user);");
     query.exec("ALTER TABLE history_data ADD FOREIGN KEY (id_sender) REFERENCES registration_data (id_user);");
     query.exec("ALTER TABLE history_private_data ADD FOREIGN KEY (id_sender) REFERENCES registration_data (id_user);");
     query.exec("ALTER TABLE history_private_data ADD FOREIGN KEY (id_receiver) REFERENCES registration_data (id_user);");


    return (1);

}
std::vector<std::string> getUserList();
QString getid(QString Qemail);
QString getQemail(QString Qid);



#endif // PGSQL_H

