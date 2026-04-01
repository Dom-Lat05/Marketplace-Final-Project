# Online Marketplace
The program allows users to create profiles, listings saved to their profile, search listings, and created to be simple to use for people of all ages. Users sometimes find it harder to use with newer platforms and this creates a place that is easier to use. This is meant to be a straight forwards marketplace

---

## Project Team
- Dominic LaTorraca
- Timothy Muehl
- Joao Olivo
  
---

## How to Run

### Requirments
- C++ Complier (ex. Visual Studio 2022, CLion)
- GUI framework used: Qt

### Steps
1. Clone the repository
2. Open Project in your IDE
3. Build the project
4. Run the application

---

## Features
1. **Account Creation** <br>
Users can create a personalized account with a username and passcode.

2. **Login System** <br>
Existing users can log into their account securely.

3. **Create Lisitings** <br>
Users can post items for sale with details like name, description, condition, and price.

4. **Search Listings** <br>
Users can search for items by name or keyword.

5. **Filter Listings** <br>
Users can filter by category or condition.

6. **Edit Listings** <br>
Sellers can update their listings whenver they need to.

7. **Mark Sold/Remove Listings** <br>
Users can mark items as sold or completely delete their listings.

---

## OOP Concepts Used

### Encapsulation
- Each class (User, Listing, Marketplace) uses private attributes with public member functions to control access and not have data leaks

### Inheritance
- Listing categories can be extended into categories for filters on search such as electronics and Furniture

### Polymorphism
- Different listing categories can override display or behavior functions depending on type

### Composition
- The Marketplace class will have the User and Listings classes
- The User class will have the different listings (relationship)

---

## Team Contributions
 ### Dominic LaTorraca
 - Project Design
 - Implementation of Marketplace and Core Logic
 - GUI concept design and implementation

### Timothy Muehl
- Listing Class implementation
- Search and filter functionality
- Editing and marking listings as sold

### Joao Olivo
- User class implementation
- Account System (Creation and login)
- Input Validation

---

## AI and External Resources Disclosure

### AI Tools
#### ChatGPT:

### External Resources
1. https://cplusplus.com (used for C++ references and vectors)
2. Stack Overflow
https://stackoverflow.com/questions
3. QT (Used for GUI)
https://www.qt.io/development/qt-framework

---

### Collaboration Policy Statement
All submitted work reflects our team’s understanding. Any external code has been:
- Reviewed  
- Modified as needed  
- Integrated by our team  

Failure to disclose AI or external resources may be considered an academic integrity violation.
