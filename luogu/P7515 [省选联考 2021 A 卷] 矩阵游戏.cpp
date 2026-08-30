#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

long long a[305][305], b[305][305];
int n, m;
vector<long long> v[605], w[605];
// 前300：行约束
// 后300：列约束
long long dis[605];
int cnt[605];
bool in[605];
queue<int> q;
bool spfa(){
	memset(dis, 0x3f, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	memset(in, 0, sizeof(in));
	dis[1] = 0;
	cnt[1] = 1;
	while (!q.empty()) q.pop();
	q.push(1);
	in[1] = true;
	while (!q.empty()){
		int x = q.front();
		q.pop();
		cnt[x]++;
		in[x] = false;
		if (cnt[x] > n+m) return false;
		for (int i = 0; i < v[x].size(); i++)
			if (dis[v[x][i]] > dis[x] + w[x][i]){
				dis[v[x][i]] = dis[x] + w[x][i];
				if (!in[v[x][i]]){
					q.push(v[x][i]);
					in[v[x][i]] = true;
				}
			}
	}
	return true;
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		for (int i = 1; i <= 600; i++)
			v[i].clear(), w[i].clear();
		cin >> n >> m;
		for (int i = 1; i < n; i++)
			for (int j = 1; j < m; j++)
				cin >> b[i][j];
		for (int i = 1; i < n; i++)
			for (int j = 1; j < m; j++)
				a[i+1][j+1] = b[i][j] - a[i][j] - a[i+1][j] - a[i][j+1];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++){
				if ((i + j) & 1){
					v[i].push_back(j+300);
					w[i].push_back(a[i][j]);
					v[j+300].push_back(i);
					w[j+300].push_back(1e6-a[i][j]); 
				} else {
					v[i].push_back(j+300);
					w[i].push_back(1e6-a[i][j]);
					v[j+300].push_back(i);
					w[j+300].push_back(a[i][j]); 
				}
			}
		bool flag = spfa();
		if (flag){
			cout << "YES\n";
			for (int i = 1; i <= n; i++){
				for (int j = 1; j <= m; j++){
					if ((i + j) & 1){
						cout << a[i][j] + (dis[i] - dis[j + 300]) << ' ';
					} else {
						cout << a[i][j] + (dis[j + 300] - dis[i]) << ' '; 
					}
				}
				cout << '\n';
			}
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}

