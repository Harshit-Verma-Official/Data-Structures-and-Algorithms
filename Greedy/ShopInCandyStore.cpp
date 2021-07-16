#include<bits/stdc++.h> 
using namespace std; 

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K) {
        sort(candies, candies + N);
        
        int i = 0;
        int j = N - 1;
        
        int min = 0;
        int max = 0;
        
        while (i <= j) {
            min += candies[i++];
            j -= K;
        }
        
        i = 0;
        j = N - 1;
        
        while (j >= i) {
            max += candies[j--];
            i += K;
        }
        
        return {min, max};
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}

// Time Complexity: O(NLogN)
// Auxiliary Space: O(1)

// Test case
// 1
// 4 2
// 3 2 1 4