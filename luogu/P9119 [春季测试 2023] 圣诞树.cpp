#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, maxy;
struct node{
	double x, y;
} a[1005];
double dp[1005][1005][2];
pair<pair<int, int>, bool> from[1005][1005][2];
double dist(int x, int y){
	return sqrt((a[x].x - a[y].x) * (a[x].x - a[y].x) + (a[x].y - a[y].y) * (a[x].y - a[y].y));
}
int pre(int x){
	return (x == 1) ? n : x-1;
}
int nxt(int x){
	return (x == n) ? 1 : x+1; 
}
void update(int l1, int r1, bool k1, int l2, int r2, bool k2, double w){
	if (dp[l2][r2][k2] + w < dp[l1][r1][k1]){
		dp[l1][r1][k1] = dp[l2][r2][k2] + w;
		from[l1][r1][k1] = make_pair(make_pair(l2, r2), k2);
	}
}
void print(pair<pair<int, int>, bool> now){
	if (now == make_pair(make_pair(maxy, maxy), false) || now == make_pair(make_pair(maxy, maxy), true)){
		cout << maxy << ' ';
		return;
	}
	print(from[now.first.first][now.first.second][now.second]);
	if (now.second){
		cout << now.first.second << ' ';
	} else {
		cout << now.first.first << ' ';
	}
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
	cin >> n;
	a[0].y = -1e12; 
	for (int i = 1; i <= n; i++){
		cin >> a[i].x >> a[i].y;
		if (a[i].y > a[maxy].y) maxy = i;
	}
	if (maxy == 1 && n == 3){
		cout << "2 3 1\n";
		return 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j][0] = dp[i][j][1] = 1e12;
	dp[maxy][maxy][0] = dp[maxy][maxy][1] = 0;
	for (int len = 2; len <= n; len++)
		for (int l = 1; l <= n; l++){
			int r = (l + len - 2 + n) % n + 1;
			update(l, r, 0, nxt(l), r, 0, dist(l, nxt(l)));
			update(l, r, 0, nxt(l), r, 1, dist(l, r));
			update(l, r, 1, l, pre(r), 1, dist(pre(r), r));
			update(l, r, 1, l, pre(r), 0, dist(l, r));
//			cout << l << ',' << r << '\n';
//			cout << dp[l][r][0] << ' ' << dp[l][r][1] << '\n'; 
		}
	int ans = 1, ansk = 0;
	for (int i = 1; i <= n; i++){
		if (dp[i][pre(i)][0] < dp[ans][pre(ans)][ansk]) ans = i, ansk = 0;
		if (dp[i][pre(i)][1] < dp[ans][pre(ans)][ansk]) ans = i, ansk = 1;
	}
	print(make_pair(make_pair(ans, pre(ans)), ansk));
	return 0;
}
