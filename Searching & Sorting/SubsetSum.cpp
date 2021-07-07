#include <bits/stdc++.h>
using namespace std;

#define ll long long

void subSum(ll arr[], ll currindex, ll n, ll sum, vector<ll> &v) {
    if (currindex > n)
        return;

    if (currindex == n) {
        v.push_back(sum);
        return;
    }

    subSum(arr, currindex + 1, n, sum + arr[currindex], v);
    subSum(arr, currindex + 1, n, sum, v);
}

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    ll arr[n];
    for (ll i = 0; i < n; ++i)
        cin >> arr[i];

    vector<ll> v1;
    vector<ll> v2;

    subSum(arr, 0, (n / 2), 0, v1);
    subSum(arr, (n / 2), n, 0, v2);

    sort(v2.begin(), v2.end());

    ll res = 0;
    for (ll i = 0; i < v1.size(); ++i) {
        ll low = lower_bound(v2.begin(), v2.end(), a - v1[i]) - v2.begin();
        ll high = upper_bound(v2.begin(), v2.end(), b - v1[i]) - v2.begin();
        res += (high - low);
    }

    cout << res;

    return 0;
}