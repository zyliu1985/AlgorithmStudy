#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring> 
#include <queue>
using namespace std;

vector<int> v[2000005];
int dfn[2000005], cnt;
int low[2000005], col[2000005], colnt;
bool in[2000005];
stack<int> st;
void tarjan(int x){
//	cout << x << '\n';
	st.push(x);
	in[x] = true;
	low[x] = dfn[x] = ++cnt;
	for (int i = 0; i < v[x].size(); i++)
		if (dfn[v[x][i]] && in[v[x][i]]){
			low[x] = min(low[x], dfn[v[x][i]]);
		} else if (!dfn[v[x][i]]){
			tarjan(v[x][i]);
			low[x] = min(low[x], low[v[x][i]]);
		}
	if (low[x] == dfn[x]){
		colnt++;
		while (!st.empty()){
			int now = st.top();
			if (dfn[now] < dfn[x]) break;
			col[now] = colnt;
			st.pop();
		}
	}
	in[x] = false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, a, y, b;
		cin >> x >> a >> y >> b;
		v[(x - 1) * 2 + a].push_back((y - 1) * 2 + (!b));
		v[(y - 1) * 2 + b].push_back((x - 1) * 2 + (!a));
	}
	for (int i = 0; i <= 2 * n - 1; i++)
		if (!dfn[i]) tarjan(i);
//	for (int i = 0; i <= 2 * n - 1; i++)
//		cout << col[i] << ' ';
//	cout << '\n';
	for (int i = 0; i < n; i++){
//		cout << col[2 * i] << ' ' << col[2 * i + 1] <<'\n';
		if (col[2 * i] == col[2 * i + 1]){
			cout << "IMPOSSIBLE\n";
			return 0;
		} 
	}
	cout << "POSSIBLE\n";
	for (int i = 0; i < n; i++)
		cout << (col[2 * i] < col[2 * i + 1]) << ' ';
	return 0;
}

