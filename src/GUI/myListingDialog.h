#ifndef MYLISTINGDIALOGUE_H
#define MYLISTINGDIALOGUE_H

#include <QDialog>
#include <QVector>
#include "user.h"
#include "listing.h"
#include "databasemanager.h"

namespace Ui {
class MyListingDialogue;
}

class MyListingDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit MyListingDialogue(const User& user, DatabaseManager *db, QWidget *parent = nullptr);
    ~MyListingDialogue();

private slots:
    void on_btnEdit_clicked();
    void on_btnMarkSold_clicked();
    void on_btnClose_clicked();

private:
    void loadListings();

    Ui::MyListingDialogue *ui;
    User m_user;
    DatabaseManager *m_db;
    QVector<Listing> m_listings;
};

#endif // MYLISTINGDIALOGUE_H
