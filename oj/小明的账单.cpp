#include <iostream>
using namespace std;

struct node{
	int lc, rc, f;
} t[1000005];
int ans;
void dfs(int now, int d){
	ans = max(ans, d);
	if (t[now].lc != 0)
		dfs(t[now].lc, d+1);
	if (t[now].rc != 0)
		dfs(t[now].rc, d+1);
}
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> t[i].lc >> t[i].rc;
	}
	for (int i = 1; i <= n; i++){
		if (t[i].lc != 0) t[t[i].lc].f = i;
		if (t[i].rc != 0) t[t[i].rc].f = i;
	}
	int root;
	for (int i = 1; i <= n; i++){
		if (t[i].f == 0){
			root = i;
			break;
		}
	}
	dfs(root, 1);
	cout << ans << endl;
	return 0;
}
Ð¡ºï±à³Ì£¨8070615339112706£©