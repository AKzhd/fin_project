#include "logform.h"
#include "ui_logform.h"

LogForm::LogForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LogForm)
{
    ui->setupUi(this);
}
LogForm::~LogForm()
{
    delete ui;
}

// void LogForm::on_RegistrationButton_clicked()//Registration
// {
//     emit RegistrationRequested();//emit - отправка сигнала
// }


void LogForm::on_buttonBox_accepted()//  Ok
{
    int userId=checkPassword(ui->LoginEdit->text().toStdString(),
                               ui->PasswordEdit->text().toStdString());
    switch(userId)//выставляем варианты вывода функции checkPassword
    {
    case 0://некорректное имя
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("Wrong Email"));
        return;
    case 1://пользователь существует
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("Wrong Password"));
        return;
    default:

        QMessageBox::information(0,"Успешно", "Добро пожаловать в чат!");

        emit accepted(userId,ui->LoginEdit->text());//передаем сигнал, что бы зарегистрирован новый пользователь
    }

}


void LogForm::on_buttonBox_rejected()//  Cancel
{
    emit rejected();
}

void LogForm::on_RegistrationButton_clicked()
{
    emit RegistrationRequested();
}

