#include <bits/stdc++.h>
using namespace std;

string findSubString(string str) {
    int n = str.length();

    unordered_set<char> set;
    for (int i = 0; i < n; ++i)
        set.insert(str[i]);

    int dist_count = set.size();

    int start = 0;
    int start_index = -1;
    int min_len = INT_MAX;

    int count = 0;
    unordered_map<char, int> map;

    for (int i = 0; i < n; ++i) {
        map[str[i]]++;

        if (map[str[i]] == 1)
            count++;

        if (count == dist_count) {
            while (map[str[start]] > 1) {
                if (map[str[start]] > 1)
                    map[str[start]]--;
                start++;
            }

            int window_len = i - start + 1;
            if (window_len < min_len) {
                min_len = window_len;
                start_index = start;
            }
        }
    }

    return str.substr(start_index, min_len);
}

int main() {
    string str = "aabcbcdbca";
    cout << "Smallest window containing all distinct"
            " characters is: "
         << findSubString(str);

    return 0;
}