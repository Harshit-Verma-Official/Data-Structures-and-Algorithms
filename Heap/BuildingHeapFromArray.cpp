#include <bits/stdc++.h>
using namespace std;

int parent(int index) {
	return (index - 1) / 2;
}

int leftChild(int index) {
	return index * 2 + 1;
}

int rightChild(int index) {
	return index * 2 + 2;
}

void maxHeapify(int arr[], int n, int i) {
	int left = leftChild(i);
	int right = rightChild(i);
	int largest = i;

	if (left < n and arr[largest] < arr[left])
		largest = left;
	if (right < n and arr[largest] < arr[right])
		largest = right;

	if (largest != i) {
		swap(arr[i], arr[largest]);
		maxHeapify(arr, n, largest);
	}
}

void buildHeap(int arr[], int n) {
	int startIdx = n / 2 - 1;

	for (int i = startIdx; i >= 0; --i)
		maxHeapify(arr, n, i);
}

void printHeap(int arr[], int n) {
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

int main() {
	// Binary Tree Representation
    // of input array
    // 1
    //           /     \
    // 3         5
    //      /    \     /  \
    // 4      6   13  10
    //    / \    / \
    // 9   8  15 17
    int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
  
    int n = sizeof(arr) / sizeof(arr[0]);
  
    buildHeap(arr, n);
  
    printHeap(arr, n);
    // Final Heap:
    // 17
    //           /      \
    // 15         13
    //       /    \      /  \
    // 9      6    5   10
    //     / \    /  \
    // 4   8  3    1

	return 0;
}