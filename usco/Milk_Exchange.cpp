#include <iostream>
using namespace std;

int n, m;
long long a[200005], maxa[200005];
int type[200005];
bool vis[200005];
string s;
void dfs(int now){
	vis[now] = true;
	if (s[now] == 'R'){
		a[now == n ? 1 : now+1] += a[now];
		a[now] = 0;
		if (a[now == n ? 1 : now+1] < 0) dfs(now == n ? 1 : now+1);
	} else {
		a[now == 1 ? n : now-1] += a[now];
		a[now] = 0;
		if (a[now == 1 ? n : now-1] < 0) dfs(now == 1 ? n : now-1);
	}
}
int main(){
	cin >> n >> m;
	cin >> s;
	s = '!' + s;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		maxa[i] = a[i];
	}
	for (int i = 1; i <= n; i++){
		if (s[i] == 'R')
			type[i == n ? 1 : i+1]++;
		else
			type[i == 1 ? n : i-1]++;
		type[i]--;
	}
	for (int i = 1; i <= n; i++){
		type[i] *= m;
		a[i] += type[i];
	}
	for (int i = 1; i <= n; i++)
		if (a[i] < 0 && !vis[i]) dfs(i);
	for (int i = 1; i <= n; i++)
		a[i] = min(a[i], maxa[i]);
	long long ans = 0;
	for (int i = 1; i <= n; i++) ans += a[i];
	cout << ans << endl;
	return 0;
}