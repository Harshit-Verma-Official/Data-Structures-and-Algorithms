#include <bits/stdc++.h>
using namespace std;

int getSum(int arr[], int n, int k) {
	deque<int> mins;
	deque<int> maxs;

	int ans = 0;

	for (int i = 0; i < n; ++i) {
		while (!mins.empty() and mins.front() <= i - k)
			mins.pop_front();
		while (!maxs.empty() and maxs.front() <= i - k)
			maxs.pop_front();

		while (!mins.empty() and arr[mins.back()] > arr[i])
			mins.pop_back();
		while (!maxs.empty() and arr[maxs.back()] < arr[i])
			maxs.pop_back();

		mins.push_back(i);
		maxs.push_back(i);

		if (i >= k - 1)
			ans += arr[mins.front()] + arr[maxs.front()];
	}

	return ans;
}

int main() {
	int arr[] = {2, 5, -1, 7, -3, -1, -2};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << getSum(arr, n, 4);

	return 0;
}