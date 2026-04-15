#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QVector>
#include "listing.h"

class DatabaseManager
{
public:
    DatabaseManager();

    bool openDatabase();
    void createTables();

    bool createUser(const QString& username, const QString& password);
    bool validateUser(const QString& username, const QString& password);
    bool updatePassword(const QString& username, const QString& currentPassword, const QString& newPassword);

    void addListing(const Listing& listing);
    QVector<Listing> getAllListings();
    QVector<Listing> filterListings(const QString& search, const QString& category);

    QVector<Listing> getListingsBySeller(const QString& seller);
    bool updateListing(int id, const QString& title, const QString& category, double price, const QString& description);
    bool markListingSold(int id);

private:
    QSqlDatabase m_db;
};

#endif // DATABASEMANAGER_H
