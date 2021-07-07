#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
	list<int> dq;
	unordered_map<int, list<int>::iterator> m;
	int csize;

public:

	LRUCache(int size) {
		this->csize = size;
	}

	void refer(int page) {
		if (m.find(page) == m.end()) {
			if (dq.size() == csize) {
				int last = dq.back();
				dq.pop_back();

				m.erase(last);
			}
		} else
			dq.erase(m[page]);

		dq.push_front(page);
		m[page] = dq.begin();
	}

	void display() {
		for (auto itr = dq.begin(); itr != dq.end(); itr++)
			cout << *itr << " ";
		cout << endl;
	}

};

int main() {
	LRUCache ca(4);
  
    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();


	return 0;
}