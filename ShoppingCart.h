// The Item class represents a product in a shopping cart.
// Coffie Boafo Gabriel Kofi
// 15784055
// 2025-09-22
// Jie Meichsner
#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include "Bag.h"
#include "Item.h"

/**
 * @class ShoppingCart
 * @brief Derived class from Bag<Item> that represents a shopping cart
 *
 * Keeps track of total price and allows adding, removing, and clearing items.
 */
class ShoppingCart : public Bag<Item> {
private:
    double totalPrice; ///< Total price of items in the cart

public:
    /**
     * Default constructor
     * @pre None
     * @post Creates an empty shopping cart with totalPrice = 0
     */
    ShoppingCart();

    /**
     * Gets the total price of all items in the cart
     * @return totalPrice
     * @pre None
     * @post Returns the current total price of items
     */
    double getTotalPrice() const;

    /**
     * Adds an item to the shopping cart
     * @param newItem Item to add
     * @pre Cart is not full
     * @post Item is added and totalPrice updated
     * @return true if item added successfully, false otherwise
     */
    bool add(const Item& newItem);

    /**
     * Removes an item from the shopping cart
     * @param item Item to remove
     * @pre None
     * @post Item is removed and totalPrice updated
     * @return true if item removed, false otherwise
     */
    bool remove(const Item& item);

    /**
     * Clears all items from the shopping cart
     * @pre None
     * @post Cart is empty and totalPrice is reset to 0
     */
    void clear();
};
# include "ShoppingCart.cpp"
#endif
