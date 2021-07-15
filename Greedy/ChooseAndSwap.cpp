#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    string chooseandswap(string a) {
        set<char> set;
        
        for (int i = 0; i < a.length(); ++i)
            set.insert(a[i]);
        
        for (int i = 0; i < a.length(); ++i) {
            char ch = a[i];
            
            set.erase(ch);
            
            if (set.empty())
                break;
            
            char next = *(set.begin());
            
            if (next < ch) {
                for (int j = 0; j < a.length(); ++j) {
                    if (a[j] == ch)
                        a[j] = next;
                    else if (a[j] == next)
                        a[j] = ch;
                }
                break;
            }
        }
        
        return a;
    }
    
};

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}

// Time Complexity: O(|A|) length of the string A
// Auxiliary Space: O(1)

// Test case :
// 1
// ccad
