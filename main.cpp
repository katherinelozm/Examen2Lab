#include <iostream>
#include <string>
#include "products.h"
#include "scholar.h"
#include "alcohol.h"
#include "luxury.h"
#include <vector>

using namespace std;

int menu();
void CreateProduct(vector<Product*>&,double,double,double);

int main(int argc, char* argv[]){
	int option = menu();
	vector<Product*> myproducts;
	double ratescholar, ratealcohol, rateluxury;
	cout<<"Welcome!\nPlease introduce the following:\n Rate for Scholar products: ";
	cin>>ratescholar;
	cout<<"Rate for Alcoholic products: ";
	cin>>ratealcohol;
	cout<<"Rate for Luxury Products: ";
	cin>>rateluxury;
	while(option<3){
		if(option==1){

		}else if(option==2){

		}
	}
	cout<<"Have a good day!"<<endl;

	return 0;
}

int menu(){
	cout<<"Welcome!\nChoose what you'd like to do:\n1)Add Product\n2)List Products\n3)Exit\n:";
	int option;
	cin>>option;
	return option;
}

void CreateProduct(vector<Product*>& myproducts, double ratescholar, double ratealcohol, double rateluxury){
	string client;
	int option;
	double price, volume, weight;
	string type;
	cout<<"Client: ";
	cin>>client;
	cout<<"Price: ";
	cin>>price;
	cout<<"Volume: ";
	cin>>volume;
	cout<<"Weight: ";
	cin>>weight;
	cout<<"1) Scholar\n2) Alcoholic\n3) Luxury"<<endl;
	cin>>option;
	while(option<1 || option>3){
		if(option==1){
			type = "Scholar";
		}else if(option==2){
			type = "Alcohol";
		}else if(option==3){
			type = "Luxury";
		}else{
			cout<<"Invalid option, please choose between 1 and 3!\nChoose: ";
			cin>>option;
		}
	}

	if(type=="Scholar"){
		//double price, double volume, double weight, string client, double rate
		myproducts.push_back(new Scholar(price,volume,weight,client,ratescholar));
	}else if(type=="Alcohol"){
		//double price, double volume, double weight, string client, double rate
		myproducts.push_back(new Alcohol(price,volume,weight,client,ratealcohol));
	}else{
		//double price, double volume, double weight, string client, double rate
		myproducts.push_back(new Luxury(price,volume,weight,client,rateluxury));
	}

}

bool isScholar(vector<Product*> products, int pos){
    if (Scholar* a = dynamic_cast<Scholar*>(products[pos])){
        return true;
    } else {
        return false;
    }
}

bool isAlcohol(vector<Product*> products, int pos){
    if (Alcohol* a = dynamic_cast<Alcohol*>(products[pos])){
        return true;
    } else {
        return false;
    }
}

bool isLuxury(vector<Product*> products, int pos){
    if (Luxury* a = dynamic_cast<Luxury*>(products[pos])){
        return true;
    } else {
        return false;
    }
}