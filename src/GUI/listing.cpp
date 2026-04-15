#include "listing.h"

Listing::Listing()
    : m_id(-1),
      m_price(0.0),
      m_sold(false)
{
}

Listing::Listing(const QString& title,
                 const QString& category,
                 double price,
                 const QString& description,
                 const QString& seller)
    : m_id(-1),
      m_title(title),
      m_category(category),
      m_price(price),
      m_description(description),
      m_seller(seller),
      m_sold(false)
{
}

Listing::Listing(int id,
                 const QString& title,
                 const QString& category,
                 double price,
                 const QString& description,
                 const QString& seller,
                 bool sold)
    : m_id(id),
      m_title(title),
      m_category(category),
      m_price(price),
      m_description(description),
      m_seller(seller),
      m_sold(sold)
{
}

int Listing::getId() const
{
    return m_id;
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

bool Listing::isSold() const
{
    return m_sold;
}

QString Listing::toDisplayString() const
{
    QString soldText = m_sold ? " | SOLD" : "";
    return m_title + " | " + m_category + " | $" +
           QString::number(m_price, 'f', 2) +
           " | Seller: " + m_seller + soldText;
}
