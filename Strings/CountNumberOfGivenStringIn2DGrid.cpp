#include <bits/stdc++.h>
using namespace std;

int dfs(string hay[], string needle, int i, int j, int idx) {
    int found = 0;

    if (i >= 0 and j >= 0 and i < hay->length() and j < hay[i].length() and hay[i][j] == needle[idx]) {
        char temp = needle[idx];
        hay[i][j] = '0';
        idx++;
        if (idx == needle.length())
            found = 1;
        else {
            found += dfs(hay, needle, i + 1, j, idx);
            found += dfs(hay, needle, i - 1, j, idx);
            found += dfs(hay, needle, i, j + 1, idx);
            found += dfs(hay, needle, i, j - 1, idx);
        }
        hay[i][j] = temp;
    }
    return found;
}

bool internalSearch(string hay[], string needle, int i, int j, int idx) {
    if (idx == needle.length())
        return true;

    if (i < 0 or i >= hay->length() or j < 0 or j >= hay[i].length())
        return false;

    bool found = 0;
    if (hay[i][j] == needle[idx]) {
        char temp = needle[idx];
        hay[i][j] = '0';
        found = internalSearch(hay, needle, i + 1, j, idx + 1) || internalSearch(hay, needle, i - 1, j, idx + 1) || internalSearch(hay, needle, i, j + 1, idx + 1) || internalSearch(hay, needle, i, j - 1, idx + 1);
        hay[i][j] = temp;
    }

    return found;
}

int searchString(string hay[], string needke) {
    int count = 0;

    for (int i = 0; i < hay->length(); ++i)
        for (int j = 0; j < hay[i].length(); ++j)
            count += internalSearch(hay, needke, i, j, 0);

    return count;
}

int main() {
    string needle = "MAGIC";
    string input[] = {"BBABBM",
                      "CBMBBA",
                      "IBABBG",
                      "GOZBBI",
                      "ABBBBC",
                      "MCIGAM"};

    cout << searchString(input, needle);

    return 0;
}