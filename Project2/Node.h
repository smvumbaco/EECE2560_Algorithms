// Group 11: Drew Balfour and Sean Vumbaco
// Project 2 (parts a and b)

// Contains class Node declaration for linked list

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <list>

// #include "Card.h"

using namespace std;

template <class T>
class Node
{
    public:  
        // constructor
        Node();
        Node(T obj, Node n);
        Node(T obj);
        // member data
        T nodeValue;
        Node<T> *next; 
};

#endif // NODE_H
