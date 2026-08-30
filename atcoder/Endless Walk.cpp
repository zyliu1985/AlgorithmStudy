#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int cur;
int dfn[200005], low[200005];
bool inf[200005], in[200005];
stack<int> st;
vector<int> v[200005]; 
void tarjan(int x){
	dfn[x] = low[x] = ++cur;
	in[x] = true;
	st.push(x); 
	for (int i = 0; i < v[x].size(); i++)
		if (!dfn[v[x][i]]){
			tarjan(v[x][i]);
			low[x] = min(low[x], low[v[x][i]]);
		} else if (in[v[x][i]]) low[x] = min(low[x], dfn[v[x][i]]);
	if (dfn[x] == low[x]){
		if (st.top() == x){
			for (int i = 0; i < v[x].size(); i++)
				inf[x] |= inf[v[x][i]];
			in[x] = false;
			st.pop();
		} else {
			while (!st.empty()){
				int t = st.top();
				st.pop();
				inf[t] = true;
				in[t] = false;
				if (t == x) break;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) tarjan(i);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += inf[i];
	cout << ans << '\n';
	return 0;
}

