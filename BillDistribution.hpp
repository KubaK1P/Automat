#ifndef BILLDISTRIBUTION_HPP
#define BILLDISTRIBUTION_HPP

#include <vector>
#include <string>

class BillDistribution {
private:
    std::vector<std::pair<std::string, int>> denominations;

public:
    BillDistribution();
    void calculateChange(double change);
};

#endif // BILLDISTRIBUTION_HPP

