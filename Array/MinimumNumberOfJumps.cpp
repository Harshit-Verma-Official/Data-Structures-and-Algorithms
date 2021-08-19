#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        if (n == 1)
            return 0;
        if (arr[0] == 0)
            return -1;

        int maxR = arr[0];
        int step = arr[0];
        int jump = 1;

        for (int i = 1; i < n - 1; ++i)
        {
            maxR = max(maxR, i + arr[i]);
            step--;

            if (step == 0)
            {
                jump++;
                if (i >= maxR)
                    return -1;
                step = maxR - i;
            }
        }

        return jump;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)

// Test Case
// 1
// 11
// 1 3 5 8 9 2 6 7 6 8 9