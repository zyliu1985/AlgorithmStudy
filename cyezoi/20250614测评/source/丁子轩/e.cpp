#include<bits/stdc++.h>
using namespace std;
#define int long long
int k,n,m;
int dp[210][2010];
struct Node{
	int v,t,h,next;
}node[20010];
int tot=0,h[2010];
void build(int u,int v,int t,int hl){
	tot++;
	node[tot]={v,t,hl,h[u]};
	h[u]=tot;
}
signed main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	cin>>k>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b,t,h;
		cin>>a>>b>>t>>h;
		build(a,b,t,h);
		build(b,a,t,h);
	}
	int a,b;
	cin>>a>>b;
	memset(dp,0x3f,sizeof(dp));
	dp[0][a]=0;
	//dp[0][b]=0;
	set<pair<int,pair<int,int> > >st;
	st.insert({0,{0,a}});
	//st.insert({0,{0,b}});
	while(!st.empty()){
		auto it=st.begin();
		int ua=(*it).second.first;
		int ub=(*it).second.second;
		st.erase(it);
		for(int i=h[ub];i;i=node[i].next){
			if(dp[ua][ub]+node[i].t<dp[ua+node[i].h][node[i].v]&&ua+node[i].h<k){
				st.erase({dp[ua+node[i].h][node[i].v],{ua+node[i].h,node[i].v}});
				dp[ua+node[i].h][node[i].v]=dp[ua][ub]+node[i].t;
				st.insert({dp[ua+node[i].h][node[i].v],{ua+node[i].h,node[i].v}});
			}
		}
	}
	int ans=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<k;i++){
		ans=min(ans,dp[i][b]);
	}
	if(ans==0x3f3f3f3f3f3f3f3f){
		cout<<-1;
		return 0;
	}
	cout<<ans;
	/*
	cout<<ans<<'\n';
	for(int i=0;i<k;i++){
		for(int j=1;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<'\n';
	}*/
}
