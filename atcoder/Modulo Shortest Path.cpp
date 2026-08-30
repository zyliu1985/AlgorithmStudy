#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int a[200005];
struct node{
	int val, id;
} b[200005];
bool cmp(node x, node y){
	return x.val < y.val;
}
vector<int> v[400005], w[400005];
long long dis[400005];
bool vis[400005];
struct qnode{
	int x;
	long long d;
	friend bool operator < (const qnode x, const qnode y){
		return x.d > y.d;
	}
};
priority_queue<qnode> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i].val, b[i].id = i;
	sort(b+1, b+n+1, cmp);
	for (int i = 1; i <= n; i++){
		int t = lower_bound(b+1, b+n+1, node{m - a[i], 0}, cmp) - b;
//		cout << i << ':' << b[t].id << '\n';
		v[i].push_back(b[1].id + n);
		w[i].push_back(a[i] + b[1].val);
		if (t > n) continue;
		v[i].push_back(b[t].id + n);
		w[i].push_back(a[i] + b[t].val - m);
	}
	for (int i = 1; i <= n; i++){
		v[b[i].id + n].push_back(b[i].id);
		w[b[i].id + n].push_back(0);
		if (i < n){
			v[b[i].id + n].push_back(b[i+1].id + n);
			w[b[i].id + n].push_back(b[i+1].val - b[i].val);
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	q.push({1, 0});
	while (!q.empty()){
		int x = q.top().x;
		q.pop();
		if (vis[x]) continue;
		vis[x] = true;
//		cout << x << ',' << dis[x] << " -> ";
		for (int i = 0; i < v[x].size(); i++)
			if (dis[v[x][i]] > dis[x] + w[x][i]){
				dis[v[x][i]] = dis[x] + w[x][i];
//				cout << v[x][i] << ", ";
				q.push({v[x][i], dis[v[x][i]]});
			}
//		cout << '\n';
	}
	cout << dis[n] << '\n';
	return 0;
}

