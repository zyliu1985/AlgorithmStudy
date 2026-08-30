#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct node{
	int x, w;
};
struct q_node{
	int x;
	long long d;
	friend bool operator < (const q_node x, const q_node y){
		return x.d > y.d;
	}
};
vector<node> v[400005];
long long dis[400005];
priority_queue<q_node> q;
void dij(){
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	q.push({1, 0});
	while (!q.empty()){
		int x = q.top().x;
		q.pop();
		for (int i = 0; i < v[x].size(); i++)
			if (dis[v[x][i].x] > dis[x] + v[x][i].w){
				dis[v[x][i].x] = dis[x] + v[x][i].w;
				q.push({v[x][i].x, dis[v[x][i].x]});
			}
	}
}
int main(){
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 1; i <= n; i++){
		v[i].push_back({i + n, x});
		v[i + n].push_back({i, x});
	}
	for (int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back({b, 1});
		v[b + n].push_back({a + n, 1});
	}
	dij();
	cout << min(dis[n], dis[n << 1]) << '\n'; 
	return 0;
}


