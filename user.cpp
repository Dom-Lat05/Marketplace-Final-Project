#include <iostream>
#include "user.h"

// Constructor
User::User(const std::string& username, const std::string& password)
	: username(username), password(password) {
}

// Get username
std::string User::getUsername() const { return username; }

// Login Check
bool User::login(std::string u, std::string p) const {
	return (u == username && p == password);
}

// Add Listing
void User::addListing(const std::string& listing) {
	my_Listings.push_back(listing);
}

// Remove Listing by name
void User::removeListing(const std::string& listing) {
	for (auto it = my_Listings.begin(); it != my_Listings.end(); ++it) {
		if (*it == listing) {
			my_Listings.erase(it);
			std::cout << "Listing removed: " << listing << "\n";
			return;
		}
	}
	std::cout << "Listing not found: " << listing << "\n";
}

// Display User's Listings
void User::displayMyListings() const {
	std::cout << "\nListings for user: " << getUsername() << std::endl;
	for (const auto& listing : my_Listings) {
		std::cout << "- " << listing << "\n";
	}
}

// Getters for My Listings
std::vector<std::string> User::getMyListings() const {
	return my_Listings;
}
