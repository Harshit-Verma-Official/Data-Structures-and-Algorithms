#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool bfs(int cur, vector<int> adj[], vector<int> &color) {
        queue<int> q;
        q.push(cur);
        color[cur] = 1;
        
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            
            for (auto x : adj[top]) {
                if (color[x] == color[top])
                    return false;
                else if (color[x] == -1) {
                    color[x] = 1 - color[top];
                    q.push(x);
                }
            }
        }
        
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]) {
	    vector<int> color(V, -1);
	    
	    for (int i = 0; i < V; ++i)
	        if (color[i] == -1)
	            if (!bfs(i, adj, color))
	                return false;
	                
	    return true;
	}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}

// Time : O(V)
// Space : O(V)