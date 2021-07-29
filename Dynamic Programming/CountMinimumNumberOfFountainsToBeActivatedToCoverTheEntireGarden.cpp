#include <bits/stdc++.h>
using namespace std;

int minCountFountains(int arr[], int n) {
	vector<int> dp(n, -1);

	int left;
	int right;

	for (int i = 0; i < n; i++) {
		left = max(i - arr[i], 0);
		right = min(i + arr[i] + 1, n);
		dp[left] = max(dp[left], right);
	}

	int countFountain = 1;

	right = dp[0];

	int idxNext = -1;

	for (int i = 0; i < n; ++i) {
		idxNext = max(idxNext, dp[i]);

		if (i == right) {
			countFountain++;
			right = idxNext;
		}
	}

	return countFountain;
}

int main() {
	int a[] = {2, 1, 1, 2, 1};
    int N = sizeof(a) / sizeof(a[0]);
    cout << minCountFountains(a, N);

	return 0;
}

// Time Complexity: O(N)
// Auxiliary Space: O(N)