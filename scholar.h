#ifndef SCHOLAR_H
#define SCHOLAR_H

#include <string>
#include "products.h"

using std::string;


class Scholar : public Product{
    double rate;
public:
    Scholar(double, double, double, string, double);
    double getRate() const;
    virtual double getTax() const;
    virtual string toString() const;
    void setRate(double);
};

#endif // SCHOLAR_H
