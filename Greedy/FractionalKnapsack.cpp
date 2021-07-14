#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution
{
    public:
    static bool comp(Item &a, Item &b) {
        double av = (double) a.value / (double) a.weight; 
        double bv = (double) b.value / (double) b.weight;
        return av > bv; 
    }
    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr + n, comp);
        
        int curW = 0;
        double curV = 0;
        
        for (int i = 0; i < n; ++i) {
            if (arr[i].weight + curW <= W) {
                curW = arr[i].weight + curW;
                curV += arr[i].value;
            } else {
                int remain = W - curW;
                curV += ((double) arr[i].value / (double) arr[i].weight) * (double) remain;
                break;
            }
        }
        
        return curV;
    }
        
};


int main()
{
	int t;
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}

// Time Complexity : O(NlogN)
// Auxilliary Space: O(1)

// Test Case : 
// 1
// 3 50
// 60 10 100 20 120 30