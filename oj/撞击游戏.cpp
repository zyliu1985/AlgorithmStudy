#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int a[105], dis[105], ans, n; // dis[i]��ʾ��i���ɲݰ��ı�ը�뾶
bool vis[105]; // vis[i]��ʾ��i���ɲݰ��Ƿ�ը
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