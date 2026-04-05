#include <iostream>
#include "listing.h"

// Constructor
Listing::Listing(const std::string& name, const std::string& description, const std::string& category,
				 const std::string& condition, const std::string& item_status, const std::string& location, double price)
	: name(name), description(description), category(category), condition(condition),
	item_status(item_status), location(location), price(price) {
}

// Display Listing
void Listing::display() const {
	std::cout << "Name: " << name << "\n"
		<< "Description: " << description << "\n"
		<< "Category: " << category << "\n"
		<< "Condition: " << condition << "\n"
		<< "Item Status: " << item_status << "\n"
		<< "Location: " << location << "\n"
		<< "Price: $" << price << "\n";
}

// Edit Listing
void Listing::updateDetails(const std::string& new_description, const std::string& new_category,
	const std::string& new_condition, const std::string& new_item_status,
	const std::string& new_location, double new_price) {
	description = new_description;
	category = new_category;
	condition = new_condition;
	item_status = new_item_status;
	location = new_location;
	price = new_price;
}

// Mark Item as Sold
void Listing::markAsSold() {
	item_status = "Sold";
}

// Getters
std::string Listing::getName() const { return name; }
std::string Listing::getDescription() const { return description; }
std::string Listing::getCategory() const { return category; }
std::string Listing::getCondition() const { return condition; }
std::string Listing::getItemStatus() const { return item_status; }
std::string Listing::getLocation() const { return location; }
double Listing::getPrice() const { return price; }
