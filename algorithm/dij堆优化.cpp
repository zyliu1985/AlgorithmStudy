#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
	int x, d;
	friend bool operator > (const node a, const node b){
		return a.d > b.d;
	}
};
struct node2{
	int x, w;
};
int dis[100005];
int n, m, s;
bool vis[100005];
vector<node2> v[100005];
priority_queue<node, vector<node>, greater<node> > q;
void dij(){
	for (int i = 0; i <= n; i++) dis[i] = 2147483647;
	dis[s] = 0;
	q.push({s, 0});
	while (!q.empty()){
		node x = q.top();
		q.pop();
		if (vis[x.x]) continue;
		vis[x.x] = true;
		for (int i = 0; i < v[x.x].size(); i++){
			if (dis[v[x.x][i].x] > x.d + v[x.x][i].w){
				dis[v[x.x][i].x] = x.d + v[x.x][i].w;
				q.push({v[x.x][i].x, dis[v[x.x][i].x]});
			}
		}
	}
}
int main(){
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		v[a].push_back({b, w});
	}
	dij();
	for (int i = 1; i <= n; i++)
		cout << dis[i] << ' ';
	return 0;
}