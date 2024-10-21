#include "VendingMachine.hpp"
#include <iostream>

int main() {
    VendingMachine vendingMachine;
    int choice;
    double moneyInserted;
    std::string name = "";
    int quantity = 0;
    float price = 0;
    while (true) {
        vendingMachine.displayDrinks();
        std::cout << "\nEnter the ID of the drink you want to purchase (or 0 to quit, or -1 to add a drink): ";
        std::cin >> choice;

        if (choice == 0) {
            break;
        }
        if (choice == -1) {
            std::cout << "Input the drink name: " << std::endl;
            std::cin >> name;
            std::cout << "Input the drink price: " << std::endl;
            std::cin >> price;
            std::cout << "Input the drink quantity: " << std::endl;
            std::cin >> quantity;
            vendingMachine.addDrink(name, price, quantity);
            name = "";
            price, quantity = 0;
            vendingMachine.displayDrinks();
            continue;
        }

        std::cout << "Insert money PLN:  ";
        std::cin >> moneyInserted;

        vendingMachine.purchaseDrink(choice, moneyInserted);
    }

    vendingMachine.showTotalMoney();

    return 0;
}

