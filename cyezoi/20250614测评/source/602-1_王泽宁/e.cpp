#include<bits/stdc++.h>
using namespace std;
int k,n,m,ans;
struct hx {
	int b,t,h;
};
vector<hx> g[10004];
bool vis[2003];
void dfs(int tim,int har,int n,int e) {
	if(n==e) {
		ans=min(ans,tim);
	}
	if(vis[n]) return;
	if(tim>=ans) return;
	if(har<=0) return;
	vis[n]=1;
	for(int i=0;i<g[n].size();i++) {
		dfs(tim+g[n][i].t,har-g[n][i].h,g[n][i].b,e);
	}
}
int main() {
	cin>>k>>n>>m;
	if(k==1) {
		for(int i=1;i<=m;i++) {
			int a,b,t,h;
			cin>>a>>b>>t>>h;
			if(h>=1)
				break;
			g[a].push_back(hx{b,t,h});
			g[b].push_back(hx{a,t,h});
		}
		int a,b;
		cin>>a>>b;
		dfs(0,k,a,b);
		cout<<ans;
	}
	return 0;
}
