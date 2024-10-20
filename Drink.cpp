#include "Drink.hpp"

Drink::Drink(std::string name, double price, int quantity)
    : name(name), price(price), quantity(quantity) {}

std::string Drink::getName() const {
    return name;
}

double Drink::getPrice() const {
    return price;
}

int Drink::getQuantity() const {
    return quantity;
}

void Drink::setQuantity(int qty) {
    quantity = qty;
}

void Drink::reduceQuantity() {
    if (quantity > 0) {
        quantity--;
    }
}

