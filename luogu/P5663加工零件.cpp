#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <queue>
using namespace std;

int n, m, que;
int dis[2][100005]; // dis[0][i]表示走偶数步能走到i点最少的步数，dis[1][i]表示走奇数步能走到i点最少的步数
bool vis[100005]; // vis[x]表示x是否在队列里
queue<int> q;
vector<int> v[100005];
void spfa(){
	memset(dis, 0x3f, sizeof(dis));
	q.push(1);
	dis[0][1] = 0;
	while (!q.empty()){
		int x = q.front();
		q.pop();
		vis[x] = false;
		for (int i = 0; i < v[x].size(); i++){
			if (dis[0][x] + 1 < dis[1][v[x][i]]){ // +1奇偶性转变
				dis[1][v[x][i]] = dis[0][x] + 1;
				if (!vis[v[x][i]]){
					vis[v[x][i]] = true;
					q.push(v[x][i]);
				}
			}
			if (dis[1][x] + 1 < dis[0][v[x][i]]){
				dis[0][v[x][i]] = dis[1][x] + 1;
				if (!vis[v[x][i]]){
					vis[v[x][i]] = true;
					q.push(v[x][i]);
				}
			}
		}
	}
}
int main(){
	// 读入
	cin >> n >> m >> que;
	for (int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	// 求出所有点与点1的距离
	spfa();
	for (int i = 1; i <= que; i++){
		int a, l;
		scanf("%d%d", &a, &l);
		if (dis[l & 1][a] <= l) // 判断能否在l步内走出步数与l同奇偶的路线
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}