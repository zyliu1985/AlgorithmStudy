#include <iostream>
#define int long long
#include <cstring>
using namespace std;

struct node{
	int x, v, w, d;
} a[2005];
int f[2005][2005];
signed main(){
	int n, v, l;
	cin >> n >> v >> l;
	for (int i = 1; i <= n; i++){
		cin >> a[i].x >> a[i].v >> a[i].w;
		a[i].d = a[i].x - a[i-1].x;
	}
	memset(f, 0x7f, sizeof(f));
	f[0][v] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= v; j++){
			if (j <= v - a[i].d && j != v) f[i][j] = min(f[i-1][j+a[i].d], (long long)(1e18*(j-a[i].v+a[i].d < 0LL))+f[i-1][max(j-a[i].v+a[i].d, 0LL)] + a[i].w);
			else if (j < v) f[i][j] = (long long)(1e18*(j-a[i].v+a[i].d < 0LL))+f[i-1][max(j-a[i].v+a[i].d, 0LL)] + a[i].w;
			else {
				for (int k = a[i].d; k <= min(v, a[i].v); k++)
					f[i][v] = min(f[i][v], f[i-1][v-k+a[i].d] + a[i].w);
			}
		}
	int ans = 1e18;
	for (int i = l - a[n].x; i <= v; i++)
		ans = min(ans, f[n][i]);
	if (ans == 1e18) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}
/*
5 5 20
5 5 1000000000
5 5 999999999
10 3 999999999
10 3 999999999
15 5 1000000000
*/