#include <bits/stdc++.h>
using namespace std;

string getFirstNonRepeatingCharString(string str) {
    vector<int> visited(26, 0);
    vector<char> order;
    string ans = "";
    for (int i = 0; i < str.length(); ++i) {
        if (!visited[str[i] - 'a'])
            order.push_back(str[i]);
        visited[str[i] - 'a']++;
        int flag = 0;
        for (int j = 0; j < order.size(); ++j) {
            if (visited[order[j] - 'a'] == 1) {
                ans.push_back(order[j]);
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            ans.push_back('#');
    }

    return ans;
}

int main() {

    string str = "aabc";

    cout << getFirstNonRepeatingCharString(str);

    return 0;
}