class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int min_v = 0;
        int max_v = 0;
        int open_taps = 0;
        
        while (max_v < n) {
            for (int i = 0; i < ranges.size(); ++i)
                if (i - ranges[i] <= min_v and i + ranges[i] >= max_v)
                    max_v = i + ranges[i];
            
            if (min_v == max_v)
                return -1;
            
            min_v = max_v;
            open_taps++;
        }
        
        return open_taps;
    }
};

// Time Complexity : O(N^2)