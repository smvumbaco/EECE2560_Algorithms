// Group 11: Drew Balfour and Sean Vumbaco
// Project 2 (parts a and b)

// Contains member functions for class Card. Including:

#include <iostream>
#include <string>
using namespace std;

#include "Card.h"

Card::Card()
// default class Code constructor
{
    card_value = "Ace";
    card_suit = "Club";
}

Card::Card(int val, int s)
// class constructor. Val is the card_value, s is the card_suit
{
    if (val > 0 && val <13 && s >= 0 && s < 4)
    {
        setValue(val);
        setSuit(s);
    } 
    else
    {
        cout << "Invalid Card Info" << endl;
    }
    
}

void Card::setValue(int val)
// Set Card private data member card_value
{
    switch (val) 
    {
        case 1:
            card_value = "Ace";
            break;
        case 10:
            card_value = "Jack";
            break;
        case 11:
            card_value = "Queen";
            break;
        case 12:
            card_value = "King";
            break;
        default:
            if( val > 0 && val < 13)
            {
                card_value = string(input_card.card_value);
            } 
            else 
            {
                cout << "Invalid Card Number" << endl;
                return NULL;
            }
            break;
    }
} // end setValue
        
void Card::setSuit(int s)
// Set Card private data member card_suit
{
    switch (s)
    {
        case 1:
            card_suit =  "Clubs";
            break;
        case 2:
            card_suit = "Diamonds";
            break;
        case 3:
            card_suit = "Hearts";
            break;
        case 4:
            card_suit = "Spades";
            break;
        default:
            cout << "Invalid Suit" << endl;
            return NULL;
    }
} // end setSuit
        
string Card::getValue()
// Returns Card private data member card_value as an int
{
    return card_value;
}
        
string Card::getSuit()
// Returns Card private data member suit as a card_string
{
    return card_suit;
}
        
ostream& operator<<(ostream& out, Card& input_card)
// Overloads operator << for class Card. Function takes a Card and a stream
// output to the card_value and card_suit
{
    string text;
    text = input_card.card_value + " of " + input_card.card_suit;
    out << text;
    return out;
} 
