#include "bet.h"
#include <iostream>
#include <sstream>
using namespace std;


bool Bet::contains(unsigned num) const
{
    tabHInt::const_iterator it = numbers.find(num);
    if(it == numbers.end()) return false;
	return true;
}

void Bet::generateBet(const vector<unsigned>& values, unsigned n)
{
    numbers.clear();
    int nVals = 0, i = 0;
    while(nVals < n){
        pair<tabHInt::iterator, bool> res = numbers.insert(values[i]);
        if(res.second == true)
            nVals++;
        i++;
    }
}

unsigned Bet::countRights(const tabHInt& draw) const
{
    unsigned int count = 0;
    tabHInt::const_iterator it = draw.begin();
    while(it != draw.end()){
        if(contains(*it)) count++;
        it++;
    }

	return count;
}

unsigned int Bet::size() const
{
    return numbers.size();
}