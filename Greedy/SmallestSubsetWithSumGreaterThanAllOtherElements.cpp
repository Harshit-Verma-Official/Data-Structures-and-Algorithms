#include <bits/stdc++.h>
using namespace std;

int main() {

	vector<int> arr = {3, 1, 7, 1};

	sort(arr.begin(), arr.end());

	int sum = 0;

	for (auto x : arr)
		sum += x;

	int newSum = 0;
	int count = 0;

	for (int i = arr.size() - 1; i >= 0; --i) {
		sum -= arr[i];
		newSum += arr[i];
		count++;
		if (newSum > sum)
			break;
	}

	cout << count;

	return 0;
}