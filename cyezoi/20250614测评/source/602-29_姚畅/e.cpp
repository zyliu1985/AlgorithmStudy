#include <bits/stdc++.h>
using namespace std;
int k,n,m,t[2001][2001],h[2001][2001],a,b,ans=-1;
bool vis[2001];
void dfs(int u,int tott,int toth){
	vis[u]=1;
	if(u==b){
		if(ans>=0)ans=min(ans,tott);
		else ans=tott;
		return;
	}
	for(int i=1;i<=n;i++){
		if(t[u][i]>=0&&(!vis[i])&&toth+h[u][i]<k){
			dfs(i,tott+t[u][i],toth+h[u][i]);
		}
	}
	vis[u]=0;
	return;
}
int main(){
	//freopen("data.in","r",stdin);
	ios::sync_with_stdio(0),cin.tie(0);
	memset(t,-1,sizeof(t));
	memset(h,-1,sizeof(h));
	cin>>k>>n>>m;
	for(int i=1;i<=m;i++){
		int ai,bi;
		cin >> ai>>bi;
		cin>>t[ai][bi]>>h[ai][bi];
		t[bi][ai]=t[ai][bi];
		h[bi][ai]=h[ai][bi];
	}
	cin >> a>>b;
	dfs(a,0,0);
	cout << ans;
	return 0;
}
