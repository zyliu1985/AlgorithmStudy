#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,a,b,t,h,d[2009][209],ans=2147000000;
bool vst[2009][209],inq[2009][209];
struct Edge{
	int v,h,t;
	bool operator<(const Edge &b)const{
		return d[v][h]>d[b.v][b.h];
	}
};
vector<Edge> es[2009][209];
priority_queue<Edge> pq;
void dijkstra(int st){
	pq.push((Edge){st,0,0});
	d[st][0]=0;
	while(!pq.empty()){
		Edge now=pq.top(),v;
		pq.pop();
		vst[now.v][now.h]=1;
		//cout<<now.v<<'-'<<now.h<<'\n';
		for(int i=0;i<es[now.v][now.h].size();i++){
			v=es[now.v][now.h][i];
			if(vst[v.v][v.h]) continue;
			d[v.v][v.h]=min(d[v.v][v.h],d[now.v][now.h]+v.t);
			if(!inq[v.v][v.h]){
				//cout<<v.v<<'+'<<v.h<<'\n';
				pq.push(v);
			}
			inq[v.v][v.h]=1;
		}
	}
}
int main(){
	cin>>k>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>t>>h;
		for(int j=0;j<k-h;j++){
			es[a][j].push_back((Edge){b,j+h,t});
			es[b][j].push_back((Edge){a,j+h,t});
			//cout<<a<<'='<<b<<'('<<j<<','<<j+h<<")\n";
		}
	}
	for(int i=1;i<=n;i++) for(int j=0;j<=k;j++) d[i][j]=2147000000;
	cin>>a>>b;
	dijkstra(a);
	//for(int i=1;i<=n;i++) for(int j=0;j<=k;j++) cout<<i<<' '<<j<<' '<<d[i][j]<<'\n';
	for(int i=1;i<k;i++) ans=min(ans,d[b][i]);
	cout<<ans;
	return 0;
}

