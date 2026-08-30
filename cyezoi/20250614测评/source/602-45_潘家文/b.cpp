#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lll = __int128;
using ull= unsigned long long;
using vi = vector<int>;
using pii = pair<int, int>;
using pbi = pair<bool, int>;
const int INF = 0x3f3f3f3f, C = 200000;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
int c, ans, tg[2][C + 5], nc;
queue<pbi> q, nq;

void bfs(bool x, int y){
	tg[x][y] = ++ nc;
	q.push({x, y});
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		nq.push({x, y});
		q.pop();
		if(y > 1 && !tg[x][y - 1]){
			tg[x][y - 1] = nc;
			q.push({x, y - 1});
		}
		if(y < c && !tg[x][y + 1]){
			tg[x][y + 1] = nc;
			q.push({x, y + 1});
		}
		if((y & 1) && !tg[x ^ 1][y]){
			tg[x ^ 1][y] = nc;
			q.push({x ^ 1, y});
		}
	}
	while(!nq.empty()){
		x = nq.front().first;
		y = nq.front().second;
		nq.pop();
		ans += 3;
		if(y > 1 && tg[x][y - 1] == nc) -- ans;
		if(y < c && tg[x][y + 1] == nc) -- ans;
		if((y & 1) && tg[x ^ 1][y] == nc) -- ans;
	}
}

int main(){
	int t;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c;
	for(int i = 1; i <= c; ++ i){
		cin >> t;
		if(!t) tg[0][i] = -1;
	}
	for(int i = 1; i <= c; ++ i){
		cin >> t;
		if(!t) tg[1][i] = -1;
	}
	for(int i = 1; i <= c; ++ i) if(!tg[0][i]) bfs(0, i);
	for(int i = 1; i <= c; ++ i) if(!tg[1][i]) bfs(1, i);
	cout << ans;
}

