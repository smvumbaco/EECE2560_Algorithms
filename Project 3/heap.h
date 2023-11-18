// Group 11: Drew Balfour and Sean Vumbaco 
// Project 3 (parts a and b)


// Contains class Heap declaration

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

template <class T>
class Heap {
    private:
    // member data
    vector<T> vec;
    public:
    // constructors
    Heap();
    Heap(vector<T> v);
    // member functions
    T parent(int p);
    T left(int l);
    T right(int r);
    T getItem(int i);
    void initializeMaxHeap();
    void maxHeapify();
    void buildMaxHeap();
    void heapsort();
};

#endif // HEAP_H