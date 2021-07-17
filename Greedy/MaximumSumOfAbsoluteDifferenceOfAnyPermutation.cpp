#include <bits/stdc++.h>
using namespace std;
 
int MaxSumDifference(int a[], int n)
{
    sort(a, a + n);

    vector<int> finalSequence;
 
    int counter = 0;
    int i = 0;
    int j = n - 1;
    while (counter++ < n) {
        if (counter % 2 == 0)
            finalSequence.push_back(a[i++]);
        else
            finalSequence.push_back(a[j--]);
    }
 
    int MaximumSum = 0;
 
    for (int i = 0; i < n - 1; ++i)
        MaximumSum = MaximumSum + abs(finalSequence[i] - finalSequence[i + 1]);
    MaximumSum = MaximumSum + abs(finalSequence[n - 1] - finalSequence[0]);
 
    return MaximumSum;
}
 
int main()
{
    int a[] = { 1, 2, 4, 8, 16 };
    int n = sizeof(a) / sizeof(a[0]);
 
    cout << MaxSumDifference(a, n) << endl;
}