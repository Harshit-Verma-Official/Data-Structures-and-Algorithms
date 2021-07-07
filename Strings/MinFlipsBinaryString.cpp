#include <bits/stdc++.h>
using namespace std;

int minFlips(string str) {
    int res = 0;

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == str[i + 1]) {
            res++;
            i++;
            continue;
        }
    }
    return res;
}

int main() {

    string str = "000001111111100000000000";

    cout << minFlips(str);

    return 0;
}