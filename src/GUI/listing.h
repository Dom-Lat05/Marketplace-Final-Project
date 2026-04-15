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
    
    QString getTitle() const;
    QString getCategory() const;
    double getPrice() const;
    QString getDescription() const;
    QString getSeller() const;
    
    QString toDisplayString() const;
    
private:
    QString m_title;
    QString m_category;
    double m_price;
    QString m_description;
    QString m_seller;
};

#endif // LISTING_H
