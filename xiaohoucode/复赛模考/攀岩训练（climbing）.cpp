#include <iostream>
#include <cmath>
#include <algorithm>
#define int long long
using namespace std;

struct node{
	int x, y;
} a[50];
int n, h, k, s, ans = 1e16;
void dfs(int step, int x, int j){
	if (step == s-1){
		j = max(j, (h-a[x].y)*(h-a[x].y));
		ans = min(ans, j);
		return;
	}
	for (int i = x+1; i <= n; i++){
		dfs(step+1, i, max(j, (x != 0 ? (abs(a[i].x-a[x].x)*abs(a[i].x-a[x].x)) : 0) + abs(a[i].y-a[x].y)*abs(a[i].y-a[x].y)));
	}
}
bool cmp(node x, node y){
	return x.y < y.y;
}
signed main(){
	cin >> n >> h >> k;
	for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
	sort(a+1, a+n+1, cmp);
	for (int i = 1; i <= k; i++){
		s = i;
		dfs(0, 0, 0);
	}
	return 0;
}