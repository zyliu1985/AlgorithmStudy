#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
#define priq priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>
using namespace std;
const ll N=2e3+5;
struct line{
	ll v,t,h;
};
ll k,n,m,a,b,d[N],f[N],hi[N];
vector<line> edges[N];
void dij(ll x){
	priq q;
	q.push({0,x});
	d[x]=0;
	while(!q.empty()){
		ll u=q.top().second,dis=q.top().first;
		q.pop();
		for(auto y:edges[u]){
			ll v=y.v,h=y.h;
			if(d[v]>d[u]+h || d[v]==-1){
				d[v]=d[u]+h;
				q.push({d[v],v});
			}
		}
	}
}
void dij2(ll x){
	priq q;
	q.push({0,x});
	f[x]=0;
	while(!q.empty()){
		ll u=q.top().second,dis=q.top().first;
		q.pop();
		for(auto y:edges[u]){
			ll v=y.v,h=y.h,t=y.t;
			if((f[v]>f[u]+t || f[v]==-1) && hi[u]+h<k-d[v]){
				f[v]=f[u]+t;
				hi[v]=hi[u]+h;
				q.push({f[v],v});
			}
		}
	}
}
int main(){
	scanf("%lld%lld%lld",&k,&n,&m);
	for(ll i=1;i<=m;i++){
		ll u,v,t,h;
		scanf("%lld%lld%lld%lld",&u,&v,&t,&h);
		edges[u].push_back({v,t,h});
		edges[v].push_back({u,t,h});
	}
	scanf("%lld%lld",&a,&b);
	memset(d,-1,sizeof(d));
	dij(b);
	if(k<=d[a])return !printf("-1\n");
	memset(f,-1,sizeof(f));
	dij2(a);
	printf("%lld\n",f[b]);
	return 0;
}
