#include <bits/stdc++.h>
using namespace std;

vector<int> deno = { 1, 2, 5, 10, 20, 50, 100, 500, 1000 };

void findMin(int V) {
	sort(deno.begin(), deno.end());

	vector<int> ans;

	for (int i = deno.size() - 1; i >= 0; --i) {
		while (V >= deno[i]) {
			V -= deno[i];
			ans.push_back(deno[i]);
		}
	}

	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";
}

int main() {
	int n = 93;
    cout << "Following is minimal"
         << " number of change for " << n
         << ": ";
    findMin(n);

	return 0;
}

// Time Complexity: O(V).
// Auxiliary Space: O(V).