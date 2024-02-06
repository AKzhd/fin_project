#ifndef LOGFORM_H
#define LOGFORM_H

#include <QWidget>
#include "pgsql.h"

namespace Ui {
class LogForm;
}

class LogForm : public QWidget
{
    Q_OBJECT

public:
    explicit LogForm(QWidget *parent = nullptr);
    ~LogForm();


signals:
    void RegistrationRequested();
    void accepted(int userId,QString Qemail);
    void rejected();

private slots:
    void on_RegistrationButton_clicked();

    void on_buttonBox_accepted();//Ok\ Cancel если принято

    void on_buttonBox_rejected();//Ok\ Cancel если отклонено

private:
    Ui::LogForm *ui;
};

#endif // LOGFORM_H
