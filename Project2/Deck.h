// Group 11: Drew Balfour and Sean Vumbaco
// Project 2 (parts a and b)

// Contains class Deck declaration for Flip

#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <string>
#include <list>

#include "Card.h"
#include "Node.h"

using namespace std;

class Deck 
{
    private:
        // member data
        Node<Card> *first;
    public:
        // constructor
        Deck();
        // member functions
        void shuffle();
        friend ostream& operator<< (ostream& out, Deck& deck)
        
};

#endif //DECK_H
