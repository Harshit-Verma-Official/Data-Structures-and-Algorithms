#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(vector<int> &arr, int sum, int index, vector<int> &aux, vector<vector<int>> &res) {
        if (index == arr.size()) {
            if (sum == 0){
                sort(aux.begin(), aux.end());
                res.push_back(aux);
            }
            return;
        }
        
        if (arr[index] <= sum) {
            aux.push_back(arr[index]);
            
            solve(arr, sum - arr[index], index, aux, res);
            
            aux.pop_back();
        }
        
        solve(arr, sum, index + 1, aux, res);
    }
    vector<vector<int> > combinationSum(vector<int> &arr, int sum) {
        vector<vector<int>> res;
        vector<int> aux;
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        
        solve(arr, sum, 0, aux, res);
        
        return res;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}

// Time Complexity: O(X^2 * 2^N), where X is average of summation B/arri for every number in the array.
// Auxiliary Space: O(X * 2^N)

// Test Case :
// 1
// 4
// 7 2 6 5
// 16