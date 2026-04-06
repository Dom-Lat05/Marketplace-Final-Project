#include <iostream>
#include "user.h"

// Constructor
User::User(const std::string& username, const std::string& password)
    : username(username), password(password) {
}

// Getters
std::string User::getUsername() const {
    return username;
}

std::string User::getPassword() const {
    return password;
}

std::vector<Listing>& User::getListings() {
    return my_Listings;
}

// Login Check
bool User::login(std::string u, std::string p) const {
    return (u == username && p == password);
}

// Add Listing
void User::addListing(const Listing& listing) {
    my_Listings.push_back(listing);
}

// Remove Listing by name
void User::removeListing(const std::string& listingName) {
    for (auto it = my_Listings.begin(); it != my_Listings.end(); ++it) {
        if (it->getName() == listingName) {
            my_Listings.erase(it);
            std::cout << "Listing removed: " << listingName << "\n";
            return;
        }
    }

    std::cout << "Listing not found: " << listingName << "\n";
}

// Display User's Listings
void User::displayMyListings() const {
    std::cout << "\nListings for user: " << getUsername() << std::endl;
    for (const auto& listing : my_Listings) {
        listing.display();
        std::cout << "\n";
    }
}
