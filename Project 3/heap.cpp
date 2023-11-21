// Group 11: Drew Balfour and Sean Vumbaco 
// Project 3 (parts a and b)

// Contains member functions for class Heap.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "heap.h"

template <class T>
Heap<T>::Heap()
//default class constructor
{
    vec = {};
    heapsize = 0;
}

template <class T>
Heap<T>::Heap(vector<T> v)
{
    vec = v;
    heapsize = vec.size();
}

template <class T>
int Heap<T>::parent(int p)
{
    if(p <= vec.size())
        // return floor((p+1)/2) - 1;
        return (p+1) / 2 - 1; // Take advantage of integer division here
}

template <class T>
int Heap<T>::left(int l)
{
    int i = (2 * l) + 1;
    if(i + 1 <= vec.size())
        return i;
    else
        return l;
}

template <class T>
int Heap<T>::right(int r)
{
    int i = (2 * r) + 2;
    if(i + 1 <= vec.size())
        return i;
    else
        return r;
}

template <class T>
T Heap<T>::getItem(int i)
{
    if(i + 1 <= vec.size())
        return vec[i];
}

template <class T>
void Heap<T>::initializeMaxHeap()
{
    // cout << "Start initaxheap\n";
    heapsize = vec.size();
    buildMaxHeap();
}

template <class T>
void Heap<T>::maxHeapify(int i)
{
    // cout << "Start maxheap\n";
    int largest, l, r;
    T hold;
    l = left(i);
    r = right(i);
    // cout << "right - " << vec[r] << ", left - " << vec[l] << ", i - " << vec[i] << endl;
    // if ((l + 1) <= v.size && v[l] > v[i])
    if ((l + 1) <= heapsize && vec[l] > vec[i])
        largest = l;
    else
        largest = i;
    // if ((r + 1) <= v.size && v[r] > v[largest])
    if ((r + 1) <= heapsize && vec[r] > vec[largest])
        largest = r;
    if (largest != i)
    {
        // hold = v[i]
        // v[i] = v[largest];
        // v[largest] = hold;
        hold = vec[i];
        vec[i] = vec[largest];
        vec[largest] = hold;
        maxHeapify(largest);
    }
}

template <class T>
void Heap<T>::buildMaxHeap()
{
    // for (int i = (floor(heapsize / 2)) - 1, i == 0, i--)
    // cout << "Start build maxheap\n";
    // cout << "heapsize = " << heapsize << endl;
    for (int i = ((heapsize / 2) - 1); i >= 0; i--) // Take advantage of integer division
    {
        // cout << i << endl;
        maxHeapify(i);
        // cout << "right - " << vec[right(i)] << ", left - " << vec[left(i)] << ", i - " << vec[i] << endl;

    }
}

template <class T>
void Heap<T>::heapsort()
{
    T hold;
    // cout << "Start heapsort\n";
    initializeMaxHeap();
    for (int i = vec.size() - 1; i >= 1; i--)
    {
        // hold = v[i];
        // v[i] = v[1];
        // v[1] = hold;
        hold = vec[i];
        vec[i] = vec[0];
        vec[0] = hold;
        // cout << i << ": " << vec[0] << ", " << vec[i] << endl;
        heapsize--;
        maxHeapify(0);
    }
}

template <class T>
vector<T> Heap<T>::getVec()
{
    return vec;
}