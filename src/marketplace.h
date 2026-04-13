#ifndef MARKETPLACE_H
#define MARKETPLACE_H

#include <string>
#include <vector>
#include "listing.h"
#include "user.h"

class Marketplace {
private:
    std::vector<User> users;
    std::vector<Listing> all_Listings;

public:
    void addUser(const User& user);
    void addListing(const Listing& listing);
    void displayAllListings() const;
    void displayMyListings(const std::string& username) const;

    std::vector<Listing>& getAllListings();
    const std::vector<Listing>& getAllListings() const;

    void searchListingsByName(const std::string& name) const;
    void filterListingsByCategory(const std::string& category) const;
    void filterListingsByPrice(double minPrice, double maxPrice) const;
    void sortListingsByPriceLowToHigh() const;
    void sortListingsByPriceHighToLow() const;
    void removeListing(const std::string& listingName);
};

#endif
