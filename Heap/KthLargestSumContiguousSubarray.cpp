#include <bits/stdc++.h>
using namespace std;

int kthLargestSubSum(vector<int> &arr, int k) {
	int n = arr.size();
	
	priority_queue< int, vector<int>, greater<int> > minHeap;
	
	int preSum[n + 1];
	preSum[0] = 0;
	preSum[1] = arr[0];

	for (int i = 2; i <= n; ++i)
		preSum[i] = preSum[i - 1] + arr[i - 1];

	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			int sum = preSum[j] - preSum[i - 1];

			if (minHeap.size() < k)
				minHeap.push(sum);
			else {
				if (sum > minHeap.top()) {
					minHeap.pop();
					minHeap.push(sum);
				}
			}
		}
	}

	return minHeap.top();
}

int main() {
	vector<int> arr {10, -10, 20, -40} ;

	cout << kthLargestSubSum(arr, 6);

	return 0;
}