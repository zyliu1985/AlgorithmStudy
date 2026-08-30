#include<bits/stdc++.h>
using namespace std;
struct dic{
	int to,time;
};
int vis[2005];
int main(){
	int k,n,m;
	cin>>k>>n>>m;
	vector<dic> v[2005];
	if(k==1){
		int a,b,t,h;
		for(int i=0;i<m;i++){
			cin>>a>>b>>t>>h;
			if(h==0){
				dic tmp;
				tmp.time=t;
				tmp.to=b;
				v[a].push_back(tmp);
				tmp.to=a;
				v[b].push_back(tmp);
			}
		}
		int st,en;
		cin>>st>>en;
		queue<dic> q;
		dic tmp;
		tmp.to=st;
		tmp.time=0;
		q.push(tmp);
		int ans=1e9+5;
		while(!q.empty()){
			dic t=q.front();
			if(t.to==en){
				ans=min(ans,t.time);
			}
			for(int i=0;i<v[t.to].size();i++){
				if(t.time+v[t.to][i].time<vis[v[t.to][i].to]){
					vis[v[t.to][i].to]=t.time+v[t.to][i].time;
					dic tmp;
					tmp.to=v[t.to][i].to;
					tmp.time=vis[v[t.to][i].to];
					q.push(tmp);
				}
				if(vis[v[t.to][i].to]==0){
					vis[v[t.to][i].to]=t.time+v[t.to][i].time;
					dic tmp;
					tmp.to=v[t.to][i].to;
					tmp.time=vis[v[t.to][i].to];
					q.push(tmp);
				}
			}
			q.pop();
		}
		cout<<ans;
	}
	return 0;
}

