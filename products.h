#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <string>

using std::string;


class Product{
protected:
    double price;
    double volume;
    double weight;
    string client;
public:
    Product(double, double, double, string);
    double getPrice() const;
    double getVolume() const;
    double getWeight() const;
    string getClient() const;
    virtual double getTax() const = 0;
    virtual string toString() const = 0;
    void setPrice(double);
    void setVolume(double);
    void setWeight(double);
    void setClient(string);
};

#endif // PRODUCTS_H
