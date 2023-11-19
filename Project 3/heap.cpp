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
    heapsize = 0;
}

Heap::Heap(vector<T> v)
{
    vec = v;
    heapsize = vec.size;
}

int Heap::parent(int p)
{
    if(p <= vec.size)
        return floor((p+1)/2) - 1;
}

int Heap::left(int l)
{
    i = (2 * l) + 1;
    if(i + 1 <= vec.size)
        return i;
    else
        return l;
}

int Heap::right(int r)
{
    i = (2 * r) + 2;
    if(i + 1 <= vec.size)
        return i;
    else
        return r;
}

T Heap::getItem(int i)
{
    if(i + 1 <= vec.size)
        return vec[i];
}

void Heap::initializeMaxHeap()
{
    heapsize = vec.size;
    buildMaxHeap();
}

void Heap::maxHeapify(int i)
{
    int largest, l, r;
    T hold;
    l = left(i);
    r = right(i);
    if ((l + 1) <= v.size && v[l] > v[i])
        largest = l;
    else
        largest = i;
    if ((r + 1) <= v.size && v[r] > v[largest])
        largest = r;
    if (largest != i)
    {
        hold = v[i]
        v[i] = v[largest];
        v[largest] = hold;
        maxHeapify(largest);
    }
}

void Heap::buildMaxHeap()
{
    for (int i = (floor(heapsize / 2)) - 1, i == 0, i--)
        maxHeapify(i);
}

void Heap::heapsort()
{
    T hold;
    initializeMaxHeap();
    for (int i = vec.size - 1, i == 1, i--)
    {
        hold = v[i];
        v[i] = v[1];
        v[1] = hold;
        heapsize--;
        maxHeapify(1);
    }
}