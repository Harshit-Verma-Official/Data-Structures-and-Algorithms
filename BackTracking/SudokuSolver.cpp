#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends


class Solution 
{
    public:
    bool isValid(int grid[N][N], int row, int col, int ch) {
        for (int i = 0; i < N; ++i) {
            if (grid[i][col] == ch)
                return false;
            if (grid[row][i] == ch)
                return false;
            if (grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
                return false;
        }
        return true;
    }
    
    bool solve(int grid[N][N]) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 0) {
                    for (int ch = 1; ch <= 9; ++ch) {
                        if (isValid(grid, i, j, ch)) {
                            grid[i][j] = ch;
                            
                            if (solve(grid))
                                return true;
                            else
                                grid[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N]) {
        return solve(grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j)
                cout << grid[i][j] << " ";
            cout << endl;
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends

// Time Complexity: O(9N*N).
// Auxiliary Space: O(N*N).

// Test case : 
// 1
// 3 0 6 5 0 8 4 0 0 
// 5 2 0 0 0 0 0 0 0 
// 0 8 7 0 0 0 0 3 1 
// 0 0 3 0 1 0 0 8 0 
// 9 0 0 8 6 3 0 0 5 
// 0 5 0 0 9 0 6 0 0 
// 1 3 0 0 0 0 2 5 0 
// 0 0 0 0 0 0 0 7 4 
// 0 0 5 2 0 6 3 0 0