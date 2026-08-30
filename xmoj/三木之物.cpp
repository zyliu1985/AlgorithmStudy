#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<int> v[100005];
long long a[100005];
int fa[100005], gfa[100005];
set<int> ch[100005], gch[100005];
void dfs(int x){
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != fa[x]){
			fa[v[x][i]] = x;
			dfs(v[x][i]);
		}
}
void del(int x){
//	cout << "get "<< x << ", a[x] = " << a[x] << '\n';
	a[x] = 0;
	if (fa[x]) ch[fa[x]].erase(x);
	if (gfa[x]) gch[gfa[x]].erase(x);
}
void add(int x){
	if (fa[x]) ch[fa[x]].insert(x);
	if (gfa[x]) gch[gfa[x]].insert(x);
}
int clear[100005], cur;
int main(){
	freopen("three.in", "r", stdin);
	freopen("three.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		a++, b++;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1);
	for (int i = 1; i <= n; i++){
		gfa[i] = fa[fa[i]];
		if (fa[i] && a[i] > 0) ch[fa[i]].insert(i);
		if (gfa[i] && a[i] > 0) gch[gfa[i]].insert(i);
	}
	int q;
	cin >> q;
	while (q--){
		long long S = 0;
		int x;
		cin >> x;
		x++;
		if (fa[x] && a[fa[x]]) S += a[fa[x]], del(fa[x]);
		if (gfa[x] && a[gfa[x]]) S += a[gfa[x]], del(gfa[x]);
		cur = 0;
		for (int y : ch[x]){
			clear[++cur] = y;
		}
		for (int y : gch[x]){
			clear[++cur] = y;
		}
		if (fa[x]){
			for (int y : ch[fa[x]]){
				clear[++cur] = y;
			}
		} else {
			clear[++cur] = x;
		}
		for (int i = 1; i <= cur; i++)
			S += a[clear[i]], del(clear[i]);
		a[x] = S; 
		if (S) add(x);
		cout << S << '\n';
	}
	return 0;
}

