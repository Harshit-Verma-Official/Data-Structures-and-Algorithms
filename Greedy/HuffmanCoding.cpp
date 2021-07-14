#include <bits/stdc++.h>
using namespace std;

struct Node {
	char data;
	unsigned freq;

	Node *left;
	Node *right;

	Node(char data, unsigned freq) {
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

struct comp {
	bool operator()(Node *left, Node *right) {
		return left->freq > right->freq;
	}
};

void printCodes(Node *root, string str) {
	if (!root)
		return;

	if (root->data != '$')
		cout << root->data << " : " << str << endl;

	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size) {
	priority_queue<Node*, vector<Node*>, comp> pq;

	for (int i = 0; i < size; ++i)
		pq.push(new Node(data[i], freq[i]));

	while (pq.size() != 1) {
		Node *left = pq.top();
		pq.pop();

		Node *right = pq.top();
		pq.pop();

		Node *top = new Node('$', left->freq + right->freq);

		top->left = left;
		top->right = right;

		pq.push(top);
	}

	printCodes(pq.top(), "");
}

int main() {
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
 
    int size = sizeof(arr) / sizeof(arr[0]);
 
    HuffmanCodes(arr, freq, size);

	return 0;
}

// Time complexity: O(N * LogN) 
// Space complexity: O(N) 