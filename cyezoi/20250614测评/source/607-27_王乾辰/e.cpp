#include <bits/stdc++.h>
using namespace std;
//#define int ll
#define ll long long

#define N (2005*205)

struct edge{
	int v,w;
};
vector<edge>g[N];
int dis[N];

struct node{
	int idx,dis;
	inline bool operator<(const node& x)const{
		return dis<x.dis;
	}
};

signed main(){
	int k,n,m;cin>>k>>n>>m;
	
	for(int i=1;i<=m;i++){
		int a,b,t,h;cin>>a>>b>>t>>h;
		for(int i=0;i<k-h;i++){
			g[a+i*n].push_back({b+(i+h)*n,t});
			g[b+i*n].push_back({a+(i+h)*n,t});
		}
	}
	
	int s,t;cin>>s>>t;
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	priority_queue<node,vector<node> >q;
	q.push({s,0});
	while(!q.empty()){
		node f=q.top();q.pop();
		if(dis[f.idx]==f.dis)
			for(register edge x:g[f.idx])
				if(dis[x.v]>dis[f.idx]+x.w)
					dis[x.v]=dis[f.idx]+x.w,
					q.push({x.v,dis[x.v]});
	}
	
	int ans=0x3f3f3f3f;
	for(int i=t;i<=t+(k-1)*n;i+=n){
		ans=min(ans,dis[i]);
//		cout<<dis[i]<<endl;
	}
	cout<<ans<<endl;
	
	return 0;
}
