#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int maxn=2e3+3;
struct node{
	int v,w1,w2;
};
vector<node> g[maxn];
int steps[maxn][203],k,a,b;
bool vis[maxn];
queue<int> q;
void spfa(){
	memset(steps,0x3f,sizeof(steps));
	for(int i=0;i<=k;i++)steps[a][i]=0;
	q.push(a);
	while(!q.empty()){
		int tmp=q.front();
		q.pop();
		vis[tmp]=false;
		for(int i=0;i<g[tmp].size();i++){
			node nxt=g[tmp][i];
			bool flag=false;
			for(int j=nxt.w2;j<k;j++){
				if(steps[tmp][j-nxt.w2]+nxt.w1<steps[nxt.v][j]){
					steps[nxt.v][j]=steps[tmp][j-nxt.w2]+nxt.w1;
					flag=true;
				}
			}
			if(!vis[nxt.v] && flag){
				vis[nxt.v]=true;
				q.push(nxt.v);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("data.in","r",stdin);
	freopen("ans.out","w",stdout);
	int n,m;
	cin>>k>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w1,w2;
		cin>>u>>v>>w1>>w2;
		g[u].push_back({v,w1,w2});
		g[v].push_back({u,w1,w2});
	}
	cin>>a>>b;
	spfa();
	int ans=1e9;
	for(int i=0;i<k;i++){
		ans=min(ans,steps[b][i]);
	}
	cout<<ans;
	return 0;
}
/*
10 4 7
1 2 4 4
1 3 7 2
3 1 8 1
3 2 2 2
4 2 1 6
3 4 1 1
1 4 6 12
1 4
*/
