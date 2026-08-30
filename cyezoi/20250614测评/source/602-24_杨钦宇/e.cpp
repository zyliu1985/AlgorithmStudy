#include<bits/stdc++.h>
using namespace std;
struct NODE{
	int v,d;
	bool operator<(const NODE& a)const{
		return d>a.d;
	}
};
int K,N,M,A,B,a[10001],b[10001],t[10001],h[10001],dis[402001],vis[402001],ans=2147483647;
vector<pair<int,int>>g[402001];
int main(){
	//freopen("e.in","r",stdin);
	cin>>K>>N>>M;
	for(int i=1;i<=M;i++)cin>>a[i]>>b[i]>>t[i]>>h[i];
	cin>>A>>B;
	for(int i=1;i<=K;i++){
		for(int j=1;j<=M;j++){
			if(i<=h[j])continue;
			g[a[j]+i*N].push_back(make_pair(b[j]+(i-h[j])*N,t[j]));
			g[b[j]+i*N].push_back(make_pair(a[j]+(i-h[j])*N,t[j]));
		}
	}
	for(int i=1;i<=N*K+N;i++)dis[i]=2147483647;
	priority_queue<NODE>q;
	q.push(NODE{A+K*N,0});
	while(!q.empty()){
		int u=q.top().v,d=q.top().d;
		q.pop();
		if(vis[u])continue;
		vis[u]=1,dis[u]=d;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first,dd=g[u][i].second;
			if(vis[v])continue;
			q.push(NODE{v,dd+d});
		}
	}
	for(int i=1;i<=K;i++){
		ans=min(ans,dis[i*N+B]);
	}
	cout<<ans;
	return 0;
}

