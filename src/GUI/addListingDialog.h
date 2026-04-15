#ifndef ADDLISTINGDIALOG_H
#define ADDLISTINGDIALOG_H

#include <QDialog>
#include "listing.h"
#include "user.h"

namespace Ui {
class AddListingDialog;
}

class AddListingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddListingDialog(const User& user, QWidget *parent = nullptr);
    ~AddListingDialog();

    Listing getListing() const;

private slots:
    void on_btnSave_clicked();
    void on_btnCancel_clicked();

private:
    Ui::AddListingDialog *ui;
    User m_user;
    Listing m_listing;
};

#endif // ADDLISTINGDIALOG_H
