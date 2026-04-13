#ifndef MARKETPLACE_SYSTEM_H
#define MARKETPLACE_SYSTEM_H

#include <vector>
#include <string>
#include "listing.h"
#include "user.h"
#include "marketplace.h"

class MarketplaceSystem {
private:
    Marketplace marketplace;
    std::vector<User> users;
    int currentUserIndex;

public:
    MarketplaceSystem();

    void loadData();
    void saveData();

    bool createUser(const std::string& username, const std::string& password);
    bool login(const std::string& username, const std::string& password);
    void logout();

    bool isLoggedIn() const;
    std::string getCurrentUsername() const;

    bool addListing(const std::string& name, const std::string& description,
                    const std::string& category, const std::string& condition,
                    const std::string& location, double price);

    bool markListingAsSold(const std::string& listingName);

    std::vector<Listing> getAllListings() const;
    std::vector<Listing>& getMyListings();

    void filterListingsByPrice(double minPrice, double maxPrice) const;
    void sortListingsByPriceLowToHigh() const;
    void sortListingsByPriceHighToLow() const;

    int findUserIndex(const std::string& username) const;
};

#endif
