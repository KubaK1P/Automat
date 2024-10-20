#include "BillDistribution.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

BillDistribution::BillDistribution() {
    denominations = {
        {"100 PLN Bill", 10000},
        {"50 PLN Bill", 5000},
        {"20 PLN Bill", 2000},
        {"10 PLN Bill", 1000},
        {"5 PLN Coin", 500},
        {"2 PLN Coin", 200},
        {"1 PLN Coin", 100},
        {"50 Groszy", 50},
        {"25 Groszy", 25},
        {"10 Groszy", 10},
        {"5 Groszy", 5},
        {"1 Grosz", 1}
    };
}

void BillDistribution::calculateChange(double change) {
    int remainingAmount = static_cast<int>(change * 100);

    cout << "You will receive:\n";

    for (const auto& denomination : denominations) {
        int count = remainingAmount / denomination.second;
        if (count > 0) {
            cout << count << " x " << denomination.first << endl;
            remainingAmount -= count * denomination.second;
        }
    }

    if (remainingAmount > 0) {
        cout << "Sorry, unable to return exact change for remaining: PLN"
             << fixed << setprecision(2) << remainingAmount / 100.0 << endl;
    }
}

