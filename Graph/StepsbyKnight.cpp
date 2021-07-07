#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    struct Cell {
        int x;
        int y;
        int dis;
    };
    
    bool isInside(int x, int y, int N) {
        return x >= 1 and x <= N and y >= 1 and y <= N;
    }
    
	int minStepToReachTarget(vector<int>&kp,vector<int>&tp,int N) {
	    int dx[] = {-2, -2, -1, 1, -1, 1, 2, 2};
	    int dy[] = {-1, 1, -2, -2, 2, 2, -1, 1};
	    
	    bool vis[N + 1][N + 1];
	    memset(vis, false, sizeof(vis));
	    queue<Cell> q;
	    
	    vis[kp[0]][kp[1]] = true;
	    
	    q.push({kp[0], kp[1], 0});
	    
	    while (!q.empty()) {
	        Cell t = q.front();
	        q.pop();
	        
	        if (t.x == tp[0] and t.y == tp[1])
	            return t.dis;
	        
	        for (int i = 0; i < 8; ++i) {
	            int x = t.x + dx[i];
	            int y = t.y + dy[i];
	            if (isInside(x, y, N) and !vis[x][y]) {
    	            q.push({x, y, t.dis + 1});
    	            vis[x][y] = true;
	            }
	        }
	    }
	    
	    return -1;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}

// Input Format:

// Test Case then, Second line should contains N. Second line should contain the X-Y coordinates of the knight.Third line should contain the X-Y coordinates of the target.

 
// Example:
// 1
// 6
// 4 5
// 1 1

// Time Complexity: O(N2).
// Auxiliary Space: O(N2).