#include <bits/stdc++.h>
using namespace std;
int G,p,g[100005],ans,f[100005];
int main()
{
	cin>>G>>p;
	for(int i=1;i<=p;++i)
	{
		cin>>g[i];
	}
	for(int i=1;i<=p;++i)
	{
		if(g[i]!=0)
		{
			if(f[g[i]]==0)
			{
				ans++;
				f[g[i]]=1;
			}
			else
			{
				g[i]--;
				i--;
			}
		}
		else break;
	}
	cout<<ans<<endl;
	return 0;
}
