#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct edge{
	int x, y, w;
} e[200005];
struct node{
	int x, val;
	friend bool operator < (const node x, const node y){
		return x.val > y.val;
	}
};
int m, n, k, mod;
long long dis[100005]; // dis[i]表示1到i的最短路径
long long dp[100005][55]; // dp[i][j]表示从1到i，路径长度为dis[i]+j的总方案数
bool vis[100005], in[100005][55], flag; // vis[i]是dij中已处理的节点，in[i]表示i节点是否在调用栈中，flag为-1标记
vector<node> v[100005], fv[100005]; // v为正图，fv为反图
priority_queue<node> q; // dij堆优化
void dij(){ // 最短路
	q.push({1, 0});
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	while (!q.empty()){
		int x = q.top().x;
		q.pop();
		if (vis[x]) continue;
		vis[x] = true;
		for (int i = 0; i < v[x].size(); i++)
			if (dis[v[x][i].x] > dis[x] + v[x][i].val){
				dis[v[x][i].x] = dis[x] + v[x][i].val;
				q.push(node{v[x][i].x, dis[v[x][i].x]});
			}
	}
}
int memdfs(int x, int y){ // 记忆化搜索
	if (in[x][y]){ // 判断-1
		flag = true;
		return 0;
	}
	if (dp[x][y]) // 如果有解，那么返回
		return dp[x][y];
	in[x][y] = true; // 进入调用栈
	for (int i = 0; i < fv[x].size(); i++){
		int from = fv[x][i].x, ny = dis[x] + y - fv[x][i].val - dis[from];
		if (ny < 0) continue; // 小于0无法实现
		dp[x][y] += memdfs(from, ny); // 递归
		dp[x][y] %= mod; // 取模
		if (flag){ // 如果已经判出来了-1，那么直接返回
			in[x][y] = false; // 弹出调用栈
			return 0;
		}
	}
	if (x == 1 && y == 0) dp[x][y] = 1; // 当遍历到起点时，返回-1（起点也要枚举一遍邻居判-1）
	in[x][y] = false; // 弹出调用栈
	return dp[x][y];
}
int main(){
	int t;
	cin >> t;
	while (t--){
		// 初始化
		flag = false;
		memset(vis, false, sizeof(vis));
		memset(in, false, sizeof(in));
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++){
			v[i].clear();
			fv[i].clear();
		}
		// 读入
		cin >> n >> m >> k >> mod;
		for (int i = 1; i <= m; i++){
			cin >> e[i].x >> e[i].y >> e[i].w;
			v[e[i].x].push_back({e[i].y, e[i].w}); // 建正图
			fv[e[i].y].push_back({e[i].x, e[i].w}); // 建反图
		}
		// 跑最短路
		dij();
		long long ans = 0;
		bool flag2 = false;
		for (int i = 0; i <= k; i++){
			ans += memdfs(n, i); // 只要路径长度小于等于dis[n]+k，都可以，循环累加
			ans %= mod;
			if (flag){ // -1直接输出
				cout << -1 << endl;
				flag2 = true;
				break;
			}
		}
		if (!flag2) cout << ans << endl;
	}
	return 0;
}
