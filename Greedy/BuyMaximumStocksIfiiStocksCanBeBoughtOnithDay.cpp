#include <bits/stdc++.h>
using namespace std;

int buyMaximumProducts(int n, int K, int arr[]) {
	vector<pair<int, int>> v;

	for (int i = 0; i < n; ++i)
		v.push_back({arr[i], i + 1});

	sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += min(v[i].second, K / v[i].first);
		K -= v[i].first * min(v[i].second, K / v[i].first);
	}

	return ans;
}

int main() {
	int price[] = { 10, 7, 19 };
    int n = sizeof(price)/sizeof(price[0]);
    int k = 45;
  
    cout << buyMaximumProducts(n, k, price) << endl;

	return 0;
}

// Time Complexity :O(nlogn).