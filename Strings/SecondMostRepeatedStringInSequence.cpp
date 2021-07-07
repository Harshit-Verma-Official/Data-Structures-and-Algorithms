#include <bits/stdc++.h>
using namespace std;

string secFrequent(string arr[], int n) {
    unordered_map<string, int> map;

    for (int i = 0; i < n; ++i)
        map[arr[i]]++;

    int max_first = INT_MIN;
    int max_second = INT_MIN;

    for (auto itr = map.begin(); itr != map.end(); itr++) {
        if (itr->second > max_first) {
            max_second = max_first;
            max_first = itr->second;
        } else if (itr->second > max_second and itr->second != max_first)
            max_second = itr->second;
    }

    for (int i = 0; i < n; ++i)
        if (map[arr[i]] == max_second)
            return arr[i];

    return "-1";
}

int main() {

    string arr[] = {"aaa", "bbb", "ccc", "bbb", "aaa", "aaa"};

    cout << secFrequent(arr, 6);

    return 0;
}