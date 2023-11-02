// Group 11: Drew Balfour and Sean Vumbaco
// Project 2 (parts a and b)

// Contains class Deck declaration for Flip

#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <random>
#include <vector>
using namespace std;

#include "Card.h"
#include "Node.h"

class Deck 
{
    private:
        // member data
        Node<Card> *first;
        Node<Card> *back;
    public:
        // constructor/destructor
        Deck();
        ~Deck();
        // member functions
        void shuffle();
        Card deal();
        void replace(Card card);
        friend ostream& operator<< (ostream& out, Deck& deck);
};

#endif //DECK_H
