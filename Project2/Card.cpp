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
    card_value = 1;
    card_suit = 0;
}

Card::Card(int val, int s)
// class constructor. Val is the card_value, s is the card_suit
{
    if (val > 0 && val < 13 && s >= 0 && s < 4) 
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
// For our reference:
// 0 = "Ace"
// 10 = "Jack"
// 11 = "Queen"
// 12 = "King"
{
    if (val > 0 && val <= 13)
    {
        card_value = val;
    }
} 
        
void Card::setSuit(int s)
// Set Card private data member card_suit
// For our reference:
// 0 = "Clubs"
// 1 = "Diamonds"
// 2 = "Hearts"
// 3 = "Spades"
{
    if (s < 4 && s >= 0) 
    {
        card_suit = s;
    }
} 
        
int Card::getValue()
// Returns Card private data member card_value as an int
// For our reference:
// 0 = "Ace"
// 10 = "Jack"
// 11 = "Queen"
// 12 = "King"
{
    return card_value;
}
        
int Card::getSuit()
// Returns Card private data member suit as a card_string
// For our reference:
// 0 = "Clubs"
// 1 = "Diamonds"
// 2 = "Hearts"
// 3 = "Spades"
{
    return card_suit;
}
        
ostream& operator<<(ostream& out, Card& input_card)
// Overloads operator << for class Card. Function takes a Card and a stream
// output to the card_value and card_suit
{
    int s, val;
    s = input_card.getSuit();
    val = input_card.getValue();
    string so, vo, text;
    switch (s)
    {
        case 0:
            so =  "Clubs";
            break;
        case 1:
            so = "Diamonds";
            break;
        case 2:
            so = "Hearts";
            break;
        case 3:
            so = "Spades";
            break;
    }
    switch (val) 
    {
        case 1:
            vo = "Ace";
            break;
        case 11:
            vo = "Jack";
            break;
        case 12:
            vo = "Queen";
            break;
        case 13:
            vo = "King";
            break;
        default:
            vo = to_string(val);
    }
    text = vo + " of " + so;
    out << text;
    return out;
} // operator<<
