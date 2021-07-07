#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string pat, int lps[]) {
    lps[0] = 0;

    int i = 1;
    int j = 0;

    while (i < pat.length()) {
        if (pat[i] == pat[j]) {
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
}

void KMPSearch(string pat, string txt) {
    int n = txt.length();
    int m = pat.length();

    int lps[m];
    computeLPSArray(pat, lps);

    int i = 0;
    int j = 0;

    while (i < n) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }
        if (j == m) {
            cout << "Found pattern at index " << (i - j) << endl;
            j = lps[j - 1];
        } else if (i < n and pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {

    string txt = "batmanandrobinarebat";
    string pat = "bat";
    KMPSearch(pat, txt);

    return 0;
}