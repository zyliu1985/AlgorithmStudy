#include <iostream>
#include <algorithm>
#include <cmath> 
using namespace std;

int xmaxx, ymaxx, xminx, yminx; 
int xmaxy, ymaxy, xminy, yminy;
int xmaxxy, ymaxxy, xminxy, yminxy;
bool cmp(node a, node b){
	return a.val < b.val;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++){
			int x, y;
			cin >> x >> y;
			if (x > xmaxx || (x == xmaxx && y > ymaxx)) xmaxx = x, ymaxx = y;
			if (x < xminx || (x == xminx && y < yminx)) xminx = x, yminx = y;
			if (y > ymaxy || (y == ymaxy && x > xmaxy)) xmaxy = x, ymaxy = y;
			if (y < yminy || (y == yminy && x < xminy)) xminy = x, yminy = y;
			if (x + y > xmaxxy) xmaxx = x, ymaxx = y;
			if (x < xminx || (x == xminx && y < yminx)) xminx = x, yminx = y;
			
		}
		long long ans = 1e18;
		for (int j = 1; j <= m; j++){
			long long a, b;
			cin >> a >> b;
			long long now = 0;
			if (a - ox[1].val > ox[n].val - a) now = max(now, abs(a - ox[1].val) + abs(a - y[ox[1].id]));
			else now = max(now, abs(a - ox[n].val) + abs(a - y[ox[n].id]));
			if (a - ox[1].val > ox[n].val - a) now = max(now, abs(a - ox[1].val) + abs(a - y[ox[1].id]));
			else now = max(now, abs(a - ox[n].val) + abs(a - y[ox[n].id]));
			
		}
		cout << ans << '\n';
	}
	return 0;
}



