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
int dis[10005];
int n, m, s;
bool vis[10005];
vector<node2> v[10005];
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
inline int read(){
	int re = 0, type = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') type = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		re = (re << 1) + (re << 3) + (c - '0');
//		cout << (re << 1 + re << 3 + (c - '0')) << endl;
		c = getchar();
	}
	return re * type;
}
int cc[10005];
int main(){
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	cout.tie(0);
	n = read(), m = read();
	int t = read();
	for (int i = 1; i <= n; i++)
		cc[i] = read();
	for (int i = 1; i <= m; i++){
		int x, y, w;
		x = read();
		y = read();
		w = read();
		v[x].push_back({y, w});
		v[y].push_back({x, w});
	}
	s = 1;
	dij();
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans += cc[i] * dis[i];
	cout << ans << endl;
	return 0;
}
