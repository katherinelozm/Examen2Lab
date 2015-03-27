#include <iostream>
#include <string>
#include "products.h"
#include "scholar.h"
#include "alcohol.h"
#include "luxury.h"
#include <vector>

using namespace std;

int menu();
void CreateProduct(vector<Product*>&);

int main(int argc, char* argv[]){
	int option = menu();
	vector<Product*> myproducts;
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

void CreateProduct(vector<Product*>& myproducts){
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

}