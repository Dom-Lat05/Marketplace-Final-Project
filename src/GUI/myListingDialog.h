#ifndef MYLISTINGSDIALOG_H
#define MYLISTINGSDIALOG_H

#include <QDialog>
#include "user.h"
#include "listing.h"
#include "databasemanager.h"

namespace Ui {
class MyListingsDialog;
}

class MyListingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyListingsDialog(const User& user, DatabaseManager *db, QWidget *parent = nullptr);
    ~MyListingsDialog();

private slots:
    void on_btnEdit_clicked();
    void on_btnMarkSold_clicked();
    void on_btnClose_clicked();

private:
    void loadListings();

    Ui::MyListingsDialog *ui;
    User m_user;
    DatabaseManager *m_db;
    QVector<Listing> m_listings;
};

#endif // MYLISTINGSDIALOG_H
