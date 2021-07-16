#include <bits/stdc++.h>
using namespace std;
 
void survival(int S, int N, int M) {
    int sundays = S / 7;
    int totalDays = S - sundays;

    int foodRequired = S * M;

    int days = foodRequired / N;

    if (foodRequired % N != 0)
        days++;

    days <= totalDays ? cout << "Yes " << days : cout << "No";
    cout << endl;
}
 
int main()
{
    int S = 10, N = 16, M = 2;
    survival(S, N, M);
    return 0;
}

// Time Complexity: O(1) 
// Space Complexity: O(1) 