#include <iostream>
#include <vector>
using namespace std;

int dfn[30005], low[30005], clk, ans, cnt;
struct node{
	int x, id;
};
vector<node> v[30005];
void tarjan(int x, int ide){
	dfn[x] = low[x] = ++clk;
	for (int i = 0; i < v[x].size(); i++){
		if (v[x][i].id == ide) continue;
		if (dfn[v[x][i].x] == 0){
			tarjan(v[x][i].x, v[x][i].id);
			low[x] = min(low[x], low[v[x][i].x]);
			if (dfn[x] < low[v[x][i].x]) ans++;
		} else low[x] = min(low[x], dfn[v[x][i].x]);
	}
}
int main(){
	
	return 0;
}