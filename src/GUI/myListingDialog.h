#ifndef MYLISTINGDIALOG_H
#define MYLISTINGDIALOG_H

#include <QDialog>
#include <QVector>
#include "user.h"
#include "listing.h"
#include "databasemanager.h"

namespace Ui {
class MyListingDialog;
}

class MyListingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyListingDialog(const User& user, DatabaseManager *db, QWidget *parent = nullptr);
    ~MyListingDialog();

private slots:
    void on_btnEdit_clicked();
    void on_btnMarkSold_clicked();
    void on_btnClose_clicked();

private:
    void loadListings();

    Ui::MyListingDialog *ui;
    User m_user;
    DatabaseManager *m_db;
    QVector<Listing> m_listings;
};

#endif // MYLISTINGDIALOG_H
