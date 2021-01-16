#include "fleet.h"
#include <string>
#include <iostream>

using namespace std;

vector<Vehicle *> Fleet::getVehicles() const {
    return vehicles;
}

int Fleet::numVehicles() const {
    return vehicles.size();
}

int Fleet::lowestYear() const {
    if(vehicles.size() == 0) return 0;
    int lowest = vehicles.at(0)->getYear();

    for(int i=0; i<vehicles.size(); i++)
        if(lowest > vehicles.at(i)->getYear()) lowest = vehicles.at(i)->getYear();

    return lowest;
}

void Fleet::addVehicle(Vehicle *v1) {
    vehicles.push_back(v1);
}

ostream &operator<<(ostream &o, const Fleet &f){
    for(int i=0; i<f.vehicles.size(); i++)
        f.vehicles.at(i)->info(o);
    return o;
}

vector<Vehicle *> Fleet::operator()(int yearM) const {
    vector<Vehicle *> sameYearVehicles;

    for(auto &vehicle : vehicles)
        if(vehicle->getYear() == yearM) sameYearVehicles.push_back(vehicle);

    return sameYearVehicles;
}

float Fleet::totalTax() const {
    float sum = 0;
    for(auto& vehicle : vehicles)
        sum += vehicle->calculateTax();
    return sum;
}

unsigned Fleet::removeOldVehicles(int y1) {
    int x = 0;
    for(int i=vehicles.size()-1; i>=0; i--)
        if(vehicles.at(i)->getYear()<=y1){
            vehicles.erase(vehicles.begin() + i);
            x++;
        }
    return x;
}