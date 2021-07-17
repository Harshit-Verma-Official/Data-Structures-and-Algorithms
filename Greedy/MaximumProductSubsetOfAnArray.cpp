#include <bits/stdc++.h>
using namespace std;

int maxProductSubset(int arr[], int n) {
	if (n == 1)
		return arr[0];

	int max_neg = INT_MIN;
	int count_neg = 0;
	int count_zero = 0;
	int product = 1;

	for (int i = 0; i < n; ++i) {
		if (arr[i] == 0){
			count_zero++;
			continue;
		}

		if (arr[i] < 0) {
			count_neg++;
			max_neg = max(max_neg, arr[i]);
		}

		product *= arr[i];
	}

	if (count_zero == n)
		return 0;

	if (count_neg & 1) {
		if (count_neg == 1 and count_zero > 0 and count_zero + count_neg == n)
			return 0;
		product /= max_neg;
	}

	return product;
}

int main() {
	int a[] = {  -1, -1, -2, 4, 3  };
    int n = sizeof(a) / sizeof(a[0]);
    cout << maxProductSubset(a, n);

	return 0;
}