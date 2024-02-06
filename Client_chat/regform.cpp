#include "regform.h"
#include "ui_regform.h"


RegForm::RegForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegForm)
{
    ui->setupUi(this);
}

RegForm::~RegForm()
{
    delete ui;
}


void RegForm::on_LoginButton_clicked()
{
 emit LoginRequested();
}


void RegForm::on_buttonBox_accepted()
{

    if(ui->PasswordLineEdit->text()!=ui->ConfirmPasswordLineEdit->text())
    {
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("Passwords not match"));
        return;
    }
    int userId=addUser(ui->LoginLineEdit->text().
                         toStdString());

    switch(userId)
    {
    case 0:
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("Incorrect Email"));
        return;
    case 2:
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("Email already exists"));
        return;
    default:

        QSqlQuery query;
        query.prepare("INSERT INTO registration_data (email) VALUES (:email)");
        query.bindValue(":email", ui->LoginLineEdit->text());
        query.exec();
        QString Qemail=ui->LoginLineEdit->text();
        QString id_user;
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT id_user FROM registration_data WHERE (email=\'"+Qemail+"\')");
        if (model->rowCount() > 0)
        {
            QModelIndex index = model->index(0, 0);
            id_user = model->data(index).toString();
        }
        query.prepare("UPDATE authorization_data SET password = ? WHERE id_user = ?");
        query.bindValue(0, ui->PasswordLineEdit->text());
        query.bindValue(1, id_user);
        query.exec();
        emit accepted(userId,ui->LoginLineEdit->text());//передаем сигнал, что бы зарегистрирован новый пользователь
    }

}




void RegForm::on_buttonBox_rejected()
{
    emit rejected();
}


