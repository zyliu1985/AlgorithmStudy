#include<bits/stdc++.h>
using namespace std;
int k,n,m,s,t,ans;
struct NODE {
	int a,b,t,h;
};
vector<NODE> g[2003];
int f[2003];  //f[i][j] 从起点到点i，磨损为j时，的最小耗时
struct DIS {
	int id,h,t;
};
queue<DIS> que;
void bfs(int s) {
	que.push((DIS) {
		s,0,0
	});
	f[s]=0;
	while(!que.empty()) {
		DIS nod=que.front();
		que.pop();
		int u=nod.id,h=nod.h,t=nod.t;
		for(unsigned int i=0; i<g[u].size(); i++) {
			int v=g[u][i].b,tt=g[u][i].t,hh=g[u][i].h;
			if(h+hh<k && f[u]+tt<f[v]) {
				f[v]=f[u]+tt;
				que.push((DIS) {
					v,h+hh,t+tt
				});
			}
		}
	}
}
int main() {
	cin>>k>>n>>m;
	for(int i=1; i<=m; i++) {
		int a,b,t,h;
		cin>>a>>b>>t>>h;
		g[a].push_back((NODE) {
			a,b,t,h
		});
		g[b].push_back((NODE) {
			b,a,t,h
		});
	}
	cin>>s>>t;
	memset(f,0x3f,sizeof(f));
	bfs(s);
	ans=0x3f3f3f3f;
	//for(int i=0;i<k;i++)ans=min(ans,f[t][i]);
	ans=min(ans,f[t]);
	if(ans==0x3f3f3f3f)cout<<-1;
	else cout<<ans;
	return 0;
}
/*
# P9813 2015 S4 搜索 最优性剪枝

f[i][j] 从起点到点i，磨损为j时，的最小耗时

(u,v,t,h)
如果 f[u][j]+t<f[v][j+h]，有f[v][j+h]=f[u][j]+t

在bfs的过程中执行转移

初始 f[s][0]=0
目标 min{f[t][j]}
*/

