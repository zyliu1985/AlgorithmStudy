#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

inline int read(){
	int re = 0, type = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') type = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		re = (re << 1) + (re << 3) + (c - '0');
		c = getchar();
	}
	return re * type;
}
vector<int> v[200005];
int n, m, a, b;
int sizea[200005], sizeb[200005], childa, childb, atob, btoa;
bool vis[200005], has_aorb;
int dfsa(int x){
	if (x == b) has_aorb = true;
	vis[x] = true;
	if (x == a){
		for (int i = 0; i < v[x].size(); i++){
			if (!vis[v[x][i]]){
				sizea[++childa] = dfsa(v[x][i]);
				if (has_aorb){
					atob = childa;
					has_aorb = false;
				}
			}
		}
		return 0;
	} else {
		int re = 1;
		for (int i = 0; i < v[x].size(); i++)
			if (!vis[v[x][i]])
				re += dfsa(v[x][i]);
		return re;
	}
}
int dfsb(int x){
	if (x == a) has_aorb = true;
	vis[x] = true;
	if (x == b){
		for (int i = 0; i < v[x].size(); i++){
			if (!vis[v[x][i]]){
				sizeb[++childb] = dfsb(v[x][i]);
				if (has_aorb){
					btoa = childb;
					has_aorb = false;
				}
			}
		}
		return 0;
	} else {
		int re = 1;
		for (int i = 0; i < v[x].size(); i++)
			if (!vis[v[x][i]])
				re += dfsb(v[x][i]);
		return re;
	}
}
int main(){
	freopen("junction.in", "r", stdin);
	freopen("junction.out", "w", stdout);
	cout.tie(0);
	n = read(), m = read(), a = read(), b = read();
	for (int i = 1; i <= m; i++){
		int x = read(), y = read();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfsa(a);
	memset(vis, false, sizeof(vis));
	dfsb(b);
	if (atob == 0 || btoa == 0){
		cout << 0 << endl;
		return 0;
	}
	long long suma = 0, sumb = 0;
	for (int i = 1; i <= childa; i++)
		if (atob != i)
			suma += sizea[i];
	for (int i = 1; i <= childb; i++)
		if (btoa != i)
			sumb += sizeb[i];
//	cout << suma << ' ' << sumb << endl;
	cout << suma * sumb << endl;
	return 0;
}
