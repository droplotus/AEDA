#include "carPark.h"
#include "insertionSort.h"
#include "sequentialSearch.h"
#include <algorithm>
#include <vector>
using namespace std;

CarPark::CarPark(unsigned cap, unsigned nMaxCli): capacity(cap), numMaxClients(nMaxCli)
{
    freePlaces=cap;
}

vector<InfoCard> CarPark::getClients() const
{
    return clients;
}

unsigned CarPark::getNumPlaces() const
{
    return capacity;
}

unsigned CarPark::getNumOccupiedPlaces() const
{
    return capacity-freePlaces;
}

unsigned CarPark::getNumMaxClients() const
{
    return numMaxClients;
}

unsigned CarPark::getNumClients() const
{
    return clients.size();
}

// TODO
int CarPark::clientPosition(const string & name) const
{
    for(unsigned int i = 0; i < clients.size(); i++)
        if(clients.at(i).name == name) return i;
    return -1;
}

// TODO
unsigned CarPark::getFrequency(const string &name) const
{
    if(clientPosition(name) == -1) throw ClientDoesNotExist(name);
    return clients.at(clientPosition(name)).frequency;
}

// TODO: to modify
bool CarPark::addClient(const string & name)
{
    if (clients.size() == numMaxClients) return false;
    if (clientPosition(name) != -1) return false;
    InfoCard info;
    info.name=name;
    info.present=false;
    info.frequency=0;
    clients.push_back(info);
    return true;
}

// TODO: to modify
bool CarPark::removeClient(const string & name)
{
    for (vector<InfoCard>::iterator it = clients.begin(); it != clients.end(); it++)
        if ( (*it).name == name ) {
            if ( (*it).present == false ) {
                clients.erase(it);
                return true;
            }
            else return false;
        }
    return false;
}

// TODO: to modify
bool CarPark::enter(const string & name)
{
    if (freePlaces == 0) return false;
    int pos = clientPosition(name);
    if (pos == -1) return false;
    if (clients[pos].present == true) return false;
    clients[pos].present = true;
    clients[pos].frequency+=1;
    freePlaces--;
    return true;
}

// TODO: to modify
bool CarPark::leave(const string & name)
{
    int pos = clientPosition(name);
    if (pos == -1) return false;
    if (clients[pos].present == false) return false;
    clients[pos].present = false;
    freePlaces++;
    return true;
}


// TODO
InfoCard CarPark::getClientAtPos(unsigned p) const
{
    if(p >= clients.size()) throw PositionDoesNotExist(p);
    return clients.at(p);
}

// TODO
void CarPark::sortClientsByFrequency()
{
    // cout << "before" << endl;
    // for(int i=0; i<clients.size(); i++) cout << clients.at(i).name << " - " << clients.at(i).frequency << endl;
    insertionSort(clients);
    // cout << "after" << endl;
    // for(int i=0; i<clients.size(); i++) cout << clients.at(i).name << " - " << clients.at(i).frequency << endl;
}

// TODO
void CarPark::sortClientsByName()
{
    for(int i=0; i<clients.size()-1; i++)
        for(int j=i; j<clients.size(); j++)
            if(clients.at(i).name > clients.at(j).name)
                iter_swap(clients.begin() + i, clients.begin() + j);
}

// TODO
vector<string> CarPark::clientsBetween(unsigned f1, unsigned f2)
{
    vector<string> names;
    sortClientsByFrequency();
    for(int i=0; i<clients.size(); i++)
        if(clients.at(i).frequency >= f1 && clients.at(i).frequency <= f2)
            names.push_back(clients.at(i).name);

    return names;
}


// TODO
ostream & operator<<(ostream & os, const CarPark & cp)
{
    for(auto car : cp.clients){
        os << "Name: " << car.name << " | Frequency: " << car.frequency << " | Present: " << car.present << endl;
    }
    return os;
}

bool InfoCard::operator<(const InfoCard &info) {
    if(this->frequency == info.frequency)
        return this->name < info.name;
    return this->frequency > info.frequency;
}