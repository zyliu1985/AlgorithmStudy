#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, d, k;
struct node{
	long long x, w;
	friend bool operator < (const node x, const node y){
		return x.w < y.w;
	}
} a[500005]; // 格子
long long dp[500005];
priority_queue<node> q; // 优先队列
queue<node> t; // 临时存储
int can_go(long long size, long long change){ // 返回三种状态：1：距离过小（存起来再pop）0：距离过大（直接pop）2：可以到达
	if (max(d - change, 1ll) > size) return 1;
	if (size > d + change) return 0;
	return 2;
}
bool check(int mid){
	// 初始化
	while (!q.empty()) q.pop();
	memset(dp, -0x3f, sizeof(dp));
	long long ans = -1e9;
	// 加入
	q.push(node{0, 0});
	for (int i = 1; i <= n; i++){
		while (!q.empty()){
			int type = can_go(a[i].x - q.top().x, mid);
			if (type == 0) q.pop(); // 距离过大
			else if (type == 1){ // 距离过小
				t.push(q.top()); // 存起来
				q.pop();
			} else break; // 可以到达
		}
		if (!q.empty()) dp[i] = q.top().w + a[i].w;
		q.push(node{a[i].x, dp[i]});
		while (!t.empty()) q.push(t.front()), t.pop(); // 加回去
		ans = max(ans, dp[i]);
	}
	return ans >= k;
}
int main(){
	// 读入
	cin >> n >> d >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].w;
	// 二分答案
	int l = 0, r = 1e9+1;
	while (l < r){
		int mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	if (l == 1e9+1) cout << -1 << endl;
	else cout << l << endl;
	return 0;
}