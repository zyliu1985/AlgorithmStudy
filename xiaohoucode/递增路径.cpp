#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int n, m;
vector<int> v[200005];
int p[200005], dis[200005], nf[200005], ans;
bool vis[200005];
queue<int> q;
void tbpx(){
	for (int i = 1; i <= n; i++)
		if (nf[i] == 0){
			q.push(i);
			vis[i] = true;
		}
	while (!q.empty()){
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++)
			if (!vis[v[x][i]]){
				nf[v[x][i]]--;
				dis[v[x][i]] = max(dis[v[x][i]], dis[x] + 1);
				if (nf[v[x][i]] == 0){
					ans = max(ans, dis[v[x][i]]);
					q.push(v[x][i]);
					vis[v[x][i]] = true;
				}
			}
	}
}
int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	for (int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		if (p[x] < p[y]){
			v[x].push_back(y);
			nf[y]++;
		} else if (p[y] < p[x]){
			v[y].push_back(x);
			nf[x]++;
		}
	}
	memset(dis, -0x3f, sizeof(dis));
	dis[1] = 1;
	tbpx();
	cout << max(ans, 1) << endl;
	return 0;
}