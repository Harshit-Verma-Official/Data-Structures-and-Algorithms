#include <bits/stdc++.h>
using namespace std;

#define long long int

int dp[1001][1001];

int solve(int health, int armour, int place) {
	if (health <= 0 or armour <= 0)
		return 0;

	if(dp[health][armour] != -1)
		return dp[health][armour];

	int x;
	int y;
	int z;

	x = y = z = 0;

	if (place != 1)
		x = 1 + solve(health + 3, armour + 2, 1);
	if (place != 2)
		y = 1 + solve(health - 5, armour - 10, 2);
	if (place != 3)
		z = 1 + solve(health - 20, armour + 5, 3);

	return dp[health][armour] = max({x, y, z});
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int health;
		int armour;

		cin >> health;
		cin >> armour;

		memset(dp, -1, sizeof(dp));

		cout << max({solve(health + 3, armour + 2, 1), solve(health - 5, armour - 10, 2), solve(health - 20, armour + 5, 3)}) << endl;
	}

	return 0;
}

// Test case :
// 3
// 2 10
// 4 4
// 20 8