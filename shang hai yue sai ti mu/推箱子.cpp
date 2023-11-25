#include <iostream>
#include <cmath>
using namespace std;

int a[1000005];
int main(){
	int t, n;
	string s;
	cin >> t;
	for (int _ = 1; _ <= t; _++){
		cin >> n;
		cin >> s;
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) // 记录每个箱子的位置
			if (s[i] == '@') a[++cnt] = i;
		for (int i = 1; i <= cnt; i++) // 位置偏移成相对值
			a[i] -= i;
		int mid = cnt/2+1; // 中位数（偶数偏右）或基准数
		int ans = 0;
		for (int i = 1; i <= cnt; i++){
			ans += abs(a[i] - a[mid]);
		}
		cout << ans << endl;
	}
	return 0;
}