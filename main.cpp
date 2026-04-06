#include <iostream>
#include "marketplaceSystem.h"

int main() {
	MarketplaceSystem marketplaceSystem;

	marketplaceSystem.loadData();

	// Backend test
	marketplaceSystem.createAccount("Dom", "1234");
	marketplaceSystem.login("Dom", "1234");

	marketplaceSystem.addListing("Bike", "A nice bike", "Sports", "Used", "New York", 100.0);
	marketplaceSystem.addListing("Laptop", "A powerful laptop", "Electronics", "New", "San Francisco", 1200.0);

	std::cout << "Current User: " << marketplaceSystem.getCurrentUsername() << std::endl;
	std::cout << "Total listings: " << marketplaceSystem.getAllListings().size() << std::endl;

	marketplaceSystem.saveData();

	return 0;
}
