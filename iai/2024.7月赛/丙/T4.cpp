#include <iostream>
using namespace std;

int read(){
	int re = 0, type = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') type = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		re = re * 10 + (c - '0');
		c = getchar();
	}
	return re * type;
}
int a[25], ans, n;
void dfs(int x, int sum){
	if (x > n){
		ans += (sum == 0);
		return;
	}
	dfs(x+1, sum);
	dfs(x+1, sum+a[x]);
}
int main(){
	cout.tie(0);
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}
