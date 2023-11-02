// Group 11: Drew Balfour and Sean Vumbaco
// Project 2 (parts a and b)

// Contains member function implementations for class Deck. Including:
// constructor, destructor, shuffle, deal, replace, and operator<< overload

#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <random>
#include <vector>
using namespace std;

#include "Deck.h"
#include "Node.h"
#include "Node.cpp"
#include "Card.h"
#include "Card.cpp"

Deck::Deck()
// default class Deck constructor. Creates a deck with all cards in order
// (ace-king, club-diamond-heart-spade)
{
    first = new Node<Card>(); // Default constructor for Node: Ace of Clubs, NULL pointer
    Node<Card> *curr, *next;
    curr = first;
    first->next = next;
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 1; j <= 13; j++)
        {
            curr->nodeValue.setSuit(i);
            curr->nodeValue.setValue(j);
            next = new Node<Card>();
            back = curr;
            curr->next = next;
            curr = next;
        }
    }
    delete curr;
}

Deck::~Deck() 
// destructor for class Deck. Deallocates all memory reserved for Node<Card> objects
// Assumes that deck is not empty
{
    Node<Card> *curr = first;
    Node<Card> *next;
    while (curr != NULL) 
    {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

int generateRandomInt(int num) 
// Helper function: returns a random integer between 0 and num (inclusive)
// Assumes num > 0
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, num);
    return dis(gen);
}

void Deck::shuffle() 
// Randomizes order of nodeValues in the deck linked list
// Assumes deck is not empty
{
    // Iterate through linked list, add all Cards to vector cards
    vector<Card> cards;
    Node<Card> *curr = first;
    while (curr->next != NULL) 
    {
        cards.push_back(curr->nodeValue);
        curr = curr->next;
    }

    // Randomly select indices from cards, assign Card value/suit at that index to location in linked list, remove Card at that index of cards
    // curr = first->next;
    curr = first;
    int randomIndex;
    while (cards.size() > 0) 
    {
        randomIndex = generateRandomInt(cards.size() - 1); // Generate random integer
        curr->nodeValue.setValue(cards[randomIndex].getValue()); // Set values at curr
        curr->nodeValue.setSuit(cards[randomIndex].getSuit());
        curr = curr->next; // Iterate curr to next
        cards.erase(cards.begin() + randomIndex); // Delete value from cards
    }
}

Card Deck::deal() 
// Returns the top card in the deck & removes it from the deck
// Returns a Card object (nodeValue of Node<Card> object)
// Assumes deck is not empty
{ 
    Card c = first->nodeValue;
    first = first->next;
    return c;
}

void Deck::replace(Card card) 
// Places passed card on bottom of deck (last in line for deal() function)
{
    // back = back->next;
    back->next = new Node<Card>(card);
    back = back->next;
}

ostream& operator<< (ostream& out, Deck& deck)
// Overload operator << for cout using overload operator << for Card class
// Prints all nodeValue (Card) values in the Node<Card> linked list that makes up deck
// Assumes deck is not empty
{
    Node<Card> *curr = deck.first;
    while (curr->next != NULL) 
    {
        out << curr->nodeValue << endl;
        curr = curr->next;
    }
    return out;
}