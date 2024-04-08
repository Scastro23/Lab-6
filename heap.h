#ifndef HEAP_H
#define HEAP_H

#include <vector>

class Heap {
private:
    std::vector<int> heapArray; // Vector store heap elements
    int heapSize; // Size of heap

    void reheapUp(int index); // Moves an element up to maintain heap
    void reheapDown(int index); // Moves an element down to maintain heap

public:
    // Constructor
    Heap();

    void insert(int value); // Insert a new value into heap
    int remove(); // Remove and return the root value
    void heapSort(); // Perform heap sort on heap
    void printHeap(); // Print elements of heap

};

#endif


