#include "databasemanager.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

DatabaseManager::DatabaseManager()
{
}

bool DatabaseManager::openDatabase()
{
    if (QSqlDatabase::contains("marketplace_connection"))
    {
        m_db = QSqlDatabase::database("marketplace_connection");
    }
    else
    {
        m_db = QSqlDatabase::addDatabase("QSQLITE", "marketplace_connection");
        m_db.setDatabaseName("marketplace.db");
    }

    if (!m_db.open())
    {
        qDebug() << "Database open error:" << m_db.lastError().text();
        return false;
    }

    return true;
}

void DatabaseManager::createTables()
{
    QSqlQuery query(m_db);

    query.exec(
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "username TEXT UNIQUE NOT NULL, "
        "password TEXT NOT NULL)"
    );

    query.exec(
        "CREATE TABLE IF NOT EXISTS listings ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "title TEXT NOT NULL, "
        "category TEXT NOT NULL, "
        "price REAL NOT NULL, "
        "description TEXT, "
        "seller TEXT NOT NULL)"
    );
}

bool DatabaseManager::createUser(const QString& username, const QString& password)
{
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    return query.exec();
}

bool DatabaseManager::validateUser(const QString& username, const QString& password)
{
    QSqlQuery query(m_db);
    query.prepare("SELECT COUNT(*) FROM users WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec())
        return false;

    if (query.next())
        return query.value(0).toInt() > 0;

    return false;
}

bool DatabaseManager::addListing(const Listing& listing)
{
    QSqlQuery query(m_db);
    query.prepare(
        "INSERT INTO listings (title, category, price, description, seller) "
        "VALUES (:title, :category, :price, :description, :seller)"
    );

    query.bindValue(":title", listing.getTitle());
    query.bindValue(":category", listing.getCategory());
    query.bindValue(":price", listing.getPrice());
    query.bindValue(":description", listing.getDescription());
    query.bindValue(":seller", listing.getSeller());

    return query.exec();
}

QVector<Listing> DatabaseManager::getAllListings() const
{
    QVector<Listing> listings;
    QSqlQuery query(m_db);

    query.prepare("SELECT title, category, price, description, seller FROM listings");

    if (query.exec())
    {
        while (query.next())
        {
            listings.append(Listing(
                query.value(0).toString(),
                query.value(1).toString(),
                query.value(2).toDouble(),
                query.value(3).toString(),
                query.value(4).toString()
            ));
        }
    }

    return listings;
}

QVector<Listing> DatabaseManager::filterListings(const QString& searchText,
                                                 const QString& category) const
{
    QVector<Listing> listings;
    QSqlQuery query(m_db);

    QString sql =
        "SELECT title, category, price, description, seller "
        "FROM listings "
        "WHERE lower(title) LIKE lower(:search)";

    if (category != "All")
        sql += " AND category = :category";

    query.prepare(sql);
    query.bindValue(":search", "%" + searchText + "%");

    if (category != "All")
        query.bindValue(":category", category);

    if (query.exec())
    {
        while (query.next())
        {
            listings.append(Listing(
                query.value(0).toString(),
                query.value(1).toString(),
                query.value(2).toDouble(),
                query.value(3).toString(),
                query.value(4).toString()
            ));
        }
    }

    return listings;
}
