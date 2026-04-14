#ifndef MARKETPLACEMANAGER_H
#define MARKETPLACEMANAGER_H

#include "listing.h"
#include <QVector>
#include <QString>

class MarketplaceManager
{
public:
    MarketplaceManager();

    void addListing(const Listing& listing);
    QVector<Listing> getAllListings() const;
    QVector<Listing> filterListings(const QString& searchText,
                                    const QString& category) const;

    void loadSampleListings();

private:
    QVector<Listing> m_listings;
};

#endif // MARKETPLACEMANAGER_H
