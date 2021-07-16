#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ll t;
	cin >> t;

	while (t--) {
		int m;
		int n;

		cin >> m >> n;

		m--;
		n--;

		ll x[m];
		ll y[n];

		for (ll i = 0; i < m; ++i)
			cin >> x[i];

		for (ll i = 0; i < n; ++i)
			cin >> y[i];

		sort(x, x + m, greater<int>());
		sort(y, y + n, greater<int>());

		ll i = 0;
		ll j = 0;

		ll horizontal_p = 1;
		ll vertical_p = 1;
		ll cost = 0;

		while (i < m and j < n) {
			if (x[i] > y[j]) {
				cost += vertical_p * x[i++];
				horizontal_p++;
			} else {
				cost += horizontal_p * y[j++];
				vertical_p++;
			}
		}

		while (i < m)
			cost += vertical_p * x[i++];

		while (j < n)
			cost += horizontal_p * y[j++];

		cout << cost << endl;
	}

	return 0;
}

// Time : O(NlogN)
// Space : O(1)

// Test case : 
// 1
// 6 4
// 2
// 1
// 3
// 1
// 4
// 4
// 1
// 2