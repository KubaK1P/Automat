#include "VendingMachine.hpp"
#include <iostream>

int main() {
    VendingMachine vendingMachine;
    int choice;
    double moneyInserted;

    while (true) {
        vendingMachine.displayDrinks();
        std::cout << "\nEnter the ID of the drink you want to purchase (or 0 to quit): ";
        std::cin >> choice;

        if (choice == 0) {
            break;
        }

        std::cout << "Insert money: PLN";
        std::cin >> moneyInserted;

        vendingMachine.purchaseDrink(choice, moneyInserted);
    }

    vendingMachine.showTotalMoney();

    return 0;
}

