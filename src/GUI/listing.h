#ifndef LISTING_H
#define LISTING_H

#include <QString>

class Listing
{
public:
    Listing();
    Listing(const QString& title,
            const QString& category,
            double price,
            const QString& description,
            const QString& seller);

    Listing(int id,
            const QString& title,
            const QString& category,
            double price,
            const QString& description,
            const QString& seller,
            bool sold);

    int getId() const;
    QString getTitle() const;
    QString getCategory() const;
    double getPrice() const;
    QString getDescription() const;
    QString getSeller() const;
    bool isSold() const;

    QString toDisplayString() const;

private:
    int m_id;
    QString m_title;
    QString m_category;
    double m_price;
    QString m_description;
    QString m_seller;
    bool m_sold;
};

#endif // LISTING_H
