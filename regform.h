#ifndef REGFORM_H
#define REGFORM_H
#include "pgsql.h"

#include <QWidget>

namespace Ui {
class RegForm;
}

class RegForm : public QWidget
{
    Q_OBJECT

public:
    explicit RegForm(QWidget *parent = nullptr);
    ~RegForm();

signals:
    void LoginRequested();
    void accepted(int userId,QString Qemail);
    void rejected();

private slots:
    void on_LoginButton_clicked();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();


private:
    Ui::RegForm *ui;
};

#endif // REGFORM_H
