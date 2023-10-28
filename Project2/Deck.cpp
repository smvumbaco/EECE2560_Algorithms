// Group 11: Drew Balfour and Sean Vumbaco
// Project 2 (parts a and b)

// Contains member functions for class Deck. Including:

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
    first = new Node<Card>(); // Default constructor for Node. NULL value and pointer
    Node<Card> *curr, *next;
    // prev = first;
    curr = new Node<Card>();
    first->next = curr;
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 1; j <= 13; j++)
        {
            curr->nodeValue.setSuit(i);
            curr->nodeValue.setValue(j);
            next = new Node<Card>();
            curr->next = next;
            curr = next;
        }
    }
}

Deck::~Deck() {
    Node<Card> *curr = first->next;
    Node<Card> *next;
    while (curr != NULL) 
    {
        next = curr->next;
        delete curr;
        curr = next;
    }
}

// Generates a random integer between 0 and num (inclusive)
int generateRandomInt(int num) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, num);
    return dis(gen);
}

void Deck::shuffle() 
{
    // Iterate through linked list, add all Cards to vector cards
    vector<Card> cards;
    Node<Card> *curr = first->next;
    while (curr->next != NULL) {
        cards.push_back(curr->nodeValue);
        curr = curr->next;
    }

    // Randomly select indices from cards, assign Card value/suit at that index to location in linked list, remove Card at that index of cards
    curr = first->next;
    int randomIndex;
    while (cards.size() > 0) {
        randomIndex = generateRandomInt(cards.size() - 1); // Generate random integer
        curr->nodeValue.setValue(cards[randomIndex].getValue()); // Set values at curr
        curr->nodeValue.setSuit(cards[randomIndex].getSuit());
        curr = curr->next; // Iterate curr to next
        cards.erase(cards.begin() + randomIndex); // Delete value from cards
    }
}

Card Deck::deal() {
    // Returns the top card in the deck
    // Removes the card from the deck
}

void Deck::replace(Card card) {
    // card is placed on the bottom of the deck
}

// 0 = "Clubs"
// 1 = "Diamonds"
// 2 = "Hearts"
// 3 = "Spades"
ostream& operator<< (ostream& out, Deck& deck)
{
    Node<Card> *curr = (deck.first)->next;
    while (curr->next != NULL) 
    {
        out << curr->nodeValue << endl;
        curr = curr->next;
    }
    return out;
}