#include<bits/stdc++.h>
using namespace std;
int ans[2005],k,n,m,fi;
struct Node{
	int x,t;
	bool operator<(const Node &B) const{
		return t>B.t;
	}
};
struct Edge{
	int to,w;
};
vector<Edge> g[2005]; 
void dij(int s){
	priority_queue<Node> q;
	q.push({s,0});
	ans[s]=0;
	while(!q.empty()){
		int x=q.top().x,t=q.top().t;
		q.pop();
		if(t>ans[x])	continue;
		for(auto y:g[x]){
			int to=y.to,w=y.w;
			if(t+w<ans[to]){
				ans[to]=t+w;
				q.push({to,t+w});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(ans,0x3f,sizeof(ans));
	cin>>k>>n>>m;
	while(m--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(d==0){
			g[a].push_back({b,c});
			g[b].push_back({a,c});
		}
	}
	int s;
	cin>>s>>fi;
	dij(s);
	if(ans[fi]>1e9)	cout<<-1;
	else cout<<ans[fi];
	return 0;
}

