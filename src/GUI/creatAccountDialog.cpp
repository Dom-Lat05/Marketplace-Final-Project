#include "createaccountdialog.h"
#include "ui_createaccountdialog.h"

#include <QMessageBox>

CreateAccountDialog::CreateAccountDialog(DatabaseManager *db, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateAccountDialog)
    , m_db(db)
{
    ui->setupUi(this);
}

CreateAccountDialog::~CreateAccountDialog()
{
    delete ui;
}

void CreateAccountDialog::on_btnCreateAccount_clicked()
{
    QString username = ui->txtNewUsername->text().trimmed();
    QString password = ui->txtNewPassword->text();
    QString confirmPassword = ui->txtConfirmPassword->text();

    if (username.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Username cannot be empty.");
        return;
    }

    if (password.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Password cannot be empty.");
        return;
    }

    if (password != confirmPassword)
    {
        QMessageBox::warning(this, "Error", "Passwords do not match.");
        return;
    }

    if (!m_db->createUser(username, password))
    {
        QMessageBox::warning(this, "Error", "Could not create account. Username may already exist.");
        return;
    }

    QMessageBox::information(this, "Success", "Account created successfully.");
    accept();
}

void CreateAccountDialog::on_btnCancel_clicked()
{
    reject();
}
