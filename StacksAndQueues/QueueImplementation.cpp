#include <bits/stdc++.h>
using namespace std;

class Queue {
public:
	int front;
	int rear;
	int size;
	int capacity;
	int *array;

	Queue(int capacity) {
		this->capacity = capacity;
		front = size = rear = 0;
		array = new int[capacity];
	}

	bool isEmpty() {
		return size == 0;
	}

	bool isFull() {
		return size == capacity;
	}

	void enqueue(int item) {
		if (isFull())
			return;

		array[rear] = item;
		rear = (rear + 1) % capacity;
		size++;
	}

	int dequeue() {
		if (isEmpty())
			return INT_MIN;

		int res = array[front];
		front = (front + 1) % capacity;
		size--;

		return res;
	}

	void print() {
		cout << "[";

		for (int i = 0; i < size; ++i){
			cout << array[(front + i) % capacity];
			i == size - 1 ? cout << "" : cout << ", ";
		}

		cout << "]" << endl;
	}
};



int main() {
	Queue q(5);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);

	q.print();

	return 0;
}