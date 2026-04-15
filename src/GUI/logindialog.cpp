#include "logindialog.h"
#include "ui_logindialog.h"
#include "createaccountdialog.h"

#include <QMessageBox>

LoginDialog::LoginDialog(DatabaseManager *db, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
    , m_db(db)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

User LoginDialog::getUser() const
{
    return m_user;
}

void LoginDialog::on_btnLogin_clicked()
{
    QString username = ui->txtUsername->text().trimmed();
    QString password = ui->txtPassword->text();

    if (username.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please enter both username and password.");
        return;
    }

    if (!m_db->validateUser(username, password))
    {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
        return;
    }

    m_user = User(username);
    accept();
}

void LoginDialog::on_btnCreateAccount_clicked()
{
    CreateAccountDialog createDialog(m_db, this);
    createDialog.exec();
}
