#include<bits/stdc++.h>
#define INF 1e18
typedef long long ll;
using namespace std;
struct Edge{ ll to,t,d; };
struct State{
	ll n,t,d;
	bool operator>(const State&b)const{
		return t>b.t;
	}
};
ll k,n,m,a,b,ans=INF;
int main(){
	cin>>k>>n>>m;
	vector<vector<Edge>> g(n+1);
	for(ll i=0,u,v,t,d;i<m;i++){
		cin>>u>>v>>t>>d;
		g[u].push_back({v,t,d});
		g[v].push_back({u,t,d});
	}
	cin>>a>>b;
	vector<vector<ll>> dst(n+1,vector<ll>(k,INF));
	priority_queue<State,vector<State>,greater<State>> pq;
	dst[a][0]=0;
	pq.push({a,0,0});
	while(!pq.empty()){
		State s=pq.top(); pq.pop();
		if(s.d>=k) continue;
		for(Edge e:g[s.n]){
			ll v=e.to,t=e.t,d=e.d;
			if(s.d+d<k&&s.t+t<dst[v][s.d+d]){
				dst[v][s.d+d]=s.t+t;
				pq.push({v,s.t+t,s.d+d});
			}
		}
	}
	for(ll i=0;i<k;i++) ans=min(ans,dst[b][i]);
	cout<<(ans==INF?-1ll:ans);
	return 0;
}
