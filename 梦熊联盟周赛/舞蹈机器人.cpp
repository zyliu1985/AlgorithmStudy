#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct node{
	int x, y, step, f;
	friend bool operator < (const node x, const node y){
		if (x.x != y.x) return x.x < y.x;
		if (x.y != y.y) return x.y < y.y;
		if (x.step != y.step) return x.step < y.step;
		return x.f < y.f;
	}
};
queue<node> q;
int ans, n, dx[2] = {0, 1}, dy[2] = {1, 0};
map<node, bool> vis;
void bfs(int sx, int sy){
	vis[node{sx, sy, 0, 0}] = vis[node{sx, sy, 0, 1}] = true;
	q.push(node{sx, sy, 0, 0});
	q.push(node{sx, sy, 0, 1});
	while (!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int step = q.front().step;
		int f = q.front().f;
//		cout << x << ' ' << y << ' ' << step << ' ' << f << ':' << endl; 
		q.pop();
		if (step == n){
			ans++;
		} else {
			int nx, ny;
			nx = x + dx[f], ny = y + dy[f];
//			cout << "1: " << nx << ' ' << ny << " is " << (!vis[{nx, ny, step + 1, f ^ 1}] ? "OK." : "not OK.") << endl;
			if (!vis[node{nx, ny, step + 1, f ^ 1}] || (step + 1 == n && !vis[node{nx, ny, step + 1, f}])){
				vis[node{nx, ny, step + 1, f ^ 1}] = true;
				if (step + 1 == n)
					vis[node{nx, ny, step + 1, f}] = true;
				q.push(node{nx, ny, step + 1, f ^ 1});
			}
			nx = x - dx[f], ny = y - dy[f];
//			cout << "2: " << nx << ' ' << ny << " is " << (!vis[{nx, ny, step + 1, f ^ 1}] ? "OK." : "not OK.") << endl;
			if (!vis[node{nx, ny, step + 1, f ^ 1}] || (step + 1 == n && !vis[node{nx, ny, step + 1, f}])){
				vis[node{nx, ny, step + 1, f ^ 1}] = true;
				if (step + 1 == n)
					vis[node{nx, ny, step + 1, f}] = true;
				q.push(node{nx, ny, step + 1, f ^ 1});
			}
		}
	}
}
int main(){
	freopen("dance.in", "r", stdin);
	freopen("dance.out", "w", stdout);
	cout.tie(0);
	cin >> n;
	bfs(500, 500);
	cout << ans << endl;
	return 0;
}
