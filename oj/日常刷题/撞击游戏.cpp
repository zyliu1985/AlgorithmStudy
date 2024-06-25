#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int a[105], dis[105], ans, n; // dis[i]表示第i个干草包的爆炸半径
bool vis[105]; // vis[i]表示第i个干草包是否爆炸
queue<int> q;
int bfs(int st){
	int re = 1;
	q.push(st);
	vis[st] = true;
	dis[st] = 1;
	while (!q.empty()){
		int now = q.front();
		q.pop();
		int less = lower_bound(a+1, a+n+1, a[now]-dis[now]) - a;
		int top = upper_bound(a+1, a+n+1, a[now]+dis[now]) - a;
		for (int i = less; i < top; i++)
			if (!vis[i]){
				re++;
				q.push(i);
				vis[i] = true;
				dis[i] = dis[now] + 1;
			}
	}
	return re;
}
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++){
		memset(vis, false, sizeof(vis));
		memset(dis, 0, sizeof(dis));
		ans = max(ans, bfs(i));
	}
	cout << ans << endl;
}