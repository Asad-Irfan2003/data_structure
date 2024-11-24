#include <iostream>
#include <stdexcept>
using namespace std;
class MinHeap {
private:
    int *heap;
    int capacity;
    int size;

    void heapifyUp(int index) {
        while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < size && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < size && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void resize() {
        int newCapacity = capacity * 2;
        int *newHeap = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newHeap[i] = heap[i];
        }
        delete[] heap;
        heap = newHeap;
        capacity = newCapacity;
    }

public:
    MinHeap(int c = 10) {
        capacity = c;
        size = 0;
        heap = new int[c];
    }

    ~MinHeap() {
        delete[] heap;
    }

    void insert(int value) {
        if (size == capacity) {
            resize();
        }
        heap[size] = value;
        heapifyUp(size);
        size++;
    }

    int extractMin() {
        if (size == 0) {
            throw std::out_of_range("Heap is empty");
        }
        int minValue = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return minValue;
    }

    int peekMin() {
        if (size == 0) {
            throw std::out_of_range("Heap is empty");
        }
        return heap[0];
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    void printHeap() {
        for (int i = 0; i < size; i++) {
            std::cout << heap[i] << " ";
        }
        std::cout << std::endl;
    }
};
