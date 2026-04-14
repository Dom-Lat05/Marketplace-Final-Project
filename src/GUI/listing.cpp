#include "listing.h"

Listing::Listing()
    : m_price(0.0)
{
}

Listing::Listing(const QString& title,
                 const QString& category,
                 double price,
                 const QString& description,
                 const QString& seller)
    : m_title(title),
      m_category(category),
      m_price(price),
      m_description(description),
      m_seller(seller)
{
}

QString Listing::getTitle() const
{
    return m_title;
}

QString Listing::getCategory() const
{
    return m_category;
}

double Listing::getPrice() const
{
    return m_price;
}

QString Listing::getDescription() const
{
    return m_description;
}

QString Listing::getSeller() const
{
    return m_seller;
}

QString Listing::toDisplayString() const
{
    return m_title + " | " + m_category + " | $" +
           QString::number(m_price, 'f', 2) +
           " | Seller: " + m_seller;
}
