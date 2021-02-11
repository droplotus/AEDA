#include "vehicle.h"
#include <iostream>

using namespace std;

Vehicle::Vehicle(string b, int m, int y) {
    brand = b;
    month = m;
    year = y;
}

bool Vehicle::operator<(const Vehicle &v) const {
    if(this->year<v.getYear()) return true;
    if(this->year==v.getYear())
        if(this->month<v.month)
            return true;
    return false;
}

string Vehicle::getBrand() const {
    return brand;
}

int Vehicle::getYear() const {
    return year;
}

int Vehicle::info() const {
    return 3;
}

string MotorVehicle::getFuel() const {
    return fuel;
}

int MotorVehicle::getCylinder() const {
    return cylinder;
}

int MotorVehicle::info() const {
    return 5;
}

int MotorVehicle::info(ostream &o) const {
    return 5;
}

MotorVehicle::MotorVehicle(string b, int m, int y, string f, int cyl) : Vehicle(b, m, y) {
    fuel = f;
    cylinder = cyl;
}

float MotorVehicle::calculateTax() const {
    if(fuel == "gas"){
        if (getCylinder()<=1000)
            return (getYear() > 1995) ? 14.56 : 8.10;
        else if(getCylinder()<=1300)
            return (getYear() > 1995) ? 29.06 : 14.56;
        else if(getCylinder()<=1750)
            return (getYear() > 1995) ? 45.15 : 22.65;
        else if(getCylinder()<=2600)
            return (getYear() > 1995) ? 113.98 : 54.89;
        else if(getCylinder()<=3500)
            return (getYear() > 1995) ? 181.17 : 87.13;
        else return (getYear() > 1995) ? 320.89 : 148.37;
    }else {
        if (getCylinder()<=1500)
            return (getYear() > 1995) ? 14.56 : 8.10;
        else if(getCylinder()<=2000)
            return (getYear() > 1995) ? 29.06 : 14.56;
        else if(getCylinder()<=3000)
            return (getYear() > 1995) ? 45.15 : 22.65;
        else return (getYear() > 1995) ? 113.98 : 54.89;
    }
}

Car::Car(string b, int m, int y, string f, int cyl) : MotorVehicle(b, m, y, f, cyl){}

int Car::info() const {
    return 5;
}

int Car::info(ostream &o) const {
    return 5;
}

Truck::Truck(string b, int m, int y, string f, int cyl, int ml) : MotorVehicle(b, m, y, f, cyl) {
    maximumLoad = ml;
}

int Truck::info() const {
    return 6;
}

int Truck::info(ostream &o) const {
    return 6;
}

Bicycle::Bicycle(string b, int m, int y, string t) : Vehicle(b, m, y){
    type = t;
}

float Bicycle::calculateTax() const {
    return 0;
}

int Bicycle::info() const {
    return 4;
}

int Bicycle::info(ostream &o) const {
    return 4;
}
