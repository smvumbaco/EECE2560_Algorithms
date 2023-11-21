// Group 11: Drew Balfour and Sean Vumbaco 
// Project 3 (parts a and b)

// Contains member functions for class Heap. Including: constructors, parent,
// left, right, getItem, initializeMaxHeap, maxHeapify, buildMaxHeap, heapsort,
// and getVec

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "heap.h"

template <class T>
Heap<T>::Heap()
// default class constructor: takes in nothing and creates heap with an empty
// vector and a heapsize of 0
{
    vec = {};
    heapsize = 0;
}

template <class T>
Heap<T>::Heap(vector<T> v)
// class constructor: takes in a vector. Sets vec to v and sets heapsize to
// size of vec
{
    vec = v;
    heapsize = vec.size();
}

template <class T>
int Heap<T>::parent(int p)
// return index of the parent node to the given node. If given node p is the
// first node in the vertex, parent will return self.
{
    if(p == 0)
        return 0;
    if(p <= vec.size())
        return (p + 1) / 2 - 1;
}

template <class T>
int Heap<T>::left(int l)
// return index of given node's left child node. If given node does not have
// a left child, return self
{
    int i = (2 * l) + 1;
    if(i + 1 <= vec.size())
        return i;
    else
        return l;
}

template <class T>
int Heap<T>::right(int r)
// return index of given node's right child node. If given node does not have
// a right child, return self
{
    int i = (2 * r) + 2;
    if(i + 1 <= vec.size())
        return i;
    else
        return r;
}

template <class T>
T Heap<T>::getItem(int i)
// return value at given index
{
    if(i + 1 <= vec.size())
        return vec[i];
}

template <class T>
void Heap<T>::initializeMaxHeap()
// initialize a max heap by setting heapsize to the size of vec and
// calling buildMaxHeap()
{
    heapsize = vec.size();
    buildMaxHeap();
}

template <class T>
void Heap<T>::maxHeapify(int i)
// Given a single index i, determine if i, the right child of i, or the left
// child of i is greatest. If i is greatest, do nothing. If either child is
// larger, switch i and the larger child then run maxHeapify on the index
// that was switched.
{
    int largest, l, r;
    T hold;
    l = left(i);
    r = right(i);
    if ((l + 1) <= heapsize && vec[l] > vec[i])
        largest = l;
    else
        largest = i;
    if ((r + 1) <= heapsize && vec[r] > vec[largest])
        largest = r;
    if (largest != i)
    {
        hold = vec[i];
        vec[i] = vec[largest];
        vec[largest] = hold;
        maxHeapify(largest);
    }
} // end maxHeapify

template <class T>
void Heap<T>::buildMaxHeap()
// run maxHeapify for every node that is a parent of at least one node
{
    for (int i = ((heapsize / 2) - 1); i >= 0; i--)
    {
        maxHeapify(i);
    }
}

template <class T>
void Heap<T>::heapsort()
// organize vec in descending order using maxHeapify
{
    T hold;
    initializeMaxHeap();
    for (int i = vec.size() - 1; i >= 1; i--)
    {
        hold = vec[i];
        vec[i] = vec[0];
        vec[0] = hold;
        heapsize--;
        maxHeapify(0);
    }
}

template <class T>
vector<T> Heap<T>::getVec()
// Return Heap private data member vec as a vector<T>
{
    return vec;
}