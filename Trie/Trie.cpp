#include <bits/stdc++.h>
using namespace std;

class Trie {
private:
	class Node {
	public:
		char data;
		unordered_map<char, Node*> children;
		bool isEndOfWord = false;

		Node (char data) {
			this->data = data;
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

		void remove(char ch) {
			children.erase(ch);
		}

		bool hasChildren() {
			return !children.empty();
		}
	};

	Node* findLastNodeOf(string prefix) {
		Node *current = root;

		for (char ch : prefix) {
			if (!current->hasChild(ch))
				return NULL;
			current = current->getChild(ch);
		}

		return current;
	}

	void findWords(Node *root, string prefix, vector<string> &list) {
		if (!root)
			return;

		if (root->isEndOfWord)
			list.push_back(prefix);

		for (Node *child : root->getChildren())
			findWords(child, prefix + child->data, list);
	}

	Node *root = new Node(' ');

public:
	void insert(string word) {
		Node *current = root;

		for (char ch : word) {
			if (!current->hasChild(ch))
				current->addChild(ch);
			current = current->getChild(ch);
		}

		current->isEndOfWord = true;
	}

	bool contains(string data) {
		Node *current = root;

		for (char ch : data) {
			if (!current->hasChild(ch))
				return false;
			current = current->getChild(ch);
		}

		return current->isEndOfWord;
	}

	void traverse(Node *root) {
		cout << root->data << endl;

		for (Node *x : root->getChildren())
			traverse(x);
	}

	void traverse() {
		traverse(root);
	}

	void remove(string word) {
		remove(root, word, 0);
	}

	void remove(Node *root, string word, int index) {
		if (index == word.length()) {
			root->isEndOfWord = false;
			return;
		}

		Node *child = root->getChild(word[index]);
		if (child == NULL)
			return;

		remove(child, word, index + 1);

		if (!child->hasChildren() and !child->isEndOfWord)
			root->remove(word[index]);
	}

	vector<string> findWords(string prefix) {
		vector<string> list;
		Node *lastNode = findLastNodeOf(prefix);

		findWords(lastNode, prefix, list);

		return list;
	}
};

int main() {
	Trie trie;

	trie.insert("car");
	trie.insert("card");
	trie.insert("care");
	trie.insert("careful");
	trie.insert("egg");

	// trie.remove("car");
	// trie.remove("care");

	// trie.traverse();

	// cout << trie.contains("car") << endl;
	// cout << trie.contains("care");

	for (string &word : trie.findWords("car"))
		cout << word << "\n";

	return 0;
}