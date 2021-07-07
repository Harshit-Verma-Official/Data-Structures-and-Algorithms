#include <bits/stdc++.h>
using namespace std;

template <class T>
class Deque {
private:
	class Node {
	public:
		T data;
		Node *next;
		Node *prev;
		Node (T data) {
			this->data = data;
			this->next = NULL;
			this->prev = NULL;
		}
	};

	Node *head;
	Node *tail;

public:

	Deque() {
		head = tail = NULL;
	}

	bool isEmpty() {
		return head == NULL;
	}

	int size() {
		if (!isEmpty()) {
			Node *current = head;
			int count = 0;
			while (current) {
				count++;
				current = current->next;
			}
			return count;
		}
		return 0;
	}

	void insertFirst(T data) {
		Node *newNode = new Node(data);

		if (isEmpty())
			head = tail = newNode;
		else {
			head->prev = newNode;
			newNode->next = head;
			head = newNode;
		}
	}

	void insertLast(T data) {
		Node *newNode = new Node(data);

		if (isEmpty())
			head = tail = newNode;
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}

	void removeFirst() {
		if (isEmpty()) {
			cout << "List is Empty\n";
			return;
		}

		if (head == tail) {
			delete head;
			head = tail = NULL;
			return;
		}

		Node *toDel = head;

		head = head->next;
		head->prev = NULL;

		delete toDel;
	}

	void removeLast() {
		if (isEmpty()) {
			cout << "List is Empty\n";
			return;
		}

		if (head == tail) {
			delete head;
			head = tail = NULL;
			return;
		}

		Node *toDel = tail;

		tail = tail->prev;
		tail->next = NULL;

		delete toDel;
	}

	void display() {
		if (isEmpty())
			return;

		Node *current = head;

		while (current) {
			cout << current->data << " ";
			current = current->next;
		}

		cout << endl;
	}
};

template <class T>
class Stack : public Deque <T> {
public:
	void push(T data) {
		this->insertLast(data);
	}

	void pop() {
		this->removeLast();
	}
};

template <class T>
class Queue : public Deque <T> {
public:
	void enqueue(T data) {
		this->insertLast(data);
	}
	void dequeue() {
		this->removeFirst();
	}
};

int main() {
	// object of Stack
    Stack<int> stk;
 
    // push 7 and 8 at top of stack
    stk.push(7);
    stk.push(8);
    cout << "Stack: ";
    stk.display();
 
    // pop an element
    stk.pop();
    cout << "Stack: ";
    stk.display();
 
    // object of Queue
    Queue<int> que;
 
    // insert 12 and 13 in queue
    que.enqueue(12);
    que.enqueue(13);
    cout << "Queue: ";
    que.display();
 
    // delete an element from queue
    que.dequeue();
    cout << "Queue: ";
    que.display();
 
    cout << "Size of Stack is " << stk.size() << endl;
    cout << "Size of Queue is " << que.size() << endl;

	return 0;
}