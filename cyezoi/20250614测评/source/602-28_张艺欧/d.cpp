#include<bits/stdc++.h>
#define lb(i) (i&(-i))
using namespace std;
int n, m, ans, a[100010], c[100010];
bool vis[100010];
/*
void add(int d, int k){
	for(int i=d; i<=n; i+=lb(i)){
		c[i]+=k;
	}
}
int sum(int d){
	int res = 0;
	for(int i=d; i; i-=lb(i)){
		res+=c[i];
	}
	return res;
}
*/
void dfs(int u, int res){
		for(int j=1; j<=a[u]; ++j){
			if(vis[j]) continue;
			vis[j] = 1;
			dfs(u+1, res+1);
			vis[j] = 0;
		}
	ans = max(ans, res);
	return;
}
void solve(){
	dfs(1, 0);
	cout << ans << endl;
}
int main(){
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> a[i];
		c[1]++;
		c[a[i]]--;
	}
	for(int i=1; i<=n; ++i){
		c[i]+=c[i-1];
	}
	solve();
	return 0;	
}
