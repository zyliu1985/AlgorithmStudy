#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node{
	int i, val;
} dis[100005];
bool vis[100005];
vector<int> v[100005];
queue<int> q;
bool cmp(node x, node y){
	if (x.val != y.val)
		return x.val < y.val;
	else
		return x.i < y.i;
}
void bfs(int s){
	q.push(s);
	vis[s] = true;
	dis[s].val = 0;
	while (!q.empty()){
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++)
			if (!vis[v[x][i]]){
				q.push(v[x][i]);
				vis[v[x][i]] = true;
				dis[v[x][i]].val = dis[x].val+1;
			}
	}
}
int main(){
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) dis[i].i = i;
	bfs(x);
	for (int i = 1; i <= n; i++)
		if (i != x && dis[i].val == 0) dis[i].val = 1e9;
	sort(dis+1, dis+n+1, cmp);
	int last = 0;
	for (int i = 1; i <= n; i++){
		if (dis[i].val != last){
			last = dis[i].val;
			cout << endl;
		}
		cout << dis[i].i << ' ';
	}
	return 0;
}