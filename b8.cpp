#include <bits/stdc++.h>
using namespace std;
int main()
{
    string x;
    cin>>x;
    for (int i=0 ; i< x.length()-1 ; i++)
    {
        char c = x[i];
        if (c='(')
            {cout<<"( open_parenthesis";}
        else if (c=')')
            {cout<<") close_parenthesis";}
        else if (c='+')
            {cout<<"+ operator";}
        else if (c='-')
            {cout<<"- operator";}
        else if (c='*')
            {cout<<"* operator";}
        else if (c='/')
            {cout<<"/ operator";}
        else 
            {cout<<c<<" "<<"operand";}
    }
    
}