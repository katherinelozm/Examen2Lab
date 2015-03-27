#include "products.h"
#include "luxury.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Luxury::Luxury(double price, double volume, double weight, string client, double rate)
	:Product(price, volume, weight, client), rate(rate) {

}

double Luxury::getRate() const{
	return rate;
}

double Luxury::getTax() const{
	return volume * rate + weight * rate;
}

string Luxury::toString() const{
	stringstream ss;
	ss << Product::toString() << " Rate: " << rate;
	return ss.str();
}

void Luxury::setRate(double rate){
	this->rate = rate;
}