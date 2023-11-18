#include <iostream>
using namespace std;

int n, a[35], cnt;
int f[35];
void dfs(int step, int sum){
	if (sum > n) return;
	if (sum == n){
		cnt++;
		return;
	}
	a[step] = 1;
	dfs(step+1, sum+1);
	a[step] = 3;
	dfs(step+1, sum+3);
	a[step] = 4;
	dfs(step+1, sum+4);
}
int main(){
	cin >> n;
	dfs(1, 0);
	cout << cnt << endl;
	
//	f[1] = 1;
//	f[2] = 1;
//	f[3] = 2;
//	f[4] = 4;
//	for (int i = 5; i <= n; i++){
//		f[i] = f[i-1]+f[i-3]+f[i-4];
//	}
//	cout << f[n] << endl;
	return 0;
}