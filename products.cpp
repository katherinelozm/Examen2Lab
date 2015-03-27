#include "products.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Product::Product(double price, double volume, double weight, string client)
    :price(price), volume(volume), weight(weight), client(client) {

}

double Product::getPrice() const{
    return price;
}

double Product::getVolume() const{
    return volume;
}

double Product::getWeight() const{
    return weight;
}

string Product::getClient() const{
    return client;
}

string Product::toString() const{
	stringstream ss;
	ss << "Client: " << client << " Price: " << price << " Volume: " << volume << " Weight: " << weight;
	return ss.str();
}

void Product::setPrice(double price){
    this->price = price;
}

void Product::setVolume(double volume){
    this->volume = volume;
}

void Product::setWeight(double weight){
    this->weight = weight;
}

void Product::setClient(string client){
    this->client = client;
}
