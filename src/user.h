#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "listing.h"

class User {
private:
    std::string username;
    std::string password;
    std::vector<Listing> my_Listings;

public:
    User(const std::string& username, const std::string& password);

    std::string getUsername() const;
    std::string getPassword() const;
    std::vector<Listing>& getListings();

    bool login(std::string u, std::string p) const;

    void addListing(const Listing& listing);
    void removeListing(const std::string& listingName);
    void displayMyListings() const;
};

#endif
