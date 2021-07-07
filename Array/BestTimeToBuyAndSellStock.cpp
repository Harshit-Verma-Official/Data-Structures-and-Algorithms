#include <bits/stdc++.h>
using namespace std;

// Only One transaction allowed
// Time : O(n)
// Space : O(1)
int getMaxProfitInOnlyOneTransaction(int prices[], int n) {
    int profit = 0;
    int min_v = prices[0];

    for (int i = 1; i < n; ++i) {
        min_v = min(min_v, prices[i]);
        profit = max(profit, prices[i] - min_v);
    }

    return profit;
}

// Maximum profit by buying and selling a share at most twice
// Time : O(n)
// Space: O(n)
int getMaxProfitAtMostTwoTransaction(int prices[], int n) {
    int profit[n];
    profit[n - 1] = 0;

    int max_v = prices[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        max_v = max(max_v, prices[i]);
        profit[i] = max(profit[i + 1], max_v - prices[i]);
    }

    int min_v = prices[0];
    for (int i = 1; i < n; ++i) {
        min_v = min(min_v, prices[i]);
        profit[i] = max(profit[i - 1], profit[i] + prices[i] - min_v);
    }

    return profit[n - 1];
}

// When any number of transactions are allowed (buy + sell)
// Time : O(n)
// Space : O(1)
// Method : Valley-Peak Approach
int getMaxProfitInMultipleTransactions(int prices[], int n) {
    int profit = 0;
    for (int i = 1; i < n; ++i) {
        int sub = prices[i] - prices[i - 1];
        if (sub > 0)
            profit += sub;
    }
    return profit;
}

int main() {
    int prices[] = {1, 2, 3, 4, 5};
    int n = sizeof(prices) / sizeof(prices[0]);

    cout << getMaxProfitInMultipleTransactions(prices, n);

    return 0;
}