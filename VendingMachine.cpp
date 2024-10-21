#include "VendingMachine.hpp"
#include "BillDistribution.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

VendingMachine::VendingMachine() : totalMoney(0) {
    // Initialize vending machine with some drinks
    drinks.push_back(Drink("CocaCola", 1.50, 10));
    drinks.push_back(Drink("Pepsi", 1.40, 8));
    drinks.push_back(Drink("Water", 1.00, 15));
    drinks.push_back(Drink("Juice", 2.00, 5));
}

void VendingMachine::displayDrinks() const {
    cout << "\nAvailable Drinks:\n";
    cout << left << setw(5) << "ID" << setw(15) << "Drink" << setw(10) << "Price" << "Quantity" << endl;
    for (size_t i = 0; i < drinks.size(); ++i) {
        cout << left << setw(5) << i + 1 << setw(15) << drinks[i].getName()
             << "PLN " << setw(9) << fixed << setprecision(2) << drinks[i].getPrice()
             << drinks[i].getQuantity() << endl;
    }
}

void VendingMachine::purchaseDrink(int choice, double moneyInserted) {
    if (choice < 1 || choice > drinks.size()) {
        cout << "Invalid choice!" << endl;
        return;
    }

    Drink& selectedDrink = drinks[choice - 1];

    if (selectedDrink.getQuantity() == 0) {
        cout << "Sorry, " << selectedDrink.getName() << " is not with us anymore :/" << endl;
        return;
    }

    if (moneyInserted < selectedDrink.getPrice()) {
        cout << "Insufficient money. " << selectedDrink.getName() << " costs PLN"
             << fixed << setprecision(2) << selectedDrink.getPrice() << endl;
        return;
    }

    // Process the transaction
    selectedDrink.reduceQuantity();
    totalMoney += selectedDrink.getPrice();
    double change = moneyInserted - selectedDrink.getPrice();

    cout << "Dispensing " << selectedDrink.getName() << endl;
    if (change > 0) {
        cout << "Your change is: PLN" << fixed << setprecision(2) << change << endl;
        BillDistribution changeObject;
        changeObject.calculateChange(change);
    }
    cout << "Thank you for your purchase!\n" << endl;
}

void VendingMachine::showTotalMoney() const {
    cout << "\nTotal money collected by the machine: PLN"
         << fixed << setprecision(2) << totalMoney << endl;
}

void VendingMachine::addDrink(string name, float price, int quantity) {
    drinks.push_back(Drink(name, price, quantity));
}