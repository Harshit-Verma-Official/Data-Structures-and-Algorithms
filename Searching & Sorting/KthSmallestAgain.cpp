#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n, q;
        cin >> n >> q;

        vector<pair<ll, ll>> intervals;
        for (ll i = 0; i < n; ++i) {
            ll x, y;
            cin >> x >> y;
            intervals.push_back({x, y});
        }
        sort(intervals.begin(), intervals.end());

        ll idx = 0;
        for (ll i = 1; i < intervals.size(); ++i) {
            if (intervals[idx].second >= intervals[i].first)
                intervals[idx].second = max(intervals[idx].second, intervals[i].second);
            else
                intervals[++idx] = intervals[i];
        }

        while (q--) {
            ll k;
            cin >> k;

            ll ans = -1;
            for (ll i = 0; i <= idx; ++i) {
                if (intervals[i].second - intervals[i].first + 1 >= k) {
                    ans = intervals[i].first + k - 1;
                    break;
                } else
                    k -= intervals[i].second - intervals[i].first + 1;
            }

            cout << ans << endl;
        }
    }

    return 0;
}