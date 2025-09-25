#include "ShoppingCart.h"

// Default constructor
ShoppingCart::ShoppingCart() : Bag<Item>(), totalPrice(0.0) {}

// Get total price
double ShoppingCart::getTotalPrice() const {
    return totalPrice;
}

// Add item and update totalPrice
bool ShoppingCart::add(const Item& newItem) {
    if (Bag<Item>::add(newItem)) {
        totalPrice += newItem.getPrice() * newItem.getQuantity();
        return true;
    }
    return false;
}

// Remove item and update totalPrice
bool ShoppingCart::remove(const Item& item) {
    if (Bag<Item>::remove(item)) {
        totalPrice -= item.getPrice() * item.getQuantity();
        return true;
    }
    return false;
}

// Clear cart and reset totalPrice
void ShoppingCart::clear() {
    Bag<Item>::clear();
    totalPrice = 0.0;
}
