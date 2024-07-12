#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int r[1000005]; // 房间数
struct node{
	int d, s, t;
} a[1000005]; // 订单
int d[1000005]; // 差分
bool check(int x){
	// 初始化
	memset(d, 0, sizeof(d));
	// 构建差分数组
	for (int i = 1; i <= x; i++){
		d[a[i].s] += a[i].d;
		d[a[i].t+1] -= a[i].d;
	}
	// 检查可行性
	int last = 0;
	for (int i = 1; i <= n; i++){
		last += d[i];
		if (last > r[i]) return false;
	}
	return true;
}
int main(){
	// 读入
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> r[i];
	for (int i = 1; i <= m; i++)
		cin >> a[i].d >> a[i].s >> a[i].t;
	// 二分答案
	int l = 0, r = n;
	while (l < r){
		int mid = (l + r + 1) / 2;
		if (check(mid)) l = mid;
		else r = mid-1;
	}
	if (l == n) cout << 0 << endl;
	else cout << -1 << endl << l+1 << endl;
	return 0;
}