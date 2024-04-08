#include "heap.h"
#include <iostream>
#include <stdexcept>
#include <vector>

Heap::Heap() : heapSize(0) {} // Constructor

void Heap::reheapUp(int index) {
    int parent = (index - 1) / 2; // Calculate parent index
    int temp = heapArray[index]; // Store value at current index temporarily
    while (index > 0 && heapArray[parent] < temp) { // Loop until heap satisfied
        heapArray[index] = heapArray[parent];
        index = parent;
        parent = (parent - 1) / 2; // Recalculate parent index
    }
    heapArray[index] = temp; // Place stored value at correct position
}

void Heap::reheapDown(int index) {
    int leftChild = 2 * index + 1; // Calculate left child index
    int rightChild = 2 * index + 2; // Calculate right child index
    int largest = index; // Assume current node is largest

    // Find largest child
    if (leftChild < heapSize && heapArray[leftChild] > heapArray[largest]) {
        largest = leftChild;
    }
    if (rightChild < heapSize && heapArray[rightChild] > heapArray[largest]) {
        largest = rightChild;
    }

    if (largest != index) { // If largest child is not current node
        std::swap(heapArray[index], heapArray[largest]); // Swap current node with largest child
        reheapDown(largest); // Reheapify down
    }
}

void Heap::insert(int value) {
    heapArray.push_back(value); // Add value to the end
    heapSize++; // Increment heap size
    reheapUp(heapSize - 1); // Reheapify up from inserted node
}

int Heap::remove() {
    if (heapSize == 0) { // If heap is empty
        throw std::out_of_range("Heap is empty"); // Throw exception
    }

    int root = heapArray[0]; // Store root value
    heapArray[0] = heapArray[heapSize - 1]; // Move last element to root
    heapSize--; // Decrement heap size
    heapArray.pop_back(); // Remove last element
    reheapDown(0);
    return root;
}

void Heap::heapSort() {
    for (int i = heapSize / 2 - 1; i >= 0; i--) { // Build max heap
        reheapDown(i);
    }
    for (int i = heapSize - 1; i > 0; i--) { // Extract elements one by one and reheapify down
        std::swap(heapArray[0], heapArray[i]); // Swap the root with last element
        reheapDown(0);
    }
}

void Heap::printHeap() {
    for (int i = 0; i < heapSize; i++) { // Iterate through heap elements
        std::cout << heapArray[i] << " "; // Print each element
    }
    std::cout << std::endl;
}
