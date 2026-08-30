#include<bits/stdc++.h>
using namespace std;
int G,p,g[100005],ans;
bool vis[100005];
int main()
{
	cin>>G>>p;
	for(int i=1;i<=p;i++) cin>>g[i];
	for(int i=1;i<=p;i++)
	{
		if(!vis[g[i]]) ans++,vis[g[i]]=1;
		else
		{
			int t=g[i];
			while(vis[t]&&t>1) t--;
			if(t==1&&vis[1]) break;
			else ans++,vis[t]=1;
		}
	}
	cout<<ans;
	return 0;
}
