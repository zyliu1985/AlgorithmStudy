#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int n, m;
vector<int> v[10005], w[10005];
int qu[105], sz[10005], dist[10005];
bool ans[105], vis[10005], markdist[10000005];
stack<int> st;
int calc_size(int x, int fa){
	sz[x] = 1; 
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa && !vis[v[x][i]]) sz[x] += calc_size(v[x][i], x);
	return sz[x];
}
int calc_centre(int x, int fa, int rt){
	if (sz[rt] - sz[x] > sz[rt] / 2) return -1;
	bool flag = true;
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa && !vis[v[x][i]] && sz[v[x][i]] > sz[rt] / 2){
			flag = false;
			break;
		}
	if (flag) return x;
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa && !vis[v[x][i]]){
			int re = calc_centre(v[x][i], x, rt);
			if (re != -1) return re;
		}
	return -1;
}
void calc_dist(int x, int fa){
	if (dist[x] > 1e7) return;
	for (int i = 1; i <= m; i++){
		if (qu[i] < dist[x]) continue;
		if (qu[i] == dist[x] || markdist[qu[i] - dist[x]]){
			ans[i] = true;
		}
	}
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa && !vis[v[x][i]]){
			dist[v[x][i]] = dist[x] + w[x][i];
			calc_dist(v[x][i], x);
		}
}
void mark(int x, int fa){
	if (dist[x] > 1e7) return;
	st.push(dist[x]);
	markdist[dist[x]] = true;
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa && !vis[v[x][i]]) mark(v[x][i], x);
}
void solve(int x){
	calc_size(x, 0);
	int rt = calc_centre(x, 0, x);
	for (int i = 0; i < v[rt].size(); i++){
		if (vis[v[rt][i]]) continue;
		dist[v[rt][i]] = w[rt][i];
		calc_dist(v[rt][i], rt);
		mark(v[rt][i], rt);
	}
	while (!st.empty()) markdist[st.top()] = false, st.pop();
	vis[rt] = true;
	for (int i = 0; i < v[rt].size(); i++){
		if (vis[v[rt][i]]) continue;
		solve(v[rt][i]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i < n; i++){
		int a, b, t;
		cin >> a >> b >> t; 
		v[a].push_back(b);
		v[b].push_back(a);
		w[a].push_back(t);
		w[b].push_back(t);
	}
	for (int i = 1; i <= m; i++)
		cin >> qu[i];
	solve(1);
	for (int i = 1; i <= m; i++)
		if (ans[i]){
			cout << "AYE\n";
		} else {
			cout << "NAY\n";
		}
	return 0;
}

