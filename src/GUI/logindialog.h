#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "user.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

    User getUser() const;

private slots:
    void on_btnLogin_clicked();

private:
    Ui::LoginDialog *ui;
    User m_user;
};

#endif // LOGINDIALOG_H
