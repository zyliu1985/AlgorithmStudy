#include <iostream>
#include <vector>
using namespace std;

const int root = 1;
const int N = 500005;
vector<int> v[N];
int dfn[N], low[N], clk, ans;
bool cut[N];
void tarjan(int x){
	dfn[x] = low[x] = ++clk;
	int child = 0;
	for (int i = 0; i < v[x].size(); i++){
		if (dfn[v[x][i]] == 0){
			tarjan(v[x][i]);
			child++;
			low[x] = min(low[x], low[v[x][i]]);
			if (dfn[x] <= low[v[x][i]]) cut[x] = true;
		} else low[x] = min(low[x], dfn[v[x][i]]);
	}
	if (x == root && child < 2) cut[x] = false;
}
int main(){
	
	return 0;
}