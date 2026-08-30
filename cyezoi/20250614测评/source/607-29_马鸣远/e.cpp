#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge{
	ll to,t,h,nxt;
}e[20005];
struct node{
	ll u,k,t;
	bool operator>(const node &x)const{
		return t>x.t;
	}
};
ll k,n,m,a,b,t,h,hd[2005],nE,A,B,dst[2005][205],ans=1e18;
priority_queue<node,vector<node>,greater<node> > q;
void add(ll u,ll v,ll t,ll h){
	e[++nE]=(edge){v,t,h,hd[u]};
	hd[u]=nE;
}
void Dijkstra(){
	fill(dst[0],dst[0]+2005*205,1e18);
	q.push((node){A,k,0});
	dst[A][k]=0;
	while(!q.empty()){
		node now=q.top();
		q.pop();
		for(ll i=hd[now.u];i;i=e[i].nxt){
			ll v=e[i].to,t=e[i].t,h=e[i].h;
			ll dt=now.t+t,dk=now.k-h;
			if(dst[v][dk]!=1e18){
				continue;
			}
			if(dk<=0){
				continue;
			}
			q.push((node){v,dk,dt});
			dst[v][dk]=dt;
		}
	}
}
int main(){
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
	cin>>k>>n>>m;
	for(ll i=1;i<=m;i++){
		cin>>a>>b>>t>>h;
		add(a,b,t,h);
		add(b,a,t,h);
	}
	cin>>A>>B;
	Dijkstra();
	for(ll i=1;i<=k;i++){
		ans=min(ans,dst[B][i]);
	}
	if(ans==1e18){
		cout<<-1;
	}
	else{
		cout<<ans;
	}
	return 0;
}

