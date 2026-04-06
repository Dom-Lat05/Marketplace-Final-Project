// Asked built in Copilot how to have it work with a GUI and it said to create a class that manages everything in the backend
// Not sure what the ifndef and define mean but I will look into it

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

	bool addListing(const std::string& name, const std::string& description, const std::string& category,
		const std::string& condition, const std::string& location, double price);
	
	bool markListingAsSold(const std::string& listingName);

	std::vector<Listing> getAllListings() const;
	std::vector<Listing>& getMyListings();

	int findUserIndex(const std::string& username) const;

};

#endif
