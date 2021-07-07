#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n, c;
        cin >> n >> c;
        ll stalls[n];

        for (ll i = 0; i < n; ++i)
            cin >> stalls[i];

        sort(stalls, stalls + n);

        ll low = 1;
        ll high = 1e9;
        ll ans = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll cows = 1;
            ll prev = stalls[0];

            for (ll i = 1; i < n; ++i) {
                if (stalls[i] - prev >= mid) {
                    cows++;
                    prev = stalls[i];
                    if (cows == c)
                        break;
                }
            }

            if (cows == c) {
                ans = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }

        cout << ans << endl;
    }

    return 0;
}