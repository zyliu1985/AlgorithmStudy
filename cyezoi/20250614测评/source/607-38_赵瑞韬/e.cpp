#include<bits/stdc++.h>
int k,n,m,A,B;
struct edge{
	int to,w,nxt;
}e[440000];
int hd[440000],nE;
int dst[440000],ans=0x30000000;
bool vst[440000];
void addedge(int a,int b,int t){
	e[++nE]=(edge){b,t,hd[a]};
	hd[a]=nE;
}
void dfs(){
	std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int> >,std::greater<std::pair<int,int> > >q;
	memset(dst,0x1f,sizeof dst);
	q.push(std::make_pair(0,A));dst[A]=0;
	while(!q.empty()){
		std::pair<int,int>x=q.top();q.pop();
		if(vst[x.second])continue;
		vst[x.second]=1;
		if(k==1&&x.second==B)break;
		for(int i=hd[x.second];i;i=e[i].nxt){
			if(dst[e[i].to]>x.first+e[i].w){
				dst[e[i].to]=x.first+e[i].w;
				q.push(std::make_pair(dst[e[i].to],e[i].to));
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&k,&n,&m);
	for(int i=1,a,b,t,h;i<=m;i++){
		scanf("%d%d%d%d",&a,&b,&t,&h);
		if(h>=k)continue;
		for(int x=0;x<k-h;x++)
			addedge(x*n+a,(x+h)*n+b,t),addedge(x*n+b,(x+h)*n+a,t);
	}
	scanf("%d%d",&A,&B);
	dfs();
	for(int i=k-1;i>=0;i--)
		ans=std::min(ans,dst[i*n+B]);
	if(ans>0x1f)puts("-1");
	else printf("%d",ans);
	return 0;
}
