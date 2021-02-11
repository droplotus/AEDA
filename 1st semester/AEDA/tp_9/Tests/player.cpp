#include "player.h"


void Player::addBet(const Bet& b)
{
    bets.insert(b);
}

unsigned Player::betsInNumber(unsigned num) const
{
    unsigned int count = 0;
    unordered_set<Bet, betHash, betHash>::const_iterator it;
    for(it = bets.begin(); it != bets.end(); it++){
        if((*it).contains(num)) count++;
    }
	return count;
}

tabHBet Player::drawnBets(const tabHInt& draw) const
{
	tabHBet res;
    unordered_set<Bet, betHash, betHash>::const_iterator it;
    for(it = bets.begin(); it != bets.end(); it++){
        if((*it).countRights(draw) > 3) res.insert((*it));
    }
	return res;
}
