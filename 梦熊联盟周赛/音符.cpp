#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int read(){
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9'){if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9'){x = (x << 1) + (x << 3) + (c - '0'); c = getchar();}
	return x * f;
}
int a[500005], r[500005], len[500005], maxl[500005];
int main(){
	freopen("music.in", "r", stdin);
	freopen("music.out", "w", stdout);
	int n = read(), k = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; i++){ // 用upper_bound求r与len 
		r[i] = upper_bound(a+1, a+n+1, a[i] + k) - a - 1;
		len[i] = r[i] - i + 1;
	}
	for (int i = n; i >= 1; i--) // 求maxl
		maxl[i] = max(maxl[i+1], len[i]); 
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, len[i] + maxl[r[i] + 1]);
	cout << ans << endl;
	return 0;
}
