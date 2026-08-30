#include<bits/stdc++.h>
using namespace std;
int n, ans, a[200010][2];
bool vis[200010][2];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int bfs(int x, int y){
	int cnt = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	while(!q.empty()){
		int xx = q.front().first, yy = q.front().second;
		q.pop();
		if(vis[xx][yy]) continue;
		vis[xx][yy] = 1;
		cnt+=3;
//		cout << cnt << endl;
//		printf("%d %d,%d\n", xx, yy, cnt);
		for(int i=0; i<4; ++i){
			int sx = xx+dx[i], sy = yy+dy[i];
			if(i == 0 || i == 2){
				if(sx%2 == 0) continue;
			}
			if(sx<=0 || sy<0 || sx>n || sy>1  || !a[sx][sy]){
				continue;
			}
			if(vis[sx][sy]){
				continue;
			}
			cnt-=2;//common arc
			q.push(make_pair(sx, sy));
//			printf("%d %d to ", xx, yy);
//			cout << 1 << endl;
		}
	}
//	cout << cnt << endl;
	return cnt;
}
int main(){
//	freopen("data.in", "r", stdin);
	cin >> n;
	for(int i=0; i<=1; ++i){
		for(int j=1; j<=n; ++j){
			cin >> a[j][i];
		}
	}
	for(int i=0; i<=1; ++i){
		for(int j=1; j<=n; ++j){
			if(!vis[j][i] && a[j][i]){
				ans+=bfs(j, i);
			}
//			cout << ans << endl;
		}
	}
	cout << ans << endl;
}
