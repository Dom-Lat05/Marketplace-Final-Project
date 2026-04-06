#include <iostream>
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
