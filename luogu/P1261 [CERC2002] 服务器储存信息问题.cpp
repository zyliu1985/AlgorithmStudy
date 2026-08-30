#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int ans;
int r[30005];
vector<int> v[30005], w[30005];
long long rankdis[15][30005];
bool vis[30005];
long long dis[30005];
int clear[30005];
struct node{
	int x;
	long long d;
	friend bool operator < (const node x, const node y){
		return x.d > y.d;
	}
};
priority_queue<node> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> r[i];
	for (int i = 1; i <= m; i++){
		int a, b, t;
		cin >> a >> b >> t;
		v[a].push_back(b);
		v[b].push_back(a);
		w[a].push_back(t);
		w[b].push_back(t);
	} 
	for (int i = 1; i <= 11; i++){
		for (int j = 1; j <= n; j++){
			if (r[j] >= i){
				rankdis[i][j] = 0;
				q.push({j, 0});
			} else {
				rankdis[i][j] = 1e18;
			}
			vis[j] = false;
		}
		while (!q.empty()){
			int x = q.top().x;
			q.pop();
			if (vis[x]) continue;
			vis[x] = true;
			for (int j = 0; j < v[x].size(); j++){
				if (rankdis[i][v[x][j]] > rankdis[i][x] + w[x][j]){
					rankdis[i][v[x][j]] = rankdis[i][x] + w[x][j];
					q.push({v[x][j], rankdis[i][v[x][j]]});
				}
			}
		}
	}
//	for (int i = 1; i <= 3; i++){
//		for (int j = 1; j <= n; j++)
//			cout << rankdis[i][j] << ' ';
//		cout << '\n';
//	}
	for (int i = 1; i <= n; i++) dis[i] = 1e18, vis[i] = false;
	for (int i = 1; i <= n; i++){
//		cout << "------------\n";
		int cur = 0;
		dis[i] = 0;
		q.push({i, 0});
		while (!q.empty()){
			int x = q.top().x;
			q.pop();
			if (vis[x]) continue;
			vis[x] = true;
			clear[++cur] = x;
			if (dis[x] >= rankdis[r[i] + 1][x]) continue;
//			cout << x << '\n';
			ans++;
			for (int j = 0; j < v[x].size(); j++){
				if (dis[v[x][j]] > dis[x] + w[x][j]){
					dis[v[x][j]] = dis[x] + w[x][j];
					q.push({v[x][j], dis[v[x][j]]});
				}
			}
		}
		for (int j = 1; j <= cur; j++){
			dis[clear[j]] = 1e18;
			vis[clear[j]] = 0;
		}
	}
	cout << ans << '\n';
	return 0;
}

