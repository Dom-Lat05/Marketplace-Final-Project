#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QVector>
#include <QSqlDatabase>
#include "listing.h"

class DatabaseManager
{
public:
    DatabaseManager();

    bool openDatabase();
    void createTables();

    bool createUser(const QString& username, const QString& password);
    bool validateUser(const QString& username, const QString& password);

    bool addListing(const Listing& listing);
    QVector<Listing> getAllListings() const;
    QVector<Listing> filterListings(const QString& searchText,
                                    const QString& category) const;

private:
    QSqlDatabase m_db;
};

#endif // DATABASEMANAGER_H
