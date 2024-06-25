#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int a[6], dis[6][6][6][6][6];
bool vis[6][6][6][6][6];
int n;
struct type{
	int c[6];
};
queue<type> q;
bool check(type x){
	for (int i = 1; i <= n; i++) if (x.c[i] != i) return false;
	return true;
}
int bfs(int st1, int st2, int st3, int st4, int st5){
	cout << st1 << ' ' << st2 << endl;
	q.push({{0, st1, st2, st3, st4, st5}});
	vis[st1][st2][st3][st4][st5] = true;
	dis[st1][st2][st3][st4][st5] = 0;
	while (!q.empty()){
		type data = q.front();
		q.pop();
		if (check(data)) return dis[data.c[1]][data.c[2]][data.c[3]][data.c[4]][data.c[5]];
		cout << data.c[1] << ' ' << data.c[2] << ' ' << data.c[3] << ' ' << data.c[4] << ' ' << data.c[5] << endl;
		for (int i = 1; i <= n; i++){
			if (data.c[i] != 1){
				type nx = data;
				nx.c[i]--;
				if (!vis[nx.c[1]][nx.c[2]][nx.c[3]][nx.c[4]][nx.c[5]]){
					dis[nx.c[1]][nx.c[2]][nx.c[3]][nx.c[4]][nx.c[5]] = dis[data.c[1]][data.c[2]][data.c[3]][data.c[4]][data.c[5]] + 1;
					vis[nx.c[1]][nx.c[2]][nx.c[3]][nx.c[4]][nx.c[5]] = true;
					q.push(nx);
				}
			}
			if (data.c[i] != n){
				type nx = data;
				nx.c[i]++;
				if (!vis[nx.c[1]][nx.c[2]][nx.c[3]][nx.c[4]][nx.c[5]]){
					dis[nx.c[1]][nx.c[2]][nx.c[3]][nx.c[4]][nx.c[5]] = dis[data.c[1]][data.c[2]][data.c[3]][data.c[4]][data.c[5]] + 1;
					vis[nx.c[1]][nx.c[2]][nx.c[3]][nx.c[4]][nx.c[5]] = true;
					q.push(nx);
				}
			}
		}
	}
	return -1;
}
int main(){
	do{
		memset(vis, false, sizeof(vis));
		memset(a, 0, sizeof(a));
		cin >> n;
		if (n == 0) break;
		for (int i = 1; i <= n; i++){
			int x;
			cin >> x;
			a[x] = i;
		}
		int ans = bfs(a[1], a[2], a[3], a[4], a[5]);
		if (ans = -1) cout << "IMPOSSIBLE" << endl;
		else cout << ans << endl;
	} while (true);
	return 0;
}