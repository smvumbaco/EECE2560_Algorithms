// Group 11: Drew Balfour and Sean Vumbaco
// Project 2 (parts a and b)

// Contains class Card declaration for Flip

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
using namespace std;

class Card 
{
    private:
        // member data
        int card_value;
        string card_suit;
    public:
        // constructor
        Card();
        Card(int val, suit s);
        // member functions
        void setValue(int val);
        void setSuit(string suit);
        int getValue();
        string getSuit();
        friend ostream& operator<<(ostream& out, Card& card);
};

#endif //CARD_H