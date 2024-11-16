#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m;
const int N = 500005;
int dfn[N], low[N], color[N], clk, co;
bool in[N];
stack<int> st;
vector<int> v[N];
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
int main(){
	
	return 0;
}
