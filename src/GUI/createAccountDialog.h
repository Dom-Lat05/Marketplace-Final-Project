#ifndef CREATEACCOUNTDIALOG_H
#define CREATEACCOUNTDIALOG_H

#include <QDialog>
#include "databasemanager.h"

namespace Ui {
class CreateAccountDialog;
}

class CreateAccountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateAccountDialog(DatabaseManager *db, QWidget *parent = nullptr);
    ~CreateAccountDialog();

private slots:
    void on_btnCreateAccount_clicked();
    void on_btnCancel_clicked();

private:
    Ui::CreateAccountDialog *ui;
    DatabaseManager *m_db;
};

#endif // CREATEACCOUNTDIALOG_H
