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
void PrintProducts(vector<Product*>&);
bool isScholar(vector<Product*>, int);
bool isAlcohol(vector<Product*>, int);
bool isLuxury(vector<Product*>, int);

int main(int argc, char* argv[]){
	cout<<"Welcome!"<<endl;
	vector<Product*> myproducts;
	double ratescholar, ratealcohol, rateluxury;
	cout<<"Welcome!\nPlease introduce the following:\n Rate for Scholar products: ";
	cin>>ratescholar;
	cout<<"Rate for Alcoholic products: ";
	cin>>ratealcohol;
	cout<<"Rate for Luxury Products: ";
	cin>>rateluxury;
	int option = menu();
	while(option<3){
		if(option==1){
			CreateProduct(myproducts,ratescholar,ratealcohol,rateluxury);
		}else if(option==2){
			PrintProducts(myproducts);
		}
		option = menu();
	}
	cout<<"Have a good day!"<<endl;

	return 0;
}

int menu(){
	cout<<"Choose what you'd like to do:\n1)Add Product\n2)List Products\n3)Exit\n:";
	int option;
	cin>>option;
	return option;
}

void CreateProduct(vector<Product*>& myproducts, double ratescholar, double ratealcohol, double rateluxury){
	char ans;
	do{
		string client;
		int option;
		double price, volume, weight;
		cout<<"Client: ";
		cin>>client;
		cout<<"Price: ";
		cin>>price;
		cout<<"Volume: ";
		cin>>volume;
		cout<<"Weight: ";
		cin>>weight;
		cout<<"1) Scholar | 2) Alcoholic | 3) Luxury"<<endl;
		cin>>option;
		if(option==1){
			myproducts.push_back(new Scholar(price,volume,weight,client,ratescholar));
		}else if(option==2){
			myproducts.push_back(new Alcohol(price,volume,weight,client,ratealcohol));
		}else if(option==3){
			myproducts.push_back(new Luxury(price,volume,weight,client,rateluxury));
		}
		cout<<"Create another product? Y/N "<<endl;
		cin>>ans;
	}while(ans=='Y' || ans=='y');
}

void PrintProducts(vector<Product*>& myproducts){

	for(unsigned i=0; i<myproducts.size();i++ ){
		cout<<myproducts.at(i)->toString()<<endl;
		if(isScholar(myproducts,i)){
			cout<< "Type: Scholar"<<endl;
		}else if(isAlcohol(myproducts,i)){
			cout<< "Type: Alcoholic"<<endl;
		}else if(isLuxury(myproducts,i)){
			cout<<" Type: Luxury"<<endl;
		}
		cout<< "Tax: " << myproducts.at(i)->getTax() << endl;
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