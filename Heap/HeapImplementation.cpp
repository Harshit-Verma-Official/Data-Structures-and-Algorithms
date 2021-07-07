#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    int *harr;
    int capacity;
    int heap_size;

public:

    MinHeap(int cap) {
        this->capacity = cap;
        this->heap_size = 0;
        this->harr = new int[cap];
    }

    void minHeapify(int i) {
        int left = leftChild(i);
        int right = rightChild(i);
        int smallest = i;

        if (left < heap_size and harr[left] < harr[i])
            smallest = left;
        if (right < heap_size and harr[right] < harr[smallest])
            smallest = right;

        if (smallest != i) {
            swap(harr[i], harr[smallest]);
            minHeapify(smallest);
        }
    }

    int parent(int index) {
        return (index - 1) / 2;
    }

    int leftChild(int index) {
        return 2 * index + 1;
    }

    int rightChild(int index) {
        return 2 * index + 2;
    }

    int extractMin() {
        if (heap_size <= 0)
            return INT_MAX;
        if (heap_size == 1) {
            heap_size--;
            return harr[0];
        }

        int root = harr[0];
        harr[0] = harr[--heap_size];

        minHeapify(0);

        return root;
    }

    void decreaseKey(int i, int newKey) {
        harr[i] = newKey;
        while (i > 0 and harr[parent(i)] > harr[i]) {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    int getMin() {
        if (heap_size == 0)
            return -1;
        return harr[0];
    }

    void deleteKey(int index) {
        decreaseKey(index, INT_MIN);
        extractMin();
    }

    void insertKey(int key) {
        if (heap_size == capacity) {
            cout << "Heap Overflow\n";
            return;
        }

        harr[heap_size++] = key;

        int i = heap_size - 1;

        while (i > 0 and harr[parent(i)] > harr[i]) {
            swap(harr[parent(i)], harr[i]);
            i = parent(i);
        }
    }

};

int main() {
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();

    return 0;
}