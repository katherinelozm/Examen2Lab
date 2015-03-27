#ifndef ALCOHOL_H
#define ALCOHOL_H

#include <string>
#include "products.h"

using std::string;


class Alcohol : public Product{
    double rate;
public:
    Alcohol(double, double, double, string, double);
    double getRate() const;
    virtual double getTax() const;
    virtual string toString() const;
    void setRate(double);
};

#endif // ALCOHOL_H
