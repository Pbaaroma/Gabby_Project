#include <iostream>
#include <iomanip>
#include "ShoppingCart.h"
using namespace std;

void displayCart(const ShoppingCart& cart) {
    cout << "-------------------------------------------------\n";
    cout << "You have ordered the following items:\n";
    cout << left << setw(15) << "Name" 
         << setw(12) << "Unit_Price" 
         << setw(10) << "Quantity" << endl;

    vector<Item> items = cart.toVector();
    for (const Item& item : items) {
        cout << left << setw(15) << item.getName()
             << "$" << setw(11) << fixed << setprecision(2) << item.getPrice()
             << setw(10) << item.getQuantity() << endl;
    }
    cout << "The total charge is $" << fixed << setprecision(2) << cart.getTotalPrice() << endl;
    cout << "--------------------------------------------------\n";
}

int main() {
    ShoppingCart cart;
    Item item;
    char choice;

    cout << "Welcome to XXX SHOPPING CENTER.\n";
    cout << "Enter the item you selected as the following order:\n";
    cout << "name unitPrice quantity\n";
    cout << "(Name can not contain any space. Otherwise errors happen!)\n";

    // Add items interactively
    do {
        cout << "--> ";
        cin >> item;
        cart.add(item);

        cout << "Want to continue y/n--> ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Display initial order
    cout << "Here is your order:\n";
    displayCart(cart);

    // Modification loop
    do {
        cout << "Want to modify your order? y/n--> ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') break;

        int action;
        cout << "What do you want? Enter 1: add 2: remove 3: change quantity\n--> ";
        cin >> action;

        if (action == 1) {
            cout << "Enter the item to add as the following order:\n";
            cout << "name unitPrice quantity\n--> ";
            cin >> item;
            cart.add(item);
            cout << "The item has been added.\n";
        } 
        else if (action == 2) {
            cout << "Enter the item to remove as the following order:\n";
            cout << "name unitPrice quantity\n--> ";
            cin >> item;
            if (cart.remove(item))
                cout << "The item has been removed.\n";
            else
                cout << "No such item in your shopping cart!\n";
        } 
        else if (action == 3) {
            cout << "Enter the item to change as the following order:\n";
            cout << "name unitPrice quantity\n--> ";
            cin >> item;

            vector<Item> items = cart.toVector();
            bool found = false;
            for (Item& i : items) {
                if (i == item) {
                    int newQty;
                    do {
                        cout << "Enter a new quantity --> ";
                        cin >> newQty;
                        if (newQty <= 0)
                            cout << newQty << " is not a valid input.\n";
                    } while (newQty <= 0);
                    // Remove old item, add new item with updated quantity
                    cart.remove(i);
                    i.setQuantity(newQty);
                    cart.add(i);
                    cout << "The quantity has been modified.\n";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "No such item in your shopping cart!\n";
        }
    } while (choice == 'y' || choice == 'Y');

    cout << "Here is your updated order:\n";
    displayCart(cart);
    cout << "Thanks for shopping in XXX SHOPPING CENTER\n";

    return 0;
}
