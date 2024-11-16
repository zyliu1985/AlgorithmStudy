#include <iostream>
#include <vector>
using namespace std;

const int N = 500005;
const int M = 1000005;
int dfn[N], low[N], clk;
bool cut[M];
struct node{
	int x, id;
};
vector<node> v[N];
void tarjan(int x, int ide){
	dfn[x] = low[x] = ++clk;
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i].id == ide) continue;
		if (dfn[v[x][i].x] == 0){
			tarjan(v[x][i].x, v[x][i].id);
			low[x] = min(low[x], low[v[x][i].x]);
			if (dfn[x] < low[v[x][i].x]) cut[v[x][i].id] = true;
		} else low[x] = min(low[x], dfn[v[x][i].x]);
	}
}
int main(){
	
	return 0;
}
