#include "Item.h"

// Constructors
Item::Item() : name(""), price(0.0), quantity(0) {}
Item::Item(const string& itemName, double itemPrice, int itemQuantity)
    : name(itemName), price(itemPrice), quantity(itemQuantity) {}

// Setters
void Item::setName(const string& itemName) { name = itemName; }
void Item::setPrice(double itemPrice) { price = itemPrice; }
void Item::setQuantity(int itemQuantity) { quantity = itemQuantity; }

// Getters
string Item::getName() const { return name; }
double Item::getPrice() const { return price; }
int Item::getQuantity() const { return quantity; }

// Equality operator
bool Item::operator==(const Item& other) const {
    return (name == other.name && price == other.price && quantity == other.quantity);
}

// Input operator
istream& operator>>(istream& in, Item& item) {
    cout << "Enter item name: ";
    in >> item.name;
    cout << "Enter item price: ";
    in >> item.price;
    cout << "Enter item quantity: ";
    in >> item.quantity;
    return in;
}

// Output operator
ostream& operator<<(ostream& out, const Item& item) {
    out << "Item: " << item.name
        << ", Price: $" << item.price
        << ", Quantity: " << item.quantity;
    return out;
}
