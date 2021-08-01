// Leetcode 1512. Number of Good Pairs

class Solution {
public:
    
    int combination(int n, int r) {
        int res = 1;
        
        r = n - r < r ? n - r : r;
        
        for (int i = 0; i < r; ++i) {
            res *= n - i;
            res /= i + 1;
        }
        
        return res;
    }
    
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        
        for (int x : nums)
            m[x]++;
        
        int res = 0;
        
        for (auto x : m)
            if (x.second != 1)
                res += combination(x.second, 2);
        
        return res;
    }
};