#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a, vector<int> &b) {
	if (a[1] == b[1]) {
		if (a[2] == b[2])
			return a[0] < b[0];
		return a[2] < b[2];
	}
	return a[1] < b[1];
}

int main() {

	int n;
	cin >> n;

	vector<vector<int>> processes(n);
	vector<int> res;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			int x;
			cin >> x;
			processes[i].push_back(x);
		}
	}

	sort(processes.begin(), processes.end(), comp);

	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

	pq.push({processes[0][2], processes[0][1], processes[0][0]});

	int current_time = processes[0][1];
	int i = 1;

	while (!pq.empty()) {
		int burst_time = pq.top()[0];
		int id = pq.top()[2];

		pq.pop();

		res.push_back(id);

		current_time += burst_time;

		while (i < n and processes[i][1] <= current_time) {
			pq.push({processes[i][2], processes[i][1], processes[i][0]});
			i++;
		}
	}

	for (auto x : res)
		cout << x << " ";

	return 0;
}