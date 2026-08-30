#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cur;
int n, m, q;
vector<int> v[10005], w[10005];
int dfn[10005], low[10005], rnxt[10005], nxtl[10005];
bool vis[10005];
int fa[10005][15], depth[10005], ringid[10005], rid;
bool ringdir[10005];
long long ln[10005], ringlen[10005], slen[10005];
vector<int> ch[10005];
// 处理dfn，low，rnxt，nxtl 
void init1(int x, int fa){
	dfn[x] = low[x] = ++cur;
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == fa) continue;
		if (!dfn[v[x][i]]){
			init1(v[x][i], x);
			low[x] = min(low[x], low[v[x][i]]);
			if (low[v[x][i]] < dfn[x]) rnxt[x] = v[x][i], nxtl[x] = w[x][i];
		} else if (dfn[v[x][i]] < dfn[x]){
			low[x] = min(low[x], dfn[v[x][i]]);
			nxtl[x] = w[x][i];
		}
	}
}

// 处理fa，len，ringlen，ringid，ringdir，ch 
int temp[10005];
void init2(int x){
	vis[x] = true;
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i] == rnxt[x]) continue; 
		if (vis[v[x][i]]) continue;
		init2(v[x][i]);
		if (low[v[x][i]] > dfn[x]){
			// 树边 
			fa[v[x][i]][0] = x;
			ln[v[x][i]] = w[x][i];
			ch[x].push_back(v[x][i]);
		} else {
			// 环 
			int now = v[x][i], len = 1;
			long long nl = w[x][i];
			temp[1] = x;
			while (now){
				fa[now][0] = x;
				ch[x].push_back(now); 
				ln[now] = nl;
				temp[++len] = now;
				nl += nxtl[now];
				now = rnxt[now];
			}
			rid++;
			for (int i = 2; i <= len; i++){
				ringlen[temp[i]] = nl;
				ringid[temp[i]] = rid;
				if (nl - ln[temp[i]] < ln[temp[i]]){
					ringdir[temp[i]] = 1;
					ln[temp[i]] = nl - ln[temp[i]];
				}
			}
		}
	}
	if (rnxt[x]) init2(rnxt[x]);
}

// 处理slen，depth 
void init3(int x){
	for (int i = 0; i < ch[x].size(); i++){
		slen[ch[x][i]] += slen[x] + ln[ch[x][i]];
		depth[ch[x][i]] = depth[x] + 1;
		init3(ch[x][i]);
	}
}

// 处理lca所需的fa 
void init4(){
	for (int i = 1; i <= 14; i++)
		for (int j = 1; j <= n; j++)
			fa[j][i] = fa[fa[j][i-1]][i-1];
}

pair<int, int> lca(int x, int y){
	if (depth[x] < depth[y]) swap(x, y);
//	cout << depth[x] << ' ' << depth[y] << '\n';
	int dd = depth[x] - depth[y];
	int now = 0;
	while (dd > 0){
		if (dd & 1){
			x = fa[x][now];
		}
		dd >>= 1;
		now++;
	}
//	cout << x << ' ' << y << '\n';
	for (int i = 14; i >= 0; i--)
		if (fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	return make_pair(x, y);
}
int main(){
//	freopen("out.out",  "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++){
		int a, b, l;
		cin >> a >> b >> l;
		v[a].push_back(b);
		v[b].push_back(a);
		w[a].push_back(l);
		w[b].push_back(l);
	}
	init1(1, 0);
	init2(1);
	init3(1);
	init4();
	while (q--){
		int a, b;
		cin >> a >> b;
		pair<int, int> p = lca(a, b);
		long long org = slen[a] - slen[p.first] + slen[b] - slen[p.second];
//		cout << org << ',' << p.first << ',' << p.second << '\n';
		if (p.first == p.second){
//			cout << "case1\n";
			cout << org << '\n';
		} else if (ringid[p.first] == ringid[p.second] && ringid[p.first] != 0) {
			if (ringdir[p.first] == ringdir[p.second]){
//				cout << "case2 " << ringid[p.first] << ',' << ln[p.first] << ',' << ln[p.second] << '\n';
				if (ln[p.first] > ln[p.second]){
					cout << org + ln[p.first] - ln[p.second] << '\n';
				} else {
					cout << org + ln[p.second] - ln[p.first] << '\n';
				}
//				cout << org + min(ln[p.first] + ln[p.second], ringlen[p.first] - ln[p.first] - ln[p.second]) << '\n';
//				cout << org + ln[p.first] + ln[p.second] << '\n';
			} else {
//				cout << "case3\n";
				cout << org + min(ln[p.first] + ln[p.second], ringlen[p.first] - ln[p.first] - ln[p.second]) << '\n';
			} 
		} else {
//			cout << "case4\n";
			cout << org + ln[p.first] + ln[p.second] << '\n';
		}
	}
//	for (int i = 1; i <= n; i++)
//		cout << i << ':' << fa[i][0] << ',' << ln[i] << ',' << ringlen[i] << ',' << ringid[i] << ',' << ringdir[i] << ',' << depth[i] << '\n';
	return 0;
}

