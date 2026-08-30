#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 0 >
// 1 <
// 2 ^
// 3 v
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
struct node{
	int d, x, y;
	long long val;
	friend bool operator < (const node x, const node y){
		return x.val > y.val;
	} 
};
priority_queue<node> q;
vector<vector<long long>> f[4], a, b;
int n, m;
bool in(int x, int y){
	return 0 <= x && x < n && 0 <= y && y < m;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		cin >> n >> m;
		f[0].resize(n);
		f[1].resize(n);
		f[2].resize(n);
		f[3].resize(n);
		a.resize(n);
		b.resize(n);
		for (int i = 0; i < n; i++){
			f[0][i].resize(m);
			f[1][i].resize(m);
			f[2][i].resize(m);
			f[3][i].resize(m);
			a[i].resize(m);
			b[i].resize(m);
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++){
				int x;
				cin >> x;
				a[i][j] = x;
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++){
				int x;
				cin >> x;
				b[i][j] = x;
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				for (int k = 0; k < 4; k++)
					f[k][i][j] = 1e18;
		
		f[0][0][0] = a[0][0];
		while (!q.empty()) q.pop(); 
		q.push({0, 0, 0, a[0][0]});
		while (!q.empty()){
			int d = q.top().d, x = q.top().x, y = q.top().y;
//			cout << d << ',' << x << ',' << y << '\n';
			q.pop();
			if (d == 3 && x == n-1 && y == m-1){
				cout << f[d][x][y] << '\n';
				break;
			}
			for (int nd = 0; nd < 4; nd++){
				if (d == nd) continue; 
				if (f[nd][x][y] > f[d][x][y] + b[x][y]){
					f[nd][x][y] = f[d][x][y] + b[x][y];
					q.push({nd, x, y, f[nd][x][y]});
				}
			}
			if (in(x + dx[d], y + dy[d]) && f[d][x + dx[d]][y + dy[d]] > f[d][x][y] + a[x + dx[d]][y + dy[d]]){
				f[d][x + dx[d]][y + dy[d]] = f[d][x][y] + a[x + dx[d]][y + dy[d]];
				q.push({d, x + dx[d], y + dy[d], f[d][x + dx[d]][y + dy[d]]});
			}
		}
	} 
	return 0;
}


