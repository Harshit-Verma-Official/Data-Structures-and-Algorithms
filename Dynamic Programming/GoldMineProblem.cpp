#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M) {
        for (int col = m - 2; col >= 0; --col) {
            for (int row = 0; row < n; ++row) {
                int right_up = row == 0 ? 0 : M[row - 1][col + 1];
                int right = M[row][col + 1];
                int right_down = row == n - 1 ? 0 : M[row + 1][col + 1];
                M[row][col] = M[row][col] + max(right_up, max(right, right_down));
            }
        }
        
        int ans = M[0][0];
        for (int i = 0; i < n; ++i)
            ans = max(ans, M[i][0]);
        
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}

// Time Complexity: O(n*m)
// Auxiliary Space: O(n*m)

// Test Case :
// 1
// 3 3
// 1 3 3 2 1 4 0 6 4