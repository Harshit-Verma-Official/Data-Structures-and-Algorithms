#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool solve(ll arr[], ll n, ll m, ll h) {
    ll sum = 0;

    for (ll i = 0; i < n; ++i)
        if (arr[i] > h)
            sum += arr[i] - h;

    return sum >= m;
}

int main() {
    ll n, m;
    cin >> n >> m;

    ll height[n];
    for (ll i = 0; i < n; ++i)
        cin >> height[i];

    ll low = 0;
    ll high = *max_element(height, height + n);
    ll ans = 0;

    while (low <= high) {
        ll mid = (low + high) / 2;
        if (solve(height, n, m, mid)) {
            ans = mid;
            low = mid + 1;
        } else
            high = mid - 1;
    }

    cout << ans;

    return 0;
}