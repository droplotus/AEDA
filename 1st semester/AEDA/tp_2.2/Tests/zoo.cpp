#include "zoo.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
using namespace std;

unsigned Zoo::numAnimals() const {
    return animals.size();
}

unsigned Zoo::numVeterinarians() const {
    return veterinarians.size();
}

void Zoo::addAnimal(Animal *a1) {
    animals.push_back(a1);
}

string Zoo::getInfo() const {
    return "lol";
}

bool Zoo::isYoung(string nameA) {
    for(auto& animal : animals)
        if(animal->getName() == nameA)
            return animal->isYoung();
    return false;
}

void Zoo::allocateVeterinarians(istream &isV) {
    string name;
    string ord;
    int i = 0;
    while(!isV.eof()) {
        getline(isV, name);
        getline(isV, ord);
        Veterinary v = Veterinary(name, stol(ord, nullptr, 10));
        animals.at(i)->setVeterinary(&v);
        i++;
        veterinarians.push_back(&v);
    }
}

bool Zoo::removeVeterinary(string nameV) {
    for(int i=0; i<veterinarians.size(); i++) {
        if (veterinarians.at(i)->getName() == nameV) {
            for(int j=0; j<animals.size(); j++){
                if(animals.at(j)->getVeterinary()->getName() == nameV){
                    if(i==veterinarians.size()-1) return false;
                    animals.at(j)->setVeterinary(veterinarians.at(i+1));
                }
            }
            veterinarians.erase(veterinarians.begin() + i);
        }
        break;
    }
    return true;
}

bool Zoo::operator<(Zoo &zoo2) const {
    int sum1 = 0;
    int sum2 = 0;
    for(int i=0; i<this->animals.size(); i++) sum1+=this->animals.at(i)->getAge();
    for(int j=0; j<this->animals.size(); j++) sum2+=zoo2.animals.at(j)->getAge();
    return sum1<sum2;
}