#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;
        bool isPresent = false;
        
        for (auto word : wordList) {
            if (endWord.compare(word) == 0)
                isPresent = true;
            wordSet.insert(word);
        }
        
        if (!isPresent)
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        
        int depth = 0;
        
        while (!q.empty()) {
            depth++;
            int size = q.size();
            
            while (size--) {
                string cur = q.front();
                q.pop();
                for (int i = 0; i < cur.size(); ++i) {
                    string temp = cur;
                    for (int c = 'a'; c <= 'z'; ++c) {
                        temp[i] = c;
                        if (cur.compare(temp) == 0)
                            continue;
                        if (temp.compare(endWord) == 0)
                            return depth + 1;
                        if (wordSet.find(temp) != wordSet.end()) {
                            wordSet.erase(temp);
                            q.push(temp);
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};

int main() {
	string beginWord;
	string endWord;
	vector<string> wordList;

	int n;
	cin >> n;

	cin >> beginWord >> endWord;

	for (int i = 0; i < n; ++i) {
		string word;
		cin >> word;
		wordList.push_back(word);
	}

	Solution solve;

	cout << solve.ladderLength(beginWord, endWord, wordList);

	return 0;
}

// Input Format:
// n(number of words)
// beginWord endWord
// n words

// 6
// hit cog
// hot dot dog lot log cog