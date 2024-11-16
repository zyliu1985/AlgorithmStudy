#include <iostream>
using namespace std;

const int MAXBIT = 62;
int cnt[MAXBIT];
long long ans;
void qie(int x){
	for (int i = x + 1; i < MAXBIT; i++) // 因为y必须大于x，所以从x+1开始枚举 
		if (cnt[i] > 0){
			ans += i - x;
			cnt[i]--; 
			return;
		} else // 如果没找到，后面找到的会给前面的每块蛋糕多一个 
			cnt[i]++;
}
int main(){
	freopen("cake.in", "r", stdin);
	freopen("cake.out", "w", stdout);
	// 读入 
	long long n, sum = 0;
	int m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		long long a;
		cin >> a;
		for (int j = 0; j < MAXBIT; j++)
			if (a >> j == 1){ // 判断a是2的几次方 
				cnt[j]++; // 计数 
				break;
			}
		sum += a;
	}
	if (sum < n){ // 判无解 
		cout << -1 << endl;
		return 0;
		
	}
	int c = 0; // 当前大小为2^x的蛋糕数量 
	for (int x = 0; x < MAXBIT; x++){
		c = c / 2 + cnt[x]; // 更新 
		if ((n >> x) & 1 && c >= 1) // 其中(n >> x) & 1用来判断n的第x位是否为1 
			c--;
		else if ((n >> x) & 1 && c == 0)
			qie(x); // 切蛋糕 
	}
	cout << ans << endl;
	return 0;
}
