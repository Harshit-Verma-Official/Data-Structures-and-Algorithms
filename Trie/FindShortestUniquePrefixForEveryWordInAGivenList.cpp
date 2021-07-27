#include <bits/stdc++.h>
using namespace std;

class Trie {
private:
	class Node {
	public:
		char data;
		int freq;
		unordered_map<char, Node*> children;
		bool isEndOfWord = false;

		Node (char data) {
			this->data = data;
			this->freq = 1;
		}

		Node(char data, int freq) {
			this->data = data;
			this->freq = freq;
		}

		bool hasChild(char ch) {
			return children.find(ch) != children.end();
		}

		void addChild(char ch) {
			children[ch] = new Node(ch);
		}

		Node* getChild(char ch) {
			return children.find(ch) != children.end() ? children[ch] : NULL;
		}

		vector<Node*> getChildren() {
			vector<Node*> childrenArr;

			for (auto x : children)
				childrenArr.push_back(x.second);

			return childrenArr;
		}
	};
	Node *root = new Node(' ', 0);

	void findPrefixes(Node *root, string prefix, vector<string> &res) {
		if (root == NULL)
			return;

		if (root->freq == 1) {
			res.push_back(prefix);
			return;
		}

		for (Node *child : root->getChildren())
			findPrefixes(child, prefix + child->data, res);
	}

public:
	void insert(string word) {
		Node *current = root;

		for (char ch : word) {
			if (!current->hasChild(ch))
				current->addChild(ch);
			else
				current->getChild(ch)->freq++;
			current = current->getChild(ch);
		}

		current->isEndOfWord = true;
	}

	vector<string> findPrefixes(string list[], int n) {
		vector<string> res;
		for (int i = 0; i < n; ++i)
			insert(list[i]);

		findPrefixes(root, "", res);

		return res;
	}
};

int main() {
	string arr[] = {"zebra", "dog", "duck", "dove"};
    int n = sizeof(arr)/sizeof(arr[0]);

	Trie trie;

	for (string &prefix : trie.findPrefixes(arr, n))
		cout << prefix << endl;

	return 0;
}

// Time Complexity : O(N) where N is total number of characters in all words.