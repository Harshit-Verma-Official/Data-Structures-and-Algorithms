#include <bits/stdc++.h>
using namespace std;

bool isPossible(int ranks[], int l, int p, int min_time) {
    int prataCount = 0;
    for (int i = 0; i < l; ++i) {
        int timeTaken = ranks[i];
        int j = 2;
        while (timeTaken <= min_time) {
            prataCount++;
            timeTaken += ranks[i] * j;
            j++;
        }
        if (prataCount >= p)
            return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int p, l;
        cin >> p >> l;

        int rank[l];
        for (int i = 0; i < l; ++i)
            cin >> rank[i];

        int low = 0;
        int high = 1e8;
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(rank, l, p, mid)) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }

        cout << ans << endl;
    }

    return 0;
}