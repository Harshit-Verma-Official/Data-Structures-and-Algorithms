#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void dfs(int i, int j, vector<vector<char>> &grid, int rows, int cols) {
        if (i < 0 or i >= rows or j < 0 or j >= cols or grid[i][j] != '1')
            return;
        
        grid[i][j] = '2';
        
        dfs(i - 1, j, grid, rows, cols);
        dfs(i - 1, j - 1, grid, rows, cols);
        dfs(i - 1, j + 1, grid, rows, cols);
        dfs(i, j - 1, grid, rows, cols);
        dfs(i, j + 1, grid, rows, cols);
        dfs(i + 1, j - 1, grid, rows, cols);
        dfs(i + 1, j, grid, rows, cols);
        dfs(i + 1, j + 1, grid, rows, cols);
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int rows = grid.size();
        
        if (rows == 0)
            return 0;
        
        int cols = grid[0].size();
        int ans = 0;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid, rows, cols);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}

// Time Compelxity: O(n*m)
// Space Compelxity: O(n*m)