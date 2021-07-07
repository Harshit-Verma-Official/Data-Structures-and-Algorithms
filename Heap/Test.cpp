#include <bits/stdc++.h>
using namespace std;

string add(string n1, string n2) {
	if (n1.length() > n2.length())
		swap(n1, n2);

	int sn1 = n1.size();
	int sn2 = n2.size();
	int diff = sn2 - sn1;

	string res = "";

	int carry = 0;
	for (int i = sn1 - 1; i >= 0; --i) {
		int sum = (n1[i] - '0') + (n2[i + diff] - '0') + carry;

		res.push_back(sum % 10 + '0'); 
		carry = sum / 10;
	}

	for (int i = sn2 - sn1 - 1; i >= 0; --i) {
		int sum = (n2[i] - '0') + carry;
		res.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	if (carry)
		res.push_back(carry + '0');

	reverse(res.begin(), res.end());

	for (int i = 0; i < res.length(); ++i)
		if (res[i] != '0')
			return res.substr(i);

	return "0";
}

string solve(int arr[], int n) {
	sort(arr, arr + n);

	string n1;
	string n2;

	for (int i = 0; i < n; ++i) {
		if (i & 1)
			n1.push_back(arr[i] + '0');
		else
			n2.push_back(arr[i] + '0');
	}

	return add(n1, n2);
}

int main() {
	int n = 6;
	int arr[] = {6, 8, 4, 5, 2, 3};

	cout << solve(arr, n);

	return 0;
}