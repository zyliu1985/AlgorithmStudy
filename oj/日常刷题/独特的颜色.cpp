#include <iostream>
#include <vector>
using namespace std;

struct node{
	int f;
	vector<int> c;
} t[100005];
bool ans[100005];
int vis[100005];
int col[100005];
vector<int> v[100005];
void nrttrt(int now){
	for (int i = 0; i < v[now].size(); i++)
		if (v[now][i] != t[now].f){
			t[v[now][i]].f = now;
			t[now].c.push_back(v[now][i]);
			nrttrt(v[now][i]);
		}
}
void dfs(int now){
	if (!vis[col[now]]) ans[now] = true;
	vis[col[now]]++;
	for (int i = 0; i < t[now].c.size(); i++)
		dfs(t[now].c[i]);
	vis[col[now]]--;
}
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> col[i];
	for (int i = 2; i <= n; i++){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	nrttrt(1);
	dfs(1);
	for (int i = 1; i <= n; i++)
		if (ans[i]) cout << i << endl;
	return 0;
}