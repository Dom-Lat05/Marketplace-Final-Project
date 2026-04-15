#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "user.h"
#include "databasemanager.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(DatabaseManager *db, QWidget *parent = nullptr);
    ~LoginDialog();

    User getUser() const;

private slots:
    void on_btnLogin_clicked();
    void on_btnCreateAccount_clicked();

private:
    Ui::LoginDialog *ui;
    User m_user;
    DatabaseManager *m_db;
};

#endif // LOGINDIALOG_H
