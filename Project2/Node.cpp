// Group 11: Drew Balfour and Sean Vumbaco
// Project 2 (parts a and b)

// Contains member functions for class Node. Including:

#include <iostream>
#include <list>
using namespace std;

#include "Node.h"
#include "Card.h"

Node::Node()
{
    nodeValue = Card();
    next = this;
    prev = this;
}

Node::Node(Card c)
{
    nodeValue = c;
    next = this;
    prev = this;
}

Node::Node(Card c, Node n, Node p)
{
    nodeValue = c;
    next = n;
    prev = p;
}
