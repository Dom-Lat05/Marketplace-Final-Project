#ifndef LISTING_H
#define LISTING_H

#include <string>

class Listing {
private:
    std::string name;
    std::string description;
    std::string category;
    std::string condition;
    std::string item_status;
    std::string location;
    double price;

public:
    Listing(const std::string& name, const std::string& description, const std::string& category,
        const std::string& condition, const std::string& item_status,
        const std::string& location, double price);

    void display() const;
    void displayDetails() const;
    void updateDetails(const std::string& new_description, const std::string& new_category,
        const std::string& new_condition, const std::string& new_item_status,
        const std::string& new_location, double new_price);
    void markAsSold();

    std::string getName() const;
    std::string getDescription() const;
    std::string getCategory() const;
    double getPrice() const;
    std::string getCondition() const;
    std::string getStatus() const;
    std::string getLocation() const;
};

#endif
