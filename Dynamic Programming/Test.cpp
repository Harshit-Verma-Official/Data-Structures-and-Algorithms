#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ll t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;

		vector<ll> arr(n);
		ll mn = INT_MAX;

		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			mn = min(mn, arr[i]);
		}

		ll orr = 0;
		for (int i = 0; i < n; ++i) {
			arr[i] ^= mn;
			orr |= arr[i];
		}

		cout << mn << " " << orr << "\n";
	}

	return 0;
}