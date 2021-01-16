#include "animal.h"
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

int Animal::youngest = -1;

string Animal::getName() const {
	return name;
}

int Animal::getAge() const {
    return age;
}

int Animal::getYoungest() {
    return youngest;
}

void Animal::setVeterinary(Veterinary *vet) {
    this->vet = vet;
}

Veterinary *Animal::getVeterinary() const {
    return vet;
}

Animal::Animal(string name, int age) {
    if(youngest < 0) youngest = age;
    else if(youngest > age) youngest = age;
    this->name = name;
    this->age = age;
}

string Dog::getInfo() const {
    string s = "";
    s += this->name + ", " + to_string(this->age) + vet->getInfo() + ", " + this->breed;
    cout << this->name << endl;
    return s;
}

Dog::Dog(string name, int age, string breed) : Animal(name, age){
    this->breed = breed;
}

Flying::Flying(int maxv, int maxa) {
    maxVelocity = maxv;
    maxAltitude = maxa;
}

Bat::Bat(string name, int age, int maxv, int maxa) : Animal(name, age), Flying(maxv, maxa){}

string Bat::getInfo() const {
    string s = "";
    s += name + ", " + to_string(age) + ", " + to_string(maxVelocity) + ", " + to_string(maxAltitude);
    return s;
}

bool Dog::isYoung() const{
    return age<5;
}

bool Bat::isYoung() const{
    return age<4;
}

