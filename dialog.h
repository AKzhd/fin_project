#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void setLoginForm();//функция для изменения индекса страницы на 0
    void setRegistrationForm();//функция для изменения индекса страницы на 1
    int user_id() const;
    QString getQemail() const;

public slots:
    void onLoggedIn(int userId,QString Qemail);//ловим из сигнала нажатие на кнопку ОК
    void onRejectRequested();//ловим из сигнала нажатие на кнопку ОК
private:
    Ui::Dialog *ui;
    int m_user_id;
    QString m_Qemail;
};

#endif // DIALOG_H
