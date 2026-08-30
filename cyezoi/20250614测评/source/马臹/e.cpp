#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
typedef long long ll;
struct To{
	ll to,t,h;
};
ll ans=LLONG_MAX;
std::vector<std::vector<To>>e;
std::vector<bool>vis;
void dfs(ll end,ll u,ll nowt,ll nowh,ll k){
	if(u==end){
		ans=std::min(ans,nowt);
		return;
	}
	vis[u]=true;
	for(ll i=0;i<e[u].size();i++){
		if(!vis[e[u][i].to]&&nowh+e[u][i].h<k){
			dfs(end,e[u][i].to,nowt+e[u][i].t,nowh+e[u][i].h,k);
		}
	}
}
int main(){
	ll k,n,m;
	scanf("%lld%lld%lld",&k,&n,&m);
	e.resize(n+1);
	vis.resize(n+1);
	for(ll i=0;i<m;i++){
		ll u,v,t,h;
		scanf("%lld%lld%lld%lld",&u,&v,&t,&h);
		e[u].push_back({v,t,h});
		e[v].push_back({u,t,h});
	}
	ll a,b;
	scanf("%lld%lld",&a,&b);
	dfs(b,a,0,0,k);
	if(ans==LLONG_MAX){
		printf("-1");
	}
	else{
		printf("%lld",ans);
	}
	return 0;
}
//ʱ�䣺O(m+n^2) �ռ䣺O(m) 
