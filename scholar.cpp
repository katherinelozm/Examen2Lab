#include "products.h"
#include "scholar.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Scholar::Scholar(double price, double volume, double weight, string client, double rate)
	:Product(price, volume, weight, client), rate(rate) {

}

double Scholar::getRate() const{
	return rate;
}

double Scholar::getTax() const{
	return volume*rate;
}

string Scholar::toString() const{
	stringstream ss;
	ss << Product::toString() << " Rate: " << rate;
	return ss.str();
}

void Scholar::setRate(double rate){
	this->rate = rate;
}