#include "products.h"
#include "alcohol.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Alcohol::Alcohol(double price, double volume, double weight, string client, double rate)
	:Product(price, volume, weight, client), rate(rate) {

}

double Alcohol::getRate() const{
	return rate;
}

double Alcohol::getTax() const{
	return volume * rate;
}

string Alcohol::toString() const{
	stringstream ss;
	ss << Product::toString() << " Rate: " << rate;
	return ss.str();
}

void Alcohol::setRate(double rate){
	this->rate = rate;
}