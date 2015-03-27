#include <iostream>
#include <string>
#include "products.h"
#include "scholar.h"
#include "alcohol.h"
#include "luxury.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

//http://stackoverflow.com/questions/26006370/g-does-not-include-files-it-says-it-includes-for-c11
//Para compilar g++ -std=c++11 *.cpp

int menu();
void CreateProduct(vector<Product*>&,vector<string>,double,double,double);
void PrintProducts(vector<Product*>&);
void SentProducts(vector<Product*>&, vector<Product*>&);
void readNames(vector<string>&);
bool isScholar(vector<Product*>, int);
bool isAlcohol(vector<Product*>, int);
bool isLuxury(vector<Product*>, int);
void readScholar(vector<Product*>&);
void readAlcohol(vector<Product*>&);
void readLuxury(vector<Product*>&);
void writeScholar(vector<Product*>);
void writeAlcohol(vector<Product*>);
void writeLuxury(vector<Product*>);

int main(int argc, char* argv[]){
	 cout<<"Welcome!"<<endl;
    vector<Product*> myproducts;
    vector<Product*> mysentproducts;
    vector<string> names;
    readScholar(mysentproducts);
    readAlcohol(mysentproducts);
    readLuxury(mysentproducts);
    readNames(names);
    double ratescholar, ratealcohol, rateluxury;
    cout<<"Please introduce the following:\n Rate for Scholar products: ";
    cin>>ratescholar;
    cout<<"Rate for Alcoholic products: ";
    cin>>ratealcohol;
    cout<<"Rate for Luxury Products: ";
    cin>>rateluxury;
    int option = menu();
    while(option<4){
        if(option==1){
            CreateProduct(myproducts,names,ratescholar,ratealcohol,rateluxury);
        }else if(option==2){
            SentProducts(myproducts,mysentproducts);
        }else if(option==3){
            PrintProducts(mysentproducts);
        }
        option = menu();
    }
    cout<<"Have a good day!"<<endl;
    writeScholar(mysentproducts);
    writeAlcohol(mysentproducts);
    writeLuxury(mysentproducts);
    return 0;
}

int menu(){
	cout<<"Choose what you'd like to do:\n1)Add Product\n2)Send Products\n3)List Products\n4)Exit\n:";
	int option;
	cin>>option;
	return option;
}

