#include <iostream>
#include <algorithm>
#include "marketplace.h"

// Add User
void Marketplace::addUser(const User& user) {
    users.push_back(user);
}

// Add Listing
void Marketplace::addListing(const Listing& listing) {
    all_Listings.push_back(listing);
}

// Display All Listings
void Marketplace::displayAllListings() const {
    std::cout << "All Listings in the Marketplace:\n";
    for (const auto& listing : all_Listings) {
        listing.display();
        std::cout << "-------------------------\n";
    }
}

// Display my listings
void Marketplace::displayMyListings(const std::string& username) const {
    std::cout << "Listings for user: " << username << "\n";

    bool found = false;

    for (const auto& listing : all_Listings) {
        if (listing.getName() == username) {
            listing.display();
            std::cout << "-------------------------\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "No listings found for user: " << username << "\n";
    }
}

// Get all listings
std::vector<Listing>& Marketplace::getAllListings() {
    return all_Listings;
}

const std::vector<Listing>& Marketplace::getAllListings() const {
    return all_Listings;
}

// Search listings by name
void Marketplace::searchListingsByName(const std::string& name) const {
    bool found = false;

    std::cout << "Search Results for Name: " << name << "\n";
    for (const auto& listing : all_Listings) {
        if (listing.getName() == name) {
            listing.display();
            std::cout << "-------------------------\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "No listings found with the name: " << name << "\n";
    }
}

// Filter by Category
void Marketplace::filterListingsByCategory(const std::string& category) const {
    bool found = false;

    std::cout << "Filter Results for Category: " << category << "\n";
    for (const auto& listing : all_Listings) {
        if (listing.getCategory() == category) {
            listing.display();
            std::cout << "-------------------------\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "No listings found in the category: " << category << "\n";
    }
}

// Filter by Price
void Marketplace::filterListingsByPrice(double minPrice, double maxPrice) const {
    bool found = false;

    std::cout << "Filter Results for Price Range: $" << minPrice
              << " - $" << maxPrice << "\n";

    for (const auto& listing : all_Listings) {
        if (listing.getPrice() >= minPrice && listing.getPrice() <= maxPrice) {
            listing.display();
            std::cout << "-------------------------\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "No listings found in that price range.\n";
    }
}

// Sort by Price Low to High
void Marketplace::sortListingsByPriceLowToHigh() const {
    std::vector<Listing> sortedListings = all_Listings;

    std::sort(sortedListings.begin(), sortedListings.end(),
        [](const Listing& a, const Listing& b) {
            return a.getPrice() < b.getPrice();
        });

    if (sortedListings.empty()) {
        std::cout << "No listings available to sort.\n";
        return;
    }

    std::cout << "Listings Sorted by Price (Low to High):\n";
    for (const auto& listing : sortedListings) {
        listing.display();
        std::cout << "-------------------------\n";
    }
}

// Sort by Price High to Low
void Marketplace::sortListingsByPriceHighToLow() const {
    std::vector<Listing> sortedListings = all_Listings;

    std::sort(sortedListings.begin(), sortedListings.end(),
        [](const Listing& a, const Listing& b) {
            return a.getPrice() > b.getPrice();
        });

    if (sortedListings.empty()) {
        std::cout << "No listings available to sort.\n";
        return;
    }

    std::cout << "Listings Sorted by Price (High to Low):\n";
    for (const auto& listing : sortedListings) {
        listing.display();
        std::cout << "-------------------------\n";
    }
}

// Remove listing
void Marketplace::removeListing(const std::string& listingName) {
    for (auto it = all_Listings.begin(); it != all_Listings.end(); ++it) {
        if (it->getName() == listingName) {
            all_Listings.erase(it);
            std::cout << "Listing removed: " << listingName << "\n";
            return;
        }
    }

    std::cout << "Listing not found: " << listingName << "\n";
}
