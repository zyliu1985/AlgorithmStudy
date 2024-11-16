#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int n, t, a, b, cnt;
double dis[405];
bool vis[405];
struct node{
	int x;
	double w;
};
vector<node> v[405];
struct dot{
	int x, y;
} pl[405];
void set_up(){
	cnt = 0;
	for (int i = 1; i <= 400; i++)
		v[i].clear();
}
double side(dot x, dot y){
	return sqrt(pow(x.x - y.x, 2) + pow(x.y - y.y, 2));
}
void make_vect(int id1, int id2, int id3, int train){
	// 构建第四个点 
	double d[4];
	d[1] = side(pl[id1], pl[id2]);
	d[2] = side(pl[id2], pl[id3]);
	d[3] = side(pl[id3], pl[id1]);
	int a, mid, b, maxn = 0;
	if (maxn < d[1]){
		maxn = d[1];
		a = id1;
		b = id2;
		mid = id3;
	}
	if (maxn < d[2]){
		maxn = d[2];
		a = id2;
		b = id3;
		mid = id1;
	}
	if (maxn < d[3]){
		maxn = d[3];
		a = id3;
		b = id1;
		mid = id2;
	}
	int xd = pl[a].x - pl[mid].x;
	int yd = pl[a].y - pl[mid].y;
	pl[++cnt] = dot{pl[b].x + xd, pl[b].y + yd};
	// 连上火车的边
	for (int i = cnt - 3; i <= cnt; i++)
		for (int j = i + 1; j <= cnt; j++){
			v[i].push_back({j, side(pl[i], pl[j]) * train});
			v[j].push_back({i, side(pl[i], pl[j]) * train});
		}
	// 连上飞机的边 
	for (int i = cnt - 3; i <= cnt; i++)
		for (int j = 1; j <= cnt - 4; j++){
			v[i].push_back({j, side(pl[i], pl[j]) * t});
			v[j].push_back({i, side(pl[i], pl[j]) * t});
		}
}
void dij(int st){
	for (int i = 0; i <= n * 4; i++)
		dis[i] = 1e9;
	memset(vis, false, sizeof(vis));
	dis[st] = 0;
	for (int i = 1; i <= n * 4; i++){
		int x = 0;
		for (int j = 1; j <= n * 4; j++)
			if (dis[j] < dis[x] && !vis[j])
				x = j;
		vis[x] = true;
		for (int j = 0; j < v[x].size(); j++)
			if (dis[v[x][j].x] > dis[x] + v[x][j].w)
				dis[v[x][j].x] = dis[x] + v[x][j].w;
	}
}
int main(){
	int text;
	cin >> text;
	while (text--){
		set_up();
		cin >> n >> t >> a >> b;
		for (int i = 1; i <= n; i++){
			int T;
			cnt++;
			cin >> pl[cnt].x >> pl[cnt].y;
			cnt++;
			cin >> pl[cnt].x >> pl[cnt].y;
			cnt++;
			cin >> pl[cnt].x >> pl[cnt].y;
			cin >> T;
			make_vect(cnt - 2, cnt - 1, cnt, T);
		}
//		for (int i = 1; i <= n; i++)
//			for (int j = 1; j <= 4; j++){
//				cout << i << '(' << j << "):";
//				for (int k = 0; k < v[(i - 1) * 4 + j].size(); k++)
//					cout << v[(i - 1) * 4 + j][k].x << ' ';
//				cout << endl;
//			}
		double ans = 1e9;
		for (int i = 4 * a - 3; i <= 4 * a; i++){
			dij(i);
			for (int i = 4 * b - 3; i <= 4 * b; i++)
				ans = min(ans, dis[i]);
		}
		printf("%.1lf", ans);
	}
	return 0;
}