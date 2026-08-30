#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 10010;
int dis[N], cnt, head[N];
int k, n, m, Start, End;
bool vis[N];
struct node{
	int to, dis, next;
};
node e[N];
void add(int u, int v, int w){
	cnt++;
	e[cnt].dis = w;
	e[cnt].to = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}
struct edge{
	int dis, pos;
	bool operator <(const edge &x) const{
		return x.dis < dis;
	}
};
priority_queue<edge> pq;
void dijkstra(){
	dis[Start] = 0;
	pq.push((edge){0, Start});
	while(!pq.empty()){
		edge tmp = pq.top();
		pq.pop();
		int x = tmp.pos;
		if(vis[x])
			continue;
		vis[x] = 1;
		for(int i = head[x]; i; i = e[i].next){
			int y = e[i].to;
			if(dis[y] > dis[x] + e[i].dis){
				dis[y] = dis[x] + e[i].dis;
				if(!vis[y])
					pq.push((edge){dis[y], y});
			}
		}
	}
}
signed main(){
	cin >> k >> n >> m;
	for(int i = 1; i <= n; i++)
		dis[i] = LONG_LONG_MAX;
	for(int i = 1; i <= m; i++){
		int a, b, t, h;
		cin >> a >> b >> t >> h;
		if(h <= 0){
			add(a, b, t);
			add(b, a, t);
		}
	}
	cin >> Start >> End;
	dijkstra();
	if(dis[End] != LONG_LONG_MAX)
		cout << dis[End];
	else
		cout << "-1";
	cout << '\n';
	return 0;
}
