// The Item class represents a product in a shopping cart.
// Coffie Boafo Gabriel Kofi
// 15784055
// 2025-09-22

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;

/**
 * @class Item
 * @brief Represents a single product in a shopping cart.
 *
 * Stores the name, unit price, and quantity of the item.
 * Provides constructors, setters, getters, and overloaded operators.
 */
class Item {
public:
    /**
     * Default constructor
     * @pre None
     * @post Creates an empty item with name="", price=0.0, quantity=0
     */
    Item();

    /**
     * Parameterized constructor
     * @param itemName Name of the item
     * @param itemPrice Price of one unit
     * @param itemQuantity Number of units
     * @pre None
     * @post Creates an item initialized with the given values
     */
    Item(const string& itemName, double itemPrice, int itemQuantity);

    /** MODIFICATION MEMBER FUNCTIONS */

    /**
     * Sets the name of the item
     * @param itemName New name for the item
     * @pre None
     * @post Name of the item is updated
     */
    void setName(const string& itemName);

    /**
     * Sets the price of the item
     * @param itemPrice New price for the item
     * @pre None
     * @post Price of the item is updated
     */
    void setPrice(double itemPrice);

    /**
     * Sets the quantity of the item
     * @param itemQuantity New quantity for the item
     * @pre None
     * @post Quantity of the item is updated
     */
    void setQuantity(int itemQuantity);

    /** CONSTANT MEMBER FUNCTIONS */

    /**
     * Gets the name of the item
     * @return Name of the item
     * @pre None
     * @post Returns name without modifying object
     */
    string getName() const;

    /**
     * Gets the price of the item
     * @return Price of the item
     * @pre None
     * @post Returns price without modifying object
     */
    double getPrice() const;

    /**
     * Gets the quantity of the item
     * @return Quantity of the item
     * @pre None
     * @post Returns quantity without modifying object
     */
    int getQuantity() const;

    /**
     * Equality operator
     * @param other Another item to compare
     * @return True if name, price, and quantity are all equal
     * @pre None
     * @post No changes to either item
     */
    bool operator==(const Item& other) const;

    /**
     * Input operator
     * @param in Input stream
     * @param item Item to fill with user input
     * @pre Input must be valid: name, price, quantity
     * @post Item fields are updated with input values
     */
    friend istream& operator>>(istream& in, Item& item);

    /**
     * Output operator
     * @param out Output stream
     * @param item Item to display
     * @pre None
     * @post Item details are printed to output stream
     */
    friend ostream& operator<<(ostream& out, const Item& item);

private:
    string name;   ///< Name of the item
    double price;  ///< Price per unit
    int quantity;  ///< Number of units
};

#endif
