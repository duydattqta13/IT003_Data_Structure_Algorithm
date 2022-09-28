#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int n;
	cin>>n;
	long long int a[n];
	for (int i=0;i<n;i++)
		cin>>a[i];
	long long int maxt,mint,ans;
	mint=a[0];
	for (int i=0;i<n;i++)
		{	mint =min(a[i],mint);
			maxt=a[i]-mint;
			if (maxt>ans)
				ans=maxt;
		}
		
	cout<<ans;
	return 0;
}