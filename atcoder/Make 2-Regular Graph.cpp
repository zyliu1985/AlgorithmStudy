#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
bool mp[10][10];
int from[10];
int ans = 1e9;
void dfs(int x, int now){
//	cout << x << ',' << now << '\n'; 
	if (x > n){
//		if (now < ans){
//			cout << "******\n";
//			for (int i = 1; i <= n; i++)
//				cout << from[i] << '.';
//			cout << '\n';	
//		}
		ans = min(ans, now);
		return;
	}
	for (int i = 1; i <= n; i++)
		if (i == x || i == from[x] || from[i]) continue;
		else from[i] = x, dfs(x+1, now + (mp[x][i] ? -1 : 1)), from[i] = 0;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		mp[a][b] = 1;
		mp[b][a] = 1;
	}
	dfs(1, m);
	cout << ans << '\n';
	return 0;
}



