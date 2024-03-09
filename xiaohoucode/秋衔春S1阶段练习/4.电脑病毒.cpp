#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int vis[100005], ans;
vector<int> v[100005];
queue<int> q;
void bfs(){
	vis[1] = true;
	q.push(1); // 初始化
	while (!q.empty()){
		int x = q.front();
		q.pop();
		int sum = 0; // sum表示x的所有未感染的邻居
		for (int i = 0; i < v[x].size(); i++) // 枚举x的所有邻居，计算未感染的节点
			if (!vis[v[x][i]]){ // 去掉已感染的节点
				vis[v[x][i]] = true; // 标记感染
				sum++;
				q.push(v[x][i]);
			}
		ans += ceil(log2(sum+1)) + sum; // 计算感染所需时间
		// cout << x << ' ' << ans << ' ' << sum << endl;
	}
}
int main(){
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs();
	cout << ans << endl;
	return 0;
}