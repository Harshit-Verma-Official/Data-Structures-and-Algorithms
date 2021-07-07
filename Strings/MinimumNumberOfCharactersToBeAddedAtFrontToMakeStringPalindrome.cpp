#include <bits/stdc++.h>
using namespace std;

vector<int> computerLPS(string str) {
    int n = str.length();

    vector<int> lps(n);
    lps[0] = 0;

    int i = 1;
    int j = 0;

    while (i < n) {
        if (str[i] == str[j]) {
            j++;
            lps[i] = j;
            i++;
        } else {
            if (j != 0)
                j = lps[j - 1];
            else
                lps[i++] = 0;
        }
    }

    return lps;
}

int getMinCharToAddedToMakeStringPalin(string str) {
    string revStr = str;
    reverse(revStr.begin(), revStr.end());
    revStr = str + "$" + revStr;
    vector<int> lps = computerLPS(revStr);
    return (str.length() - lps.back());
}

int main() {
    int arr[6] = {4, 2, 6, 0, 5, 10};
    int size = *(&arr + 1) - arr;
    cout << size;

    return 0;
}