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
    query.exec("CREATE TABLE IF NOT EXISTS listings ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "title TEXT, "
               "category TEXT, "
               "price REAL, "
               "description TEXT, "
               "seller TEXT, "
               "sold INTEGER DEFAULT 0)");
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
    query.prepare("INSERT INTO listings (title, category, price, description, seller, sold) "
                  "VALUES (:t, :c, :p, :d, :s, :sold)");
    query.bindValue(":t", listing.getTitle());
    query.bindValue(":c", listing.getCategory());
    query.bindValue(":p", listing.getPrice());
    query.bindValue(":d", listing.getDescription());
    query.bindValue(":s", listing.getSeller());
    query.bindValue(":sold", listing.isSold() ? 1 : 0);
    query.exec();
}

QVector<Listing> DatabaseManager::getAllListings()
{
    QVector<Listing> list;
    QSqlQuery query("SELECT id, title, category, price, description, seller, sold FROM listings");

    while (query.next())
    {
        list.append(Listing(
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toString(),
            query.value(3).toDouble(),
            query.value(4).toString(),
            query.value(5).toString(),
            query.value(6).toInt() == 1
        ));
    }

    return list;
}

QVector<Listing> DatabaseManager::filterListings(const QString& search, const QString& category)
{
    QVector<Listing> list;
    QSqlQuery query;

    QString sql = "SELECT id, title, category, price, description, seller, sold "
                  "FROM listings WHERE title LIKE :search";

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
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toString(),
            query.value(3).toDouble(),
            query.value(4).toString(),
            query.value(5).toString(),
            query.value(6).toInt() == 1
        ));
    }

    return list;
}

QVector<Listing> DatabaseManager::getListingsBySeller(const QString& seller)
{
    QVector<Listing> list;
    QSqlQuery query;
    query.prepare("SELECT id, title, category, price, description, seller, sold "
                  "FROM listings WHERE seller = :seller");
    query.bindValue(":seller", seller);
    query.exec();

    while (query.next())
    {
        list.append(Listing(
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toString(),
            query.value(3).toDouble(),
            query.value(4).toString(),
            query.value(5).toString(),
            query.value(6).toInt() == 1
        ));
    }

    return list;
}

bool DatabaseManager::updateListing(int id, const QString& title, const QString& category, double price, const QString& description)
{
    QSqlQuery query;
    query.prepare("UPDATE listings SET title = :title, category = :category, "
                  "price = :price, description = :description WHERE id = :id");
    query.bindValue(":title", title);
    query.bindValue(":category", category);
    query.bindValue(":price", price);
    query.bindValue(":description", description);
    query.bindValue(":id", id);
    return query.exec();
}

bool DatabaseManager::markListingSold(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE listings SET sold = 1 WHERE id = :id");
    query.bindValue(":id", id);
    return query.exec();
}
