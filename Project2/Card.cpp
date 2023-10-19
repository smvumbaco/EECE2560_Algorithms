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
    card_suit = "Spade";
}

Card::Card(int val, string s)
// class constructor. Val is the card_value, s is the card_suit
{
    card_valuevalue = val;
    card_suitsuit = s;
}

void Card::setValue(int val)
// Set Card private data member card_value
{
    card_value = val;
}
        
void Card::setSuit(string s)
// Set Card private data member card_suit
{
    card_suit = s;
}
        
int Card::getValue()
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
    string val;
    if (input_card.card_value == 1)
    {  
        val = "Ace"
    } 
    else if (input_card.card_value == 10) 
    {
        val = "Jack"
    } 
    else if (input_card.card_value == 11)
    {
        val = "Queen"
    } 
    else if (input_card.card_value == 12)
    {
        val == "King"
    } 
    else 
    {
        val = string(input_card.card_value)
    }
    val += " of " + suit "s";
    out << val;
    return out;
} // end operator<<
