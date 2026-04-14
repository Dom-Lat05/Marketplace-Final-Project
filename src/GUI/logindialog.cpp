#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
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
    QString username = ui->txtUsername->text();

    if (username.trimmed().isEmpty())
    {
        QMessageBox::warning(this, "Error", "Please enter a username.");
        return;
    }

    m_user = User(username);

    accept(); // closes dialog with success
}
