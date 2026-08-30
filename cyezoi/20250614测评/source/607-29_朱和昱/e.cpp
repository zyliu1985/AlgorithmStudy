#include<bits/stdc++.h>
using namespace std;
#define int long long
int k,n,m;
struct node{
	int v,t,h;
};
vector<node> g[10005];
int s,t;
int ans=1000000000000;
node pack(int v,int t,int h){
	node temp;
	temp.v=v;temp.t=t;temp.h=h;
	return temp;
}
void dfs(int cur,int tim,int hei){
	if(hei>=k) return;
	if(cur==t){
		ans=min(ans,tim);
		return;
	}
	for(int i=0;i<g[cur].size();i++){
		node temp=g[cur][i];
		int nxt=temp.v;
		dfs(nxt,tim+temp.t,hei+temp.h);
	}
	return;
}
signed main(){
	cin>>k>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b,t,h;
		cin>>a>>b>>t>>h;
		g[a].push_back(pack(b,t,h));
		g[b].push_back(pack(a,t,h));
	}
	cin>>s>>t;
	dfs(s,0,0);
	cout<<ans<<endl;
	return 0;
}
