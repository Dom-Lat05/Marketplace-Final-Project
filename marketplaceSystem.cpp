#include "marketplaceSystem.h"
#include <fstream>
#include <iostream>

MarketplaceSystem::MarketplaceSystem() : currentUserIndex(-1) {
}

int MarketplaceSystem::findUserIndex(const std::string& username) const {
	for (size_t i = 0; i < users.size(); ++i) {
		if (users[i].getUsername() == username) {
			return i;
		}
	}
	return -1; // User not found
}

bool MarketplaceSystem::createUser(const std::string& username, const std::string& password) {
	if (findUserIndex(username) != -1) {
		std::cout << "Username already exists. Please choose a different username.\n";
		return false; // User already exists
	}
	users.emplace_back(username, password);
	marketplace.addUser(users.back());
	std::cout << "User created successfully: " << username << "\n";
	return true;
}

bool MarketplaceSystem::login(const std::string& username, const std::string& password) {
	int index = findUserIndex(username);
	if (index != -1 && users[index].login(username, password)) {
		currentUserIndex = index;
		std::cout << "Login successful. Welcome, " << username << "!\n";
		return true;
	}
	std::cout << "Invalid username or password. Please try again.\n";
	return false; // Login failed
}

void MarketplaceSystem::logout() {
	if (isLoggedIn()) {
		std::cout << "User " << getCurrentUsername() << " logged out successfully.\n";
		currentUserIndex = -1;
	} else {
		std::cout << "No user is currently logged in.\n";
	}
}

bool MarketplaceSystem::isLoggedIn() const {
	return currentUserIndex != -1;
}

std::string MarketplaceSystem::getCurrentUsername() const {
	if (isLoggedIn()) {
		return users[currentUserIndex].getUsername();
	}
	return ""; // No user logged in
}

bool MarketplaceSystem::addListing(const std::string& name, const std::string& description, const std::string& category,
	const std::string& condition, const std::string& location, double price) {
	if (!isLoggedIn()) {
		std::cout << "You must be logged in to add a listing.\n";
		return false; // User not logged in
	}

	Listing newListing(name, description, category, condition, "Available", location, price);

	marketplace.addListing(newListing);
	users[currentUserIndex].addListing(name);

	std::cout << "Listing added successfully: " << name << "\n";

	return true;
}

bool MarketplaceSystem::markListingAsSold(const std::string& listingName) {
	if (!isLoggedIn()) {
		std::cout << "You must be logged in to mark a listing as sold.\n";

		return false; // User not logged in
	}

	for (auto& listing : marketplace.getAllListings()) {
		if (listing.getName() == listingName) {
			listing.markAsSold();

			std::cout << "Listing marked as sold: " << listingName << "\n";
			return true; // Listing found and marked as sold
		}
	}

	std::cout << "Listing not found: " << listingName << "\n";
	return false; // Listing not found
}

std::vector<Listing> MarketplaceSystem::getAllListings() const {
	return marketplace.getAllListings();
}

std::vector<Listing>& MarketplaceSystem::getMyListings() {
	return users[currentUserIndex].getMyListings();
}

void MarketplaceSystem::loadData() {
	std::ifstream userFile("users.txt");
	std::ifstream listingFile("listings.txt");
	if (userFile.is_open()) {
		std::string username, password;
		while (userFile >> username >> password) {
			createUser(username, password);
		}
		userFile.close();
	}
	if (listingFile.is_open()) {
		std::string name, description, category, condition, item_status, location;
		double price;
		while (listingFile >> name >> description >> category >> condition >> item_status >> location >> price) {
			addListing(name, description, category, condition, location, price);
		}
		listingFile.close();
	}
}

void MarketplaceSystem::saveData() {
	std::ofstream userFile("users.txt");
	std::ofstream listingFile("listings.txt");
	if (userFile.is_open()) {
		for (const auto& user : users) {
			userFile << user.getUsername() << " " << user.getMyListings().size() << "\n";
		}
		userFile.close();
	}
	if (listingFile.is_open()) {
		for (const auto& listing : marketplace.getAllListings()) {
			listingFile << listing.getName() << " " << listing.getDescription() << " "
				<< listing.getCategory() << " " << listing.getCondition() << " "
				<< listing.getItemStatus() << " " << listing.getLocation() << " "
				<< listing.getPrice() << "\n";
		}
		listingFile.close();
	}
}
