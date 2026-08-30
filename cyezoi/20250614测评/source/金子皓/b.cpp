#include <bits/stdc++.h>
using namespace std;

long long sth[200010];
long long c;

int main()
{
	long long ans=0;
	cin>>c;
	for(long long i=0;i<2;i++)
		for(long long j=0;j<c;j++) 
		{
			long long a;
			cin>>a;
			if(a==1) 
			{
				ans+=3;
				if(j!=0 && sth[j-1]==a) ans-=2;
				if(i!=0 && sth[j]==a && (j+1)%2==1) ans-=2; 
			}
			sth[j]=a;
		}
	cout<<ans;
	return 0;
}
