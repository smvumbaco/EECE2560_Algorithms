// Group 11: Drew Balfour and Sean Vumbaco
// Project 2 (parts a and b)

// Contains class Node declaration for linked list

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <list>

#include "Card.h"

using namespace std;

class Node 
{
    public:
        Node();
        Node(Card c, Node n, Node p);
        Card nodeValue;
        Node<Card> *next;   
        Node<Card> *prev;
}

#endif // NODE_H
