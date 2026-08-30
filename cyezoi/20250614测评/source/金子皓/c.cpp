#include <bits/stdc++.h>
using namespace std;

long long n,h[5100],hs[5100];

long long absm(long long a)
{
	if(a<0) return -a;
	return a;
}

long long notsame(long long l, long long r)
{
	long long ans=0;
	while(l<r)
	{
		ans+=absm(h[r]-h[l]);
		l++;
		r--;
	}
	return ans;
}

int main()
{
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>h[i];
		hs[i]=-1;
	}
	hs[1]=0;
	for(long long i=1;i<n;i++)
	{
		for(long long j=2;j<=n-i+1;j++) 
			{
				if(i!=1)hs[j]=min(hs[j],notsame(i,i+j-1));
				else hs[j]=notsame(i,i+j-1);
			}
	}
	for(long long i=1;i<=n;i++) cout<<hs[i]<<" ";
	return 0;
}

