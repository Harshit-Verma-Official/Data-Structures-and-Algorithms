#include <bits/stdc++.h>
using namespace std;

// Time : O(nLogn)
// Space : O(1)
int getMinDifference(int packets[], int n, int m) {
    sort(packets, packets + n);

    int res = INT_MAX;
    for (int i = 0; i + m - 1 < n; ++i)
        res = min(res, packets[i + m - 1] - packets[i]);

    return res;
}

int main() {

    int packets[] = {3, 4, 1, 9, 56, 7, 9, 12};
    int n = sizeof(packets) / sizeof(packets[0]);

    cout << getMinDifference(packets, n, 5);

    return 0;
}