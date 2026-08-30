#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cnt = 0;
int dfn[100005], low[100005];
bool in[100005];
void tarjan(int x){
	dfn[x] = low[x] = ++cnt;
	for (int i = 0; i < v[x].size(); i++)
		if (!dfn[v[x][i]]){
			tarjan(v[x][i]);
			
		} else if (in[v[x][i]]) low[x] = min(low[x], dfn[x]);
}
vector<int> v[100005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) tarjan(i); 
	
	return 0;
}

