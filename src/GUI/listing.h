#ifndef LISTING_H
#define LISTING_H

#include <QString>

class Listing
{
public:
    Listing() {}
    Listing(const QString& title, const QString& category, double price, const QString& seller)
        : m_title(title), m_category(category), m_price(price), m_seller(seller) {}

    QString toDisplayString() const
    {
        return m_title + " | " + m_category + " | $" + QString::number(m_price) + " | " + m_seller;
    }

    QString getTitle() const { return m_title; }
    QString getCategory() const { return m_category; }
    double getPrice() const { return m_price; }
    QString getSeller() const { return m_seller; }

private:
    QString m_title;
    QString m_category;
    double m_price;
    QString m_seller;
};

#endif // LISTING_H
