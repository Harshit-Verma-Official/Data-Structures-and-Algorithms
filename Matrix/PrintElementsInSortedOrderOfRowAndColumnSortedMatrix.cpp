#include <bits/stdc++.h>
using namespace std;

// Test Case
// 4
// 4
// 10 20 30 40
// 4
// 15 25 35 45
// 4
// 27 29 37 48
// 4
// 32 33 39 50

// Expected Output
// 10 15 20 25 27 29 30 32 33 35 37 39 40 45 48 50

typedef pair<int, pair<int, int>> pii;

void printSorted(vector<vector<int>> kArrays, int k) {
    vector<int> output;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (int i = 0; i < k; ++i)
        pq.push({kArrays[i][0], {i, 0}});

    while (!pq.empty()) {
        pii cur = pq.top();
        pq.pop();

        output.push_back(cur.first);

        int i = cur.second.first;
        int j = cur.second.second;

        if (j + 1 < kArrays[i].size())
            pq.push({kArrays[i][j + 1], {i, j + 1}});
    }

    for (int i = 0; i < output.size(); ++i)
        cout << output[i] << " ";
}

int main() {

    // Input
    vector<vector<int>> kArrays;
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int size;
        cin >> size;
        vector<int> temp(size);
        for (int j = 0; j < size; ++j)
            cin >> temp[j];
        kArrays.push_back(temp);
    }

    printSorted(kArrays, k);

    return 0;
}