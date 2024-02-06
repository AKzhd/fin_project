#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);




    connect(ui->LogWiget, &LogForm::RegistrationRequested,this, &Dialog::setRegistrationForm);//обеспечивает связь между виджетом и функциями
    connect(ui->LogWiget, &LogForm::accepted,this, &Dialog::onLoggedIn);//чтобы  сразу после нажатия ok(accepted),начиналась функция onLoggedIn
    connect(ui->LogWiget, &LogForm::rejected,this, &Dialog::onRejectRequested);//чтобы  сразу после нажатия cancel(rejected),начиналась функция onRejectRequested
    connect(ui->RegWidget, &RegForm::LoginRequested,this, &Dialog::setLoginForm);
    connect(ui->RegWidget, &RegForm::accepted,this, &Dialog::onLoggedIn);
    connect(ui->RegWidget, &RegForm::rejected,this, &Dialog::onRejectRequested);
}



Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setLoginForm()
{
    //ui->stackedWidget->setCurrentWidget(0);//0-индекс страницы(page) виджет LoginForm
    QWidget* widget = findChild<QWidget*>("LogWiget");
    ui->stackedWidget->setCurrentWidget(widget);
}

void Dialog::setRegistrationForm()
{
    //ui->stackedWidget->setCurrentWidget(1);//1- индекс страницы(page) виджет RegistrationForm
    QWidget* widget = findChild<QWidget*>("RegWidget");//ищет виджет по названию
    ui->stackedWidget->setCurrentWidget(widget);
}

void Dialog::onLoggedIn(int userId,QString Qemail)
{
    m_user_id=userId;
    m_Qemail =Qemail;
    accept();// чтоб работала ok на авторизации
}

void Dialog::onRejectRequested()
{
    reject();
}

int Dialog::user_id() const
{
    return m_user_id;
}

QString Dialog::getQemail() const
{
    return m_Qemail;
}
