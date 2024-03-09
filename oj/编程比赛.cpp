#include <iostream>
#define int long long
using namespace std;

int a[45], ans;
bool vis[1000000005];
int n, t;
void dfs(int now, int sum){
	if (vis[sum]) return;
	vis[sum] = true;
	ans = max(sum, ans);
	while (now <= n){
		if (sum + a[now] <= t) dfs(now+1, sum + a[now]);
		now++;
	}
}
signed main(){
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}