#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        unordered_set<int> set;
        int count = 0;
        unordered_map<int, int> indexes;
        
        for (int i = 0; i < N; ++i) {
            if (set.size() < C) {
                if (set.find(pages[i]) == set.end()) {
                    set.insert(pages[i]);
                    count++;
                }
            } else {
                if (set.find(pages[i]) == set.end()) {
                    int lru = INT_MAX;
                    int v;
                    for (auto x : set) {
                        if (indexes[x] < lru) {
                            lru = indexes[x];
                            v = x;
                        }
                    }
                    set.erase(v);
                    set.insert(pages[i]);
                    count++;
                }
            }
            indexes[pages[i]] = i;
        }
        
        return count;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}

// Time Complexity: O(N*C)
// Auxiliary Space: O(N)

// Test case :
// 1
// 9
// 5 0 1 3 2 4 1 0 5
// 4