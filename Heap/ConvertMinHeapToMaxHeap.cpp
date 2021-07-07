#include <bits/stdc++.h>
using namespace std;

void maxHeapify(int arr[], int n, int i) {
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	int largest = i;

	if (left < n and arr[left] > arr[largest])
		largest = left;
	if (right < n and arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		swap(arr[i], arr[largest]);
		maxHeapify(arr, n, largest);
	}
}

void convertMaxHeap(int arr[], int n) {
	int idx = n / 2 - 1;
	for (int i = idx; i >= 0; --i)
		maxHeapify(arr, n, i);
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

int main() {
	// array representing Min Heap
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    printf("Min Heap array : ");
    printArray(arr, n);
 
    convertMaxHeap(arr, n);
 
    printf("\nMax Heap array : ");
    printArray(arr, n);

	return 0;
}