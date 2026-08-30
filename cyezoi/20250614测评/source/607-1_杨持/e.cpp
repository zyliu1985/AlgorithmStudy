#include<bits/stdc++.h>
#define N 20010
using namespace std;
typedef pair<int,int> pii;
struct edge{
	int v,t,h,next;
}e[N];
int k,n,m;
int a,b;
int head[N],cnt;
int ans[N];
inline void merge(int u,int v,int t,int h){
	cnt++;
	e[cnt]={v,t,h,head[u]};
	head[u]=cnt;
}
void dfs(int u,int nt,int nh){
	if(nh>=k)return;
	if(nt>ans[u])return;
	ans[u]=min(ans[u],nt);
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].v,t=e[i].t,h=e[i].h;
		dfs(v,nt+t,nh+h);
	}
}
signed main(){
	memset(ans,0x7f,sizeof(ans));
	scanf("%d %d %d",&k,&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,t,h;
		scanf("%d %d %d %d",&u,&v,&t,&h);
		merge(u,v,t,h);
		merge(v,u,t,h);
	}
	scanf("%d %d",&a,&b);
	dfs(a,0,0);
	printf("%d",ans[b]);
}

