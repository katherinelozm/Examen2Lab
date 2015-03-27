#ifndef LUXURY_H
#define LUXURY_H

#include <string>
#include "products.h"

using std::string;


class Luxury : public Product{
    double rate;
public:
    Luxury(double, double, double, string, double);
    double getRate() const;
    virtual double getTax() const;
    virtual string toString() const;
    void setRate(double);
};

#endif // LUXURY_H
