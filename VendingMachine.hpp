#ifndef VENDINGMACHINE_HPP
#define VENDINGMACHINE_HPP

#include "Drink.hpp"
#include <vector>

class VendingMachine {
private:
    std::vector<Drink> drinks;
    double totalMoney;

public:
    VendingMachine();

    void displayDrinks() const;
    void purchaseDrink(int choice, double moneyInserted);
    void showTotalMoney() const;
};

#endif // VENDINGMACHINE_HPP

