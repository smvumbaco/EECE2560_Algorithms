// Group 11: Drew Balfour and Sean Vumbaco
// Project 2 (parts a and b)

// Contains member functions for class Deck. Including:

#include <iostream>
#include <string>
#include <list>
using namespace std;

#include "Deck.h"
#include "Node.h"
#include "Card.h"

Deck::Deck()
// default class Deck constructor. Creates a deck with all cards in order
// (ace-king, club-diamond-heart-spade)
{
    first = new Node<Card> ();
    Node<Card> *curr, *n, *p;
    curr = first;
    int i, j;
    for (i = 0, i < 4, i++)
    {
        for (j = 1, j < 13, j++)
        {
            curr.card.setSuit(i);
            curr.card.setValue(j);
            n = new Node<Card> ();
            curr->next = n;
            p = curr;
            curr = n;
        }
    }
}
