#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9 + 7;
long long mu(long long a,long long b, long long c)
{
    if (b == 0) 
        return 1;
    long long t = mu(a, b / 2,c);  
    //cout << t << endl;   	
    t = (t * t) % c; 
    if (b % 2 == 1) 
        t = (t * a) % c;
    return t;
} 
int main()
{
    long long a,b,c,d;
    cin>>a>>b>>c;
    d = mu(a,b,c);
    cout<<d;
    return 0;
}