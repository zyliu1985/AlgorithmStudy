#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

long long read(){
	long long re = 0, type = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') type = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		re = re * 10 + (c - '0');
		c = getchar();
	}
	return re * type;
}
struct node{
	int x, w;
};
vector<node> v[100005];
int dis1[100005], dis2[100005], vis[100005], add_dis[1000005];
int dfs1(int x){
	vis[x] = true;
	for (int i = 0; i < v[x].size(); i++)
		if (!vis[v[x][i].x]){
			dis1[v[x][i].x] = dis1[x] + v[x][i].w;
			dfs1(v[x][i].x);
		}
}
int dfs2(int x){
	for (int i = 0; i < v[x].size(); i++)
		if (!vis[v[x][i].x]){
			dis2[v[x][i].x] = dis2[x] + v[x][i].w;
			dfs2(v[x][i].x);
		}
}
int main(){
	cout.tie(0);
	int n = read(), m = read(), k = read(), s = read(), t = read();
	for (int i = 1; i < n; i++){
		int a = read(), b = read(), w = read();
		v[a].push_back({b, w});
		v[b].push_back({b, w});
	}
	if (k == 1e9 || m == 0){
		dfs1(s);
		cout << min(k, dis1[t]) << endl;
	} else {
//		dfs1(s);
//		memset(vis, false, sizeof(vis));
//		dfs2(t);
//		for (int i = 1; i <= n; i++)
//			
	}
	return 0;
}
