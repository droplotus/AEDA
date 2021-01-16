#include "game.h"
#include <sstream>


//TODO
ostream &operator << (ostream &os, Circle &c1)
{
    string stateStr;
    (c1.getState()) ? stateStr = "true" : stateStr = "false";
    os << c1.points << "-" << stateStr  << "-" << c1.nVisits << endl;
	return os;
}

BinaryTree<Circle> Game::initiateGame(int pos, int level, vector<int> &points, vector<bool> &states)
{
    Circle c1(points[pos],states[pos]);
    if (level==0) return BinaryTree<Circle>(c1);
    BinaryTree<Circle> leftChild = initiateGame(2 * pos + 1, level - 1, points, states);
    BinaryTree<Circle> rightChild = initiateGame(2 * pos + 2, level - 1, points, states);
    return BinaryTree<Circle>(c1, leftChild, rightChild);
}

Game::Game(int h, vector<int> &points, vector<bool> &states)
{
    game = initiateGame(0, h, points, states);
}


string Game::writeGame()
{
    BTItrLevel<Circle> it(game);
    stringstream str("");

    while(!it.isAtEnd()){
        str<<it.retrieve();
        it.advance();
    }

	return str.str();
}


int Game::move()
{
    BTItrLevel<Circle> it(game);
    int pos = 1; int nPoints = -1;
    if(it.isAtEnd()) return nPoints;
    while(true){
        int n;
        (it.retrieve().getState()) ? n = pos+1 : n = pos;
        it.retrieve().changeState();
        it.retrieve().incNVisits();
        nPoints = it.retrieve().getPoints();
        int i = 0;
        while(i < n && !it.isAtEnd()){
            i++;
            it.advance();
        }
        if(!it.isAtEnd()) pos += n;
        else break;
    }
    return nPoints;
}


int Game::mostVisited()
{
    BTItrLevel<Circle> it(game);
    int n = 0;
    it.advance();
    while(!it.isAtEnd()){
        if(it.retrieve().getNVisits() > n) n = it.retrieve().getNVisits();
        it.advance();
    }

	return n;
}
