#include<bits/stdc++.h>
using namespace std;
int k,n,m,s,e,ans=INT_MAX;
int d[100010],vis[100010];
int hh[100010],tt[100010];
struct node{
	int to,t,h;
	bool operator < (const node x) const {
	    return x.t<t;
	}
};
vector<node> a[100010];

void bfs(int s,int e){
	queue<node> q;
	q.push((node){s,0,0});
	for(int i=1;i<=n;i++){
		hh[i]=INT_MAX;
		tt[i]=INT_MAX;
	}
	while(!q.empty()){
		node r=q.front();
		q.pop();
		//cout<<r.to<<' '<<r.t<<endl;
		while(r.h>=k){
			if(q.empty())return;
			r=q.front();
			q.pop();
		}
		while(r.to==e && r.h<k){
			ans=min(r.t,ans);
			if(q.empty())return;
			r=q.front();
			q.pop();
		}
		while(r.h>=k){
			if(q.empty())return;
			r=q.front();
			q.pop();
		}
		for(int i=0;i<a[r.to].size();i++){
			if(vis[a[r.to][i].to]==0 || r.h+a[r.to][i].h<hh[a[r.to][i].to] || r.t+a[r.to][i].t<tt[a[r.to][i].to]){
				vis[a[r.to][i].to]=1;
				hh[a[r.to][i].to]=min(hh[a[r.to][i].to],r.h+a[r.to][i].h);
				tt[a[r.to][i].to]=min(r.t+a[r.to][i].t,tt[a[r.to][i].to]);
				q.push((node){a[r.to][i].to,r.t+a[r.to][i].t,r.h+a[r.to][i].h});
			}
		}
	}
}

int main(){
	cin>>k>>n>>m;
	for(int i=1,x,y,z,p;i<=m;i++){
		cin>>x>>y>>z>>p;
		a[x].push_back((node){y,z,p});
		a[y].push_back((node){x,z,p});
	}
	cin>>s>>e;
	bfs(s,e);
	if(ans!=INT_MAX)cout<<ans;
	else cout<<"-1";
}
