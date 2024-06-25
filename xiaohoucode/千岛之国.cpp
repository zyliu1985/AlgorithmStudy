#include <iostream>
#include <vector>
using namespace std;

int root = 1;
int dfn[100005], low[100005], clk, ans[100005];
vector<int> v[100005];
void tarjan(int x){
	dfn[x] = low[x] = ++clk;
	int child = 0;
	int num = 0;
	for (int i = 0; i < v[x].size(); i++){
		if (dfn[v[x][i]] == 0){
			tarjan(v[x][i]);
			child++;
			low[x] = min(low[x], low[v[x][i]]);
			if (low[v[x][i]] >= dfn[x]) num++;
		} else low[x] = min(low[x], dfn[v[x][i]]);
	}
	if (x == root && child < 2) num = 0;
	ans[x] = num;
}
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	tarjan(1);
	bool flag = true;
	for (int i = 1; i <= n; i++)
		if (ans[i] != 0){
			cout << i << ' ' << ans[i]+(i != 1) << endl;
			flag = false;
		}
	if (flag) cout << -1 << endl;
	return 0;
}