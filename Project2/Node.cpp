// Group 11: Drew Balfour and Sean Vumbaco
// Project 2 (parts a and b)

// Contains member functions for class Node. Including:

#include <iostream>
#include <list>
using namespace std;

#include "Node.h"
#include "Card.h"

template <class T>
Node<T>::Node()
{
    nodeValue = T();
    next = NULL;
}

template <class T>
Node<T>::Node(T obj, Node n)
{
    nodeValue = obj;
    next = n;
}

template <class T>
Node<T>::Node(T obj)
{
    nodeValue = obj;
    next = NULL;
}