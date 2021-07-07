#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        int mx[4] = {0,0,-1,1};
        int my[4] = {-1,1,0,0};

        bool isValid(int x, int y, int n, int m) {
            return (x >= 0 and x < n and y >= 0 and y < m);
        }

        bool hasRemainingOne(vector<vector<int>>& grid, int n, int m) {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    if (grid[i][j] == 1)
                        return true;
            return false;
        }

        class Node {
        public:
            int i, j, t;
            Node(int i , int j, int t) {
                this->i = i;
                this->j = j;
                this->t = t;
            }
        };

        int orangesRotting(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();

            queue<Node *> q;

            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    if (grid[i][j] == 2)
                        q.push(new Node(i, j, 0));

            int ans = 0;

            while (!q.empty()) {
                Node *cur = q.front();
                q.pop();

                int x = cur->i;
                int y = cur->j;

                ans = cur->t;

                for (int i = 0; i < 4; ++i) {
                    int tx = x + mx[i];
                    int ty = y + my[i];

                    if (isValid(tx, ty, n, m) and grid[tx][ty] == 1) {
                        grid[tx][ty] = 2;
                        q.push(new Node(tx, ty, cur->t + 1));
                    }
                }
            }

            return hasRemainingOne(grid, n, m) ? -1 : ans;
        }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>>grid(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
}