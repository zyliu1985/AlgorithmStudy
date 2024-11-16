#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

long long k, ans = 1;
vector<int> v[10];
bool vis[10];
int dfs(int x, bool can_zero){
	int re = 1;
	vis[x] = true;
	for (int i = 0; i < v[x].size(); i++)
		if (!vis[v[x][i]]){
			if (v[x][i] == 0 && !can_zero) continue;
			re += dfs(v[x][i], can_zero);
		}
	return re;
}
int main(){
	string s;
	cin >> s >> k;
	for (int i = 1; i <= k; i++){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
	}
	for (int i = 0; i < s.size(); i++){
		memset(vis, false, sizeof(vis));
		ans *= dfs(int(s[i]-'0'), i != 0);
	}
	cout << ans << endl;
}