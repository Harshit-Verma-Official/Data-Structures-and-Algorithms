#include <bits/stdc++.h>
using namespace std;

int romanToDecimal(string &str) {
    unordered_map<char, pair<int, int>> dict;
    dict.insert({'I', make_pair(0, 1)});
    dict.insert({'V', make_pair(1, 5)});
    dict.insert({'X', make_pair(2, 10)});
    dict.insert({'L', make_pair(3, 50)});
    dict.insert({'C', make_pair(4, 100)});
    dict.insert({'D', make_pair(5, 500)});
    dict.insert({'M', make_pair(6, 1000)});

    int last = -1;
    int sum = 0;
    for (int i = str.length() - 1; i >= 0; --i) {
        if (dict.find(str[i])->second.first >= last)
            sum += dict.find(str[i])->second.second;
        else
            sum -= dict.find(str[i])->second.second;
        last = dict.find(str[i])->second.first;
    }

    return sum;
}

int main() {

    string x = "XIX";
    cout << romanToDecimal(x);

    return 0;
}