#include <iostream>
using namespace std;

int n, m, num;
int a[3005], b[105], t[3005], f[3005];
int dp(){
	f[0] = 0, f[1] = t[1];
	for (int i = 2; i <= num; i++)
		f[i] = max(f[i-1], f[i-2] + t[i]);
	return f[num];
}
void solve1(){
	num = n;
	for (int i = 1; i <= n; i++)
		t[i] = a[i];
	cout << dp() << '\n';
}
void solve2(){
	num = n+1;
	int ans = 0; 
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n+1; j++){
			if (j < i) t[j] = a[j];
			if (j == i) t[j] = b[1];
			if (j > i) t[j] = a[j-1];
		}
		ans = max(ans, dp());
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n; 
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> m;
	for (int j = 1; j <= m; j++)
		cin >> b[j];
	if (m == 0){
		solve1();
	} else if (m == 1){
		solve2();
	}
	return 0;
}
