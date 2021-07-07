// Array Deque Implementation


#include <bits/stdc++.h>
using namespace std;

template<class T>
class Deque {
private:
	T *array;
	int front;
	int rear;
	int size;

public:

	Deque(int size) {
		this->size = size;
		array = new T[size];
		front = -1;
		rear = 0;
	}

	bool isFull() {
		return (front == 0 and rear == size - 1) or (front == rear + 1);
	}

	bool isEmpty() {
		return front == -1;
	}

	void insertFront(T key) {
		if (isFull()){
			cout << "Overflow\n";
			return;
		}

		if (front == -1)
			front = rear = 0;
		else if (front == 0)
			front = size - 1;
		else
			front--;

		array[front] = key;
	}

	void insertRear(T key) {
		if (isFull()) {
			cout << "Overflow\n";
			return;
		}

		if (front == -1)
			front = rear = 0;
		else if (rear == size - 1)
			rear = 0;
		else 
			rear++;

		array[rear] = key;
	}

	void deleteFront() {
		if (isEmpty()) {
			cout << "Queue Underflow\n";
			return;
		}

		if (front == rear)
			front = rear = -1;
		else
			if (front == size - 1)
				front = 0;
			else 
				front++;
	}

	void deleteRear() {
		if (isEmpty()) {
			cout << "Queue Underflow\n";
			return;
		}

		if (front == rear)
			front = rear = -1;
		else
			if (rear == 0)
				rear = size - 1;
			else
				rear--;
	}

	T getFront() {
		if (isEmpty()) {
			cout << "Underflow\n";
			return -1;
		}

		return array[front];
	}

	T getRear() {
		if (isEmpty()) {
			cout << "Underflow\n";
			return -1;
		}

		return array[rear];
	}
};

int main() {
	Deque<int> dq(5);

    cout << "Insert element at rear end  : 5 \n";
    dq.insertRear(5);
 
    cout << "insert element at rear end : 10 \n";
    dq.insertRear(10);
 
    cout << "get rear element " << " "
         << dq.getRear() << endl;
 
    dq.deleteRear();
    cout << "After delete rear element new rear"
         << " become " << dq.getRear() << endl;
 
    cout << "inserting element at front end \n";
    dq.insertFront(15);
 
    cout << "get front element " << " "
         << dq.getFront() << endl;
 
    dq.deleteFront();
 
    cout << "After delete front element new "
       << "front become " << dq.getFront() << endl;

	return 0;
}