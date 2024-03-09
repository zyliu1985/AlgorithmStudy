#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
	int lc, rc;
} t[10005];
int dis[10005];
queue<int> q;
void bfs(int root){
	q.push(root);
	dis[root] = 1;
	int lastd = 1;
	while (!q.empty()){
		int x = q.front();
		q.pop();
		if (dis[x] != lastd) cout << endl;
		lastd = dis[x];
		cout << x << ' ';
		if (t[x].lc != 0){
			q.push(t[x].lc);
			dis[t[x].lc] = dis[x]+1;
		}
		if (t[x].rc != 0){
			q.push(t[x].rc);
			dis[t[x].rc] = dis[x]+1;
		}
	}
}
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> t[i].lc >> t[i].rc;
	}
	bfs(1);
	return 0;
}