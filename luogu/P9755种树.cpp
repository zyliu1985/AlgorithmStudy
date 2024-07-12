#include<bits/stdc++.h>
using namespace std;

int n;
long long a[100005];
int b[100005], c[100005], f[100005];
bool vis[100005];
long long tim;
struct node{
	int id;
	long long val;	
} t[100005];
vector<int> v[100005];
bool cmp(node x, node y){
	return x.val < y.val;
}
void dfs(int x, int fa){
	f[x] = fa;
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa)
			dfs(v[x][i], x);
}
__int128 func(__int128 l, __int128 r, int x){
	if (c[x] >= 0) return b[x] * (r - l + 1) + c[x] * (l + r) * (r - l + 1) / 2;
	int imax = (1 - b[x]) / c[x];
	if (imax < l) return r - l + 1;
	if (imax >= r) return b[x] * (r - l + 1) + c[x] * (l + r) * (r - l + 1) / 2;
	return b[x] * (imax - l + 1) + c[x] * (l + imax) * (imax - l + 1) / 2 + r - imax;
}
bool check(int mid){
	tim = 0;
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n; i++){
		if (func(1, mid, i) < a[i]) return false;
		// 第二次二分答案 
		int l = 1, r = n;
		while (l < r){
			int half = (l + r + 1) / 2;
			if (func(half, mid, i) >= a[i]) l = half;
			else r = half - 1;
		}
		t[i].id = i;
		t[i].val = l;
	}
	sort(t+1, t+n+1, cmp);
	for (int i = 1; i <= n; i++){
		if (vis[t[i].id]) continue;
		int now = t[i].id;
		while (!vis[now]) tim++, vis[now] = true, now = f[now];
		if (t[i].val < tim) return false; 
	}
	return true;
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i] >> c[i];
	for (int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x); 
	}
	dfs(1, 1);
	// 第一次二分答案
	int l = n+1, r = 1e9; 
	while (l < r){
		int mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl; 
	return 0;
}