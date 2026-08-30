#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int a[405];
int c[405][405];
struct node{
	int d, id;
};
int dis[405][405];
queue<node> q;
int n, k, ans = 1e9;
bool vis[405][405];
void bfs(){
	memset(dis, 0x3f, sizeof(dis));
	q.push({0, 1});
	dis[0][1] = 0;
	vis[0][1] = true;
	while (!q.empty()){
		int x = q.front().id, d = q.front().d;
		q.pop();
		if (d == k){
			ans = min(ans, dis[d][x] + c[x][n]);
			continue;
		}
		for (int i = x+1; i <= n; i++){
			dis[d+1][i] = min(dis[d+1][i], dis[d][x] + c[x][i-1]);
			if (!vis[d+1][i]){
				q.push({d+1, i});
				vis[d+1][i] = 1;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++){
		int maxa = a[i];
		for (int j = i; j <= n; j++)
			if (maxa >= a[j]) c[i][j] = c[i][j-1] + maxa - a[j];
			else c[i][j] = c[i][j-1] + (a[j] - maxa) * (j - i), maxa = a[j];
	} 
	bfs();
	cout << ans << '\n';
	return 0;
}

