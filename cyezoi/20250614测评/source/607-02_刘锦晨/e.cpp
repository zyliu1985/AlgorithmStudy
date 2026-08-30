#include <iostream>
#include <cstring> 
#include <queue>
#include <vector>
using namespace std;

int n, m, k;
vector<int> v[2005], t[2005], h[2005];
int dis[2005][205];
struct node{
	int x, y, d;
	friend bool operator < (const node x, const node y){
		return x.d > y.d;
	}
};
priority_queue<node> q;
int dij(int st, int ed){
	memset(dis, 0x3f, sizeof(dis));
	dis[st][k] = 0;
	q.push(node{st, k, 0});
	while (!q.empty()){
		int x = q.top().x, y = q.top().y;
		q.pop();
		if (x == ed) return dis[x][y];
		for (int i = 0; i < v[x].size(); i++)
			if (y > h[x][i] && dis[v[x][i]][y - h[x][i]] > dis[x][y] + t[x][i]){
				dis[v[x][i]][y - h[x][i]] = dis[x][y] + t[x][i];
				q.push(node{v[x][i], y - h[x][i], dis[v[x][i]][y - h[x][i]]});
			}
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> k >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y, tt, hh;
		cin >> x >> y >> tt >> hh;
		v[x].push_back(y);
		v[y].push_back(x);
		h[x].push_back(hh);
		h[y].push_back(hh);
		t[x].push_back(tt);
		t[y].push_back(tt);
	}
	int a, b;
	cin >> a >> b;
	cout << dij(a, b) << '\n'; // dij
	return 0;
}
