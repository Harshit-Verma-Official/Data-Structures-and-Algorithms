#include <bits/stdc++.h>
using namespace std;

int parent(int i) {
	return (i - 1) / 2;
}

int leftChild(int i) {
	return i * 2 + 1;
}

int rightChild(int i) {
	return i * 2 + 2;
}

void maxHeapify(int arr[], int n, int i) {
	int left = leftChild(i);
	int right = rightChild(i);
	int largest = i;

	if (left < n and arr[left] > arr[i])
		largest = left;
	if (right < n and arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		swap(arr[i], arr[largest]);
		maxHeapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; --i)
		maxHeapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		maxHeapify(arr, i, 0);
	}
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

int main() {
	int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    heapSort(arr, n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);

	return 0;
}