#include <bits/stdc++.h>
using namespace std;

#define long long int

int main() {
	int t;
	cin >> t;

	while (t--) {
		int h;
		int w;
		int n;

		cin >> w >> h >> n;

		vector<int> xv;
		vector<int> yv;

		xv.push_back(0);
		yv.push_back(0);

		for (int i = 0; i < n; ++i) {
			int x;
			int y;
			cin >> x >> y;
			xv.push_back(x);
			yv.push_back(y);
		}

		xv.push_back(w + 1);
		yv.push_back(h + 1);

		sort(xv.begin(), xv.end());
		sort(yv.begin(), yv.end());

		int mx = 0;
		int my = 0;

		for (int i = 0; i < xv.size() - 1; ++i) {
			mx = max(mx, xv[i + 1] - xv[i] - 1);
			my = max(my, yv[i + 1] - yv[i] - 1);
		}

		cout << mx * my << endl;
	}

	return 0;
}

// Test case : 
// 1
// 15 8 3
// 3 8
// 11 2
// 8 6