#ifndef DRINK_HPP
#define DRINK_HPP

#include <string>

class Drink {
private:
    std::string name;
    double price;
    int quantity;

public:
    Drink(std::string name, double price, int quantity);

    std::string getName() const;
    double getPrice() const;
    int getQuantity() const;

    void setQuantity(int qty);
    void reduceQuantity();
};

#endif // DRINK_HPP
