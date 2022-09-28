// C++ program for above implementation
#include<iostream>
 
using namespace std ;
 
int nCr(int n, int r)
{
    int fac[100] = {1} ;
     
    for (int i = 1 ; i < n + 1 ; i++)
    {
        fac[i] = fac[i - 1] * i ;
    }
     
    int ans = fac[n] / (fac[n - r] *
                        fac[r]) ;
    return ans ;
}
 
// Driver Code
int main()
{
    int n = 2 ;
    int k = 5 ;
     
    int ans = nCr(k,n) -
              nCr(k -6*n-1, k-7*n);
     
    cout << ans ;
     
    return 0 ;
}   