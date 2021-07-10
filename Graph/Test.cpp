#include <bits/stdc++.h>
using namespace std;

#define ll long long
 
int findMaxSum(vector<ll> arr, int n)
{
    int incl = arr[0];
    int excl = 0;
    int excl_new;
    int i;
 
    for (i = 1; i < n; i++)
    {
        /* current max excluding i */
        excl_new = (incl > excl) ? incl : excl;
 
        /* current max including i */
        incl = excl + arr[i];
        excl = excl_new;
    }
 
    /* return max of incl and excl */
    return ((incl > excl) ? incl : excl);
}
 
int main() {
    ll n;
    vector<ll> arr;

    cin >> n;

    ll aux;
    for (ll i = 0; i < n; ++i) {
        cin >> aux;
        arr.push_back(aux);
    }

    cout << findMaxSum(arr, arr.size());

    return 0;
}