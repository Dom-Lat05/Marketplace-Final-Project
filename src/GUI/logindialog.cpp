#include "logindialog.h"
#include "ui_logindialog.h"
#include "createaccountdialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(DatabaseManager *db, QWidget *parent)
    : QDialog(parent), ui(new Ui::LoginDialog), m_db(db)
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
    QString u = ui->txtUsername->text();
    QString p = ui->txtPassword->text();

    if (!m_db->validateUser(u, p))
    {
        QMessageBox::warning(this, "Error", "Invalid login");
        return;
    }

    m_user = User(u);
    accept();
}

void LoginDialog::on_btnCreateAccount_clicked()
{
    CreateAccountDialog dialog(m_db, this);
    dialog.exec();
}
