#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct node{
	int x, y;
	friend bool operator == (const node x, const node y){
		return (x.x == y.x && x.y == y.y);
	}
};
struct node2{
	node pos;
	long long d;
	friend bool operator < (const node2 x, const node2 y){
		return x.d > y.d;
	}
};
struct quest{
	int x, p, t;
} qt[55];
bool cmp(quest x, quest y){
	return x.p < y.p;
}
int n, m, t;
// 0:ио   1:об   2:вС   3:ср 
int w[505][505][4];
int point[55], cur;
long long dis[55][505][505];
long long dp[105][105];
priority_queue<node2> q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
node getpos(int id){
	if (id <= m + 1) return node{1, id};
	if (id <= n + m + 1) return node{id - m, m+1};
	if (id <= n + m*2 + 1) return node{n+1, n+m*2+2-id};
	return node{n*2+m*2+2-id, 1}; 
}
void addedge(node x, node y, int d){
	for (int i = 0; i < 4; i++){
		int nx = x.x + dx[i];
		int ny = x.y + dy[i];
		if (node{nx, ny} == y){
			w[x.x][x.y][i] = d;
			w[y.x][y.y][i^1] = d;
			return;
		}
	}
}
long long pointdis(int x, int y){
	if (x > cur) x -= cur;
	if (y > cur) y -= cur;
	node posy = getpos(point[y]);
	return dis[x][posy.x][posy.y];
}
bool in(node x){
	return 1 <= x.x && x.x <= n+1 && 1 <= x.y && x.y <= m+1;
}
void dij(int i){
	node st = getpos(point[i]);
	q.push(node2{st, 0});
	dis[i][st.x][st.y] = 0;
//	cout << "start: (" << st.x << ", " << st.y << "): " << dis[i][st.x][st.y] << '\n';  
	while (!q.empty()){
		node x = q.top().pos;
//		cout << "(" << x.x << ", " << x.y << "): " << dis[i][x.x][x.y] << '\n'; 
		q.pop();
		for (int d = 0; d < 4; d++){
			node nx = {x.x + dx[d], x.y + dy[d]};
			if (!in(nx)) continue;
//			cout << "-> (" << nx.x << ", " << nx.y << "): " << dis[i][x.x][x.y] << "+" << w[x.x][x.y][d] << " update " << dis[i][nx.x][nx.y] << '\n';  
			if (dis[i][x.x][x.y] + w[x.x][x.y][d] < dis[i][nx.x][nx.y]){
				dis[i][nx.x][nx.y] = dis[i][x.x][x.y] + w[x.x][x.y][d];
				q.push(node2{nx, dis[i][nx.x][nx.y]});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> t;
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= m; j++){
			int rank;
			cin >> rank;
			w[i+1][j][3] = rank;
			w[i+1][j+1][2] = rank;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < m; j++){
			int row;
			cin >> row;
			w[i][j+1][1] = row;
			w[i+1][j+1][0] = row;
		}
	while (t--){
		cur = 0;
		for (int i = 1; i <= n*2+m*2; i++){
			node now = getpos(i);
			node nxt = (i == n*2+m*2) ? getpos(1) : getpos(i+1);
			addedge(now, nxt, 0);
		}
		memset(dis, 0x3f, sizeof(dis));
		int k;
		cin >> k;
		if (k == 1){
			cout << 0 << '\n';
			continue;
		}
		for (int i = 1; i <= k; i++)
			cin >> qt[i].x >> qt[i].p >> qt[i].t;
		sort(qt+1, qt+k+1, cmp);
		for (int i = 1; i <= k; i++){
			node now = getpos(qt[i].p);
			node nxt = (qt[i].p == n*2+m*2) ? getpos(1) : getpos(qt[i].p+1);
			addedge(now, nxt, qt[i].x);
			if (i != 1 && qt[i-1].t != qt[i].t){
				point[++cur] = qt[i].p;
			}
		}
		if (qt[1].t != qt[k].t){
			point[++cur] = qt[1].p;
		}
		if (cur == 0){
			cout << 0 << '\n';
			continue;
		} 
		for (int i = 1; i <= cur; i++)
			dij(i);
//		for (int i = 1; i <= cur; i++)
//			for (int j = 1; j <= cur; j++){
//				node now = getpos(point[i]);
//				node nxt = getpos(point[j]);
//				cout << "(" << now.x << ", " << now.y << ") -> ";
//				cout << "(" << nxt.x << ", " << nxt.y << "): ";
//				cout << dis[i][nxt.x][nxt.y] << '\n';
//			}
		for (int len = 2; len <= cur; len += 2)
			for (int l = 1; l + len - 1 <= cur * 2; l++){
				int r = l + len - 1;
				dp[l][r] = dp[l+1][r-1] + pointdis(l, r);
				for (int j = l + 1; j < r - 1; j += 2)
					dp[l][r] = min(dp[l][r], dp[l][j] + dp[j+1][r]);
			}
		long long ans = 1e18;
		for (int i = 1; i <= cur; i++)
			ans = min(ans, dp[i][i+cur-1]);
		cout << ans << '\n';
	}
	return 0;
}

