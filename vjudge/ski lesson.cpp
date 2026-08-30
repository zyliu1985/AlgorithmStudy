#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int f[10005][105], m[105], l[105], a[105];
struct node{
	int c, d;	
} x[10005];
int mind[10005];
bool cmp(node p, node q){
	return p.c < q.c;
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t, s, n;
	cin >> t >> s >> n;
	for (int i = 1; i <= s; i++)
		cin >> m[i] >> l[i] >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> x[i].c >> x[i].d;
	sort(x+1, x+n+1, cmp);
	mind[0] = 1e9;
	for (int i = 1; i <= n; i++)
		mind[i] = min(mind[i-1], x[i].d);
	memset(f, -0x3f, sizeof(f));
	f[0][1] = 0;
	int ans = 0;
	for (int i = 0; i <= t; i++)
		for (int j = 1; j <= 100; j++){
			ans = max(ans, f[i][j]);
			// ÉÏ¿Î
			for (int k = 1; k <= s; k++)
				if (m[k] >= i && m[k] + l[k] <= t) f[m[k] + l[k]][a[k]] = max(f[m[k] + l[k]][a[k]], f[i][j]);
			// »¬Ñ©
			int r = upper_bound(x+1, x+n+1, node{j, 0}, cmp) - x - 1;
			if (i + mind[r] <= t) f[i + mind[r]][j] = max(f[i + mind[r]][j], f[i][j] + 1);
		}
	cout << ans << '\n';
	return 0;
}