void CreateProduct(vector<Product*>& myproducts, vector<string> names, double ratescholar, double ratealcohol, double rateluxury){
	char ans;
	do{
		string client;
		int option;
		double price, volume, weight;
		cout<<"Client: " << endl;
		for (int i = 0; i < names.size(); i++){
			cout << i+1 << ") " << names[i] << endl;
		}
		int c;
		cin >> c;
		client = names[c-1];
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
		}else{
            cout<<"Not created, invalid type"<<endl;
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

void SentProducts(vector<Product*>& myproducts, vector<Product*>& mysentproducts){
    for(unsigned i=0; i<myproducts.size();i++){
        cout<< i + 1 <<") "<< myproducts.at(i)->toString();
    }
    char ans;
    int option;
    do{
        cin>>option;
        mysentproducts.push_back(myproducts.at(option-1));
        cout<<"Do you wish to send another product? Y/N"<<endl;
        cin>>ans;
    }while(ans == 'Y' || ans == 'y');

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

void readScholar(vector<Product*>& products){
    double price;
    double volume;
    double weight;
    string client;
    double rate;
    ifstream file;
    file.open("scholar.txt");
    string line;
    int cont;
    if (file.is_open()) {
        while (!file.eof() && getline(file, line)) {
            cont = 0;
            istringstream iss(line);
            do{
                string s;
                iss >> s;
                cont++;
                if (cont == 1){
                    price = stod(s);
                } else if (cont == 2){
                    volume = stod(s);
                } else if (cont == 3){
                    weight = stod(s);
                } else if (cont == 4){
                    client = s;
                } else if (cont == 5){
                    rate = stod(s);
                }
            } while (iss);
            products.push_back(new Scholar(price, volume, weight, client, rate));
        }
    }
    file.close();
}

void readAlcohol(vector<Product*>& products){
    double price;
    double volume;
    double weight;
    string client;
    double rate;
    ifstream file;
    file.open("alcohol.txt");
    string line;
    int cont;
    if (file.is_open()) {
        while (!file.eof() && getline(file, line)) {
            cont = 0;
            istringstream iss(line);
            do{
                string s;
                iss >> s;
                cont++;
                if (cont == 1){
                    price = stod(s);
                } else if (cont == 2){
                    volume = stod(s);
                } else if (cont == 3){
                    weight = stod(s);
                } else if (cont == 4){
                    client = s;
                } else if (cont == 5){
                    rate = stod(s);
                }
            } while (iss);
            products.push_back(new Alcohol(price, volume, weight, client, rate));
        }
    }
    file.close();
}

void readLuxury(vector<Product*>& products){
    double price;
    double volume;
    double weight;
    string client;
    double rate;
    ifstream file;
    file.open("luxury.txt");
    string line;
    int cont;
    if (file.is_open()) {
        while (!file.eof() && getline(file, line)) {
            cont = 0;
            istringstream iss(line);
            do{
                string s;
                iss >> s;
                cont++;
                if (cont == 1){
                    price = stod(s);
                } else if (cont == 2){
                    volume = stod(s);
                } else if (cont == 3){
                    weight = stod(s);
                } else if (cont == 4){
                    client = s;
                } else if (cont == 5){
                    rate = stod(s);
                }
            } while (iss);
            products.push_back(new Luxury(price, volume, weight, client, rate));
        }
    }
    file.close();
}

void writeScholar(vector<Product*> products){
    ofstream file;
    file.open("scholar.txt");
    if (file.is_open()) {
        for (int i = 0; i < products.size(); i++){
            if (isScholar(products, i)){
                file << dynamic_cast<Scholar*>(products[i])->getPrice();
                file << " ";
                file << dynamic_cast<Scholar*>(products[i])->getVolume();
                file << " ";
                file << dynamic_cast<Scholar*>(products[i])->getWeight();
                file << " ";
                file << dynamic_cast<Scholar*>(products[i])->getClient();
                file << " ";
                file << dynamic_cast<Scholar*>(products[i])->getRate();
                file << "\n";
            }
        }
    } else {
        cout << "No se pueden escribir los datos" << endl;
    }
    file.close();
}

void writeAlcohol(vector<Product*> products){
    ofstream file;
    file.open("alcohol.txt");
    if (file.is_open()) {
        for (int i = 0; i < products.size(); i++){
            if (isAlcohol(products, i)){
                file << dynamic_cast<Alcohol*>(products[i])->getPrice();
                file << " ";
                file << dynamic_cast<Alcohol*>(products[i])->getVolume();
                file << " ";
                file << dynamic_cast<Alcohol*>(products[i])->getWeight();
                file << " ";
                file << dynamic_cast<Alcohol*>(products[i])->getClient();
                file << " ";
                file << dynamic_cast<Alcohol*>(products[i])->getRate();
                file << "\n";
            }
        }
    } else {
        cout << "No se pueden escribir los datos" << endl;
    }
    file.close();
}

void writeLuxury(vector<Product*> products){
    ofstream file;
    file.open("luxury.txt");
    if (file.is_open()) {
        for (int i = 0; i < products.size(); i++){
            if (isLuxury(products, i)){
                file << dynamic_cast<Luxury*>(products[i])->getPrice();
                file << " ";
                file << dynamic_cast<Luxury*>(products[i])->getVolume();
                file << " ";
                file << dynamic_cast<Luxury*>(products[i])->getWeight();
                file << " ";
                file << dynamic_cast<Luxury*>(products[i])->getClient();
                file << " ";
                file << dynamic_cast<Luxury*>(products[i])->getRate();
                file << "\n";
            }
        }
    } else {
        cout << "No se pueden escribir los datos" << endl;
    }
    file.close();
}

void readNames(vector<string>& names){
    ifstream file;
    file.open("names.txt");
    string line;
    int cont;
    if (file.is_open()) {
        while (!file.eof() && getline(file, line)) {
            names.push_back(line);
        }
    }
    file.close();
}