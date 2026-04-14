#include "marketplacemanager.h"

MarketplaceManager::MarketplaceManager()
{
}

void MarketplaceManager::addListing(const Listing& listing)
{
    m_listings.append(listing);
}

QVector<Listing> MarketplaceManager::getAllListings() const
{
    return m_listings;
}

QVector<Listing> MarketplaceManager::filterListings(const QString& searchText,
                                                    const QString& category) const
{
    QVector<Listing> filteredListings;
    QString lowerSearch = searchText.trimmed().toLower();

    for (const Listing& listing : m_listings)
    {
        bool matchesSearch = listing.getTitle().toLower().contains(lowerSearch);
        bool matchesCategory = (category == "All" || listing.getCategory() == category);

        if (matchesSearch && matchesCategory)
        {
            filteredListings.append(listing);
        }
    }

    return filteredListings;
}

void MarketplaceManager::loadSampleListings()
{
    m_listings.clear();

    m_listings.append(Listing("Gaming Laptop", "Electronics", 900.00,
                              "High performance laptop", "Dom"));
    m_listings.append(Listing("Office Chair", "Furniture", 120.00,
                              "Comfortable desk chair", "Alex"));
    m_listings.append(Listing("Hoodie", "Clothing", 40.00,
                              "Black hoodie in good condition", "Sam"));
}
