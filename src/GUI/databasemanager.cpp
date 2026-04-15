#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

DatabaseManager::DatabaseManager()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("marketplace.db");
}

bool DatabaseManager::openDatabase()
{
    return m_db.open();
}

void DatabaseManager::createTables()
{
    QSqlQuery query;

    query.exec("CREATE TABLE IF NOT EXISTS users (username TEXT PRIMARY KEY, password TEXT)");
    query.exec("CREATE TABLE IF NOT EXISTS listings (title TEXT, category TEXT, price REAL, seller TEXT)");
}

bool DatabaseManager::createUser(const QString& username, const QString& password)
{
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) VALUES (:u, :p)");
    query.bindValue(":u", username);
    query.bindValue(":p", password);

    return query.exec();
}

bool DatabaseManager::validateUser(const QString& username, const QString& password)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = :u AND password = :p");
    query.bindValue(":u", username);
    query.bindValue(":p", password);

    query.exec();
    return query.next();
}

bool DatabaseManager::updatePassword(const QString& username, const QString& currentPassword, const QString& newPassword)
{
    QSqlQuery query;
    query.prepare("UPDATE users SET password = :new WHERE username = :u AND password = :curr");
    query.bindValue(":new", newPassword);
    query.bindValue(":u", username);
    query.bindValue(":curr", currentPassword);

    return query.exec() && query.numRowsAffected() > 0;
}

void DatabaseManager::addListing(const Listing& listing)
{
    QSqlQuery query;
    query.prepare("INSERT INTO listings VALUES (:t, :c, :p, :s)");
    query.bindValue(":t", listing.getTitle());
    query.bindValue(":c", listing.getCategory());
    query.bindValue(":p", listing.getPrice());
    query.bindValue(":s", listing.getSeller());

    query.exec();
}

QVector<Listing> DatabaseManager::getAllListings()
{
    QVector<Listing> list;
    QSqlQuery query("SELECT * FROM listings");

    while (query.next())
    {
        list.append(Listing(
            query.value(0).toString(),
            query.value(1).toString(),
            query.value(2).toDouble(),
            query.value(3).toString()
        ));
    }

    return list;
}

QVector<Listing> DatabaseManager::filterListings(const QString& search, const QString& category)
{
    QVector<Listing> list;
    QSqlQuery query;

    QString sql = "SELECT * FROM listings WHERE title LIKE :search";

    if (category != "All")
        sql += " AND category = :cat";

    query.prepare(sql);
    query.bindValue(":search", "%" + search + "%");

    if (category != "All")
        query.bindValue(":cat", category);

    query.exec();

    while (query.next())
    {
        list.append(Listing(
            query.value(0).toString(),
            query.value(1).toString(),
            query.value(2).toDouble(),
            query.value(3).toString()
        ));
    }

    return list;
}
