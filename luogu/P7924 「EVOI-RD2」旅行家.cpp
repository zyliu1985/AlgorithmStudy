#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int a[500005], b[500005];
struct node{
	int x, id;
};
vector<node> v[500005];
vector<int> w[500005];
stack<int> st;
int dfn[500005], low[500005], col[500005], coid, cur; 
void tarjan(int x, int last){
	dfn[x] = low[x] = ++cur;
	st.push(x);
	for (int i = 0; i < v[x].size(); i++)
		
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int j = 1; j <= m; j++){
		int a, b;
		cin >> a >> b;
		v[a].push_back({b, j});
		v[b].push_back({a, j});
	}
	
	return 0;
}



