#include<bits/stdc++.h>
using namespace std;
int n,m,k,c,d,ans=INT_MAX;
struct str{
	int a[2005],t[2005],h[2005],cnt;
}s[2005];
struct strr{
	int aa;
	int hh;
	int tt;
	int vis[2005];
};
void bfs(int x,int y){
	queue<strr> que;
	que.push({x,0,0});
	while(!que.empty()){
		strr t;
		t=que.front();
		que.pop();
		for(int i=1;i<=s[t.aa].cnt;i++){
			int nx=s[t.aa].a[i];
			int nt=s[t.aa].t[i];
			int nh=s[t.aa].h[i];
			if(t.vis[nx]==-1||t.tt+nt>=ans||t.hh+nh>=k)continue;
			if(nx==d){
				ans=min(ans,nt+t.tt);
			}
			t.vis[nx]=-1;
			strr ttt;
			ttt.aa=nx;
			ttt.hh=nh+t.hh;
			ttt.tt=t.tt+nt;
			for(int i=1;i<=n;i++){
				ttt.vis[i]=t.vis[i];
			}
			que.push(ttt);
		}
	}
}
int main(){
	cin>>k>>n>>m;
	for(int i=1;i<=m;i++){
		int x,xx,y,yy;
		cin>>x>>y>>xx>>yy;
		s[x].cnt++;
		s[y].cnt++;
		s[x].a[s[x].cnt]=y;
		s[y].a[s[y].cnt]=x;
		s[x].t[s[x].cnt]=xx;
		s[y].t[s[y].cnt]=xx;
		s[x].h[s[x].cnt]=yy;
		s[y].h[s[y].cnt]=yy;
	}
	cin>>c>>d;
	if(s[d].cnt<1){
		cout<<-1;
		return 0;
	}
	bfs(c,d);
	if(ans==INT_MAX)cout<<-1;
	else cout<<ans;
}
