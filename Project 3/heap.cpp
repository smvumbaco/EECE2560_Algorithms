// Group 11: Drew Balfour and Sean Vumbaco 
// Project 3 (parts a and b)

// Contains member functions for class Heap.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "heap.h"

Heap::Heap()
//default class constructor
{
    vec = {};
}

Heap::Heap(vector<T> v)
{
    vec = v;
}

int Grid::parent(int p)
{
    if(p <= vec.size)
        return floor((p+1)/2) - 1;
}

int Grid::left(int l)
{
    if(p <= vec.size)
        return (2 * l) + 1;
}

int Grid::right(int r)
{
    if(p <= vec.size)
        return (2 * r) + 2
}

int Grid::getItem(int i)
{
    if(p <= vec.size)
        return vec[i];
}

void Grid::initializeMaxHeap()
{
    maxHeapify(vec, 1);
}

void Grid::maxHeapify(vector<T> v, int i)
{
    int largest, l, r;
    l = left(i);
    r = right(r);
    if (l <= v.size && v[l] > v[i])
        largest = l;
    else
        largest = i;

}

void Grid::buildMaxHeap()
{

}

void Grid::heapsort()
{

}