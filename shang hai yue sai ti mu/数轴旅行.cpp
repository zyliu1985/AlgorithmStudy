#include <iostream>
#include <cmath>
using namespace std;

int a[100005];
int n, d;
bool vis[1000000005], ans;
void dfs(int now){
	if (now > 100) return;
	if (ans) return;
	if (now == d){
		ans = true;
		return;
	}
	for (int i = 1; i <= n; i++){
		if (!vis[now+a[i]]){
			vis[now+a[i]] = true;
			dfs(now+a[i]);
			vis[now+a[i]] = false;
		}
		if (!vis[now-a[i]]){
			vis[now-a[i]] = true;
			dfs(now-a[i]);
			vis[now-a[i]] = false;
		}
	}
}
int main(){
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dfs(0);
	if (ans) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}