#include<bits/stdc++.h>
using namespace std;
 
 // A O(n) solution that uses
// table fact[] to calculate
// the Permutation Coefficient
// Returns value of Permutation
// Coefficient P(n, k)
int permutationCoeff1(int n, int k)
{
    int fact[n + 1];
 
    // Base case
    fact[0] = 1;
 
    // Calculate value
    // factorials up to n
    for(int i = 1; i <= n; i++)
    fact[i] = i * fact[i - 1];
 
    // P(n,k) = n! / (n - k)!
    return fact[n] / fact[n - k];
}


// A O(n) time and O(1) extra
// space solution to calculate
// the Permutation Coefficient
int permutationCoeff2(int n, int k)
{
    int P = 1;
 
    // Compute n*(n-1)*(n-2)....(n-k+1)
    for (int i = 0; i < k; i++)
        P *= (n-i) ;
 
    return P;
}
 
int main()
{
    int n = 10, k = 2;
     
    cout << "Value of P(" << n << ", "
        << k << ") is "
        << permutationCoeff2(n, k);
 
    return 0;
}