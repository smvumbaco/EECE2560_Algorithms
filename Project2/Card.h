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
        int card_suit;
    public:
        // constructors
        Card();
        Card(int val, int s);
        // member functions
        void setValue(int val);
        void setSuit(int suit);
        int getValue();
        int getSuit();
        friend ostream& operator<<(ostream& out, Card& card);
};

#endif //CARD_H