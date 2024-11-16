#include <iostream>
#include <vector>
#include <stack>
using namespace std;

inline int read(){
	int re = 0, type = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') type = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		re = (re << 1) + (re << 3) + (c - '0');
		c = getchar();
	}
	return re * type;
}
inline void write(int x){
	if (x < 0){
		putchar('-');
		write(-x);
		return;
	}
	if (x / 10)
		write(x / 10);
	putchar(x % 10 + '0');
}
int n, m;
const int N = 200005;
int dfn[N], low[N], color[N], clk, co;
bool in[N];
stack<int> st;
vector<int> v[N], g[N];
void tarjan(int x){
	dfn[x] = low[x] = ++clk;
	in[x] = true;
	st.push(x);
	for (int i = 0; i < v[x].size(); i++){
		if (!dfn[v[x][i]]){
			tarjan(v[x][i]);
			low[x] = min(low[x], low[v[x][i]]);
		}
		if (in[v[x][i]]) low[x] = min(low[x], dfn[v[x][i]]);
	}
	if (dfn[x] == low[x]){
		co++;
		while (!st.empty()){
			int p = st.top();
			st.pop();
			color[p] = co;
			in[p] = false;
			if (p == x) break;
		}
	}
}
bool visi[N];
int a[N], disi[N];
void dfs(int x){
	visi[x] = true;
	for (int i = 0; i < g[x].size(); i++){
		if (!visi[g[x][i]])
			dfs(g[x][i]);
		disi[x] += disi[g[x][i]];
	}
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	n = read();
	m = n;
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++)
		v[i].push_back(read());
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < v[i].size(); j++){
			if (color[i] != color[v[i][j]])
				g[color[i]].push_back(color[v[i][j]]);
		}
		disi[color[i]] += a[i];
//		cout << color[i] << ':' << disi[color[i]] << "+ i=" << i << ':' << a[i] << endl;
	}
//	for (int i = 1; i <= co; i++)
//		cout << disi[i] << ' ';
//	cout << endl;
	for (int i = 1; i <= n; i++){
		if (!visi[color[i]])
			dfs(color[i]);
		write(disi[color[i]]);
		putchar('\n');
	}
	return 0;
}
