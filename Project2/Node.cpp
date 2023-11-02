// Group 11: Drew Balfour and Sean Vumbaco
// Project 2 (parts a and b)

// Contains member functions for class Node. Includes three different class 
// constructors

#include <iostream>
#include <list>
using namespace std;

#include "Node.h"
// #include "Card.h"

template <class T>
Node<T>::Node()
// Default class constructor: takes in nothing and creates node with empty
// object and no next node
{
    nodeValue = T();
    next = NULL;
}

template <class T>
Node<T>::Node(T obj, Node n)
// class constructor: takes in an object and a node. Sets next to given
// node. Sets given object to nodeValue
{
    nodeValue = obj;
    next = n;
}

template <class T>
Node<T>::Node(T obj)
// class constructor: takes in an object and sets it to nodeValue. Sets
// next to NULL
{
    nodeValue = obj;
    next = NULL;
}