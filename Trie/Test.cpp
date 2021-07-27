#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		string num;
		cin >> num;

		num[0] != '1' ? cout << "1" + num : cout << num[0] << "0" << num.substr(1);
		cout << endl;
	}

	return 0;
}