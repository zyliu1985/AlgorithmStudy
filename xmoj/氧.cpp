#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int num[1005][1005];
int f[1005];
bool vis[1005];
queue<int> q;
void bfs(int st){
	q.push(st);
	vis[st] = true;
	while (!q.empty()){
		int x = q.front();
		q.pop();
		for (int i = 1; i <= n; i++){
			if (vis[i]) continue;
			num[i][i] += num[i][x];
			if (num[i][i] == n){
				f[i] = x;
				q.push(i);
				vis[i] = true;
			}
		}
	}
} 
int main(){
	freopen("O.in", "r", stdin);
	freopen("O.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			int x;
			cin >> x;
			num[i][x]++;
		}
	int st;
	for (int i = 1; i <= n; i++){
		if (num[i][i] == n){
			st = i;
			break;
		}
	}
	bfs(st);
	for (int i = 1; i <= n-1; i++)
		cout << f[i] << ' ';
	cout << f[n];
	return 0;
}

