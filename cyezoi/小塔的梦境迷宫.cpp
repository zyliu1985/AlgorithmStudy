#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct node{
	int x, w;
};
struct q_node{
	int x, c, d;
	friend bool operator < (const q_node a, const q_node b){
		return a.d > b.d;
	} 
};
priority_queue<q_node> q;
vector<node> v[200005];
long long dis[3][200005];
int n, m, X;
void dij(){
	dis[0][1] = 0;
	q.push({1, 0, 0});
	while (!q.empty()){
		int x = q.top().x, c = q.top().c;
		q.pop();
		for (int i = 0; i < v[x].size(); i++)
			if (dis[(c + (x <= n)) % 3][v[x][i].x] > dis[c][x] + v[x][i].w){
				dis[(c + (x <= n)) % 3][v[x][i].x] = dis[c][x] + v[x][i].w;
				q.push({v[x][i].x, (c + (x <= n)) % 3, dis[(c + (x <= n)) % 3][v[x][i].x]});
			}
	}
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		cin >> n >> m >> X;
		memset(dis, 0x3f, sizeof(dis));
		for (int i = 1; i <= 2 * n; i++)
			v[i].clear();
		for (int i = 1; i <= n; i++){
			int x;
			cin >> x;
			v[i].push_back({n + x, X});
			v[n + x].push_back({i, 0});
		}
		for (int i = 1; i <= m; i++){
			int fr, to, d;
			cin >> fr >> to >> d;
			v[fr].push_back({to, d});
		}
		dij();
		if (dis[0][n] == 0x3f3f3f3f3f3f3f3f) cout << -1 << '\n'; 
		else cout << dis[0][n] << '\n';
	} 
	return 0;
}



