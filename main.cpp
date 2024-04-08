// Samuel Castro
// Lab 6
// SP2024
/* Description: Implement a heap that can perform heap sort and reheap operations.*/

#include "heap.h"
#include <iostream>

int main() {
    Heap heap; // Create instance of Heap class

    // Insert elements into heap
    heap.insert(10);
    heap.insert(7);
    heap.insert(15);
    heap.insert(3);
    heap.insert(8);

    // Print heap before sorting
    std::cout << "Heap before sorting: ";
    heap.printHeap();

    // Perform heap sort operation
    heap.heapSort();

    // Print heap after sorting
    std::cout << "Heap after sorting: ";
    heap.printHeap();

    return 0;
}
