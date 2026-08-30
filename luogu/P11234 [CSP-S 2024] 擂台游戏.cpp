#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, k;
void initk(){
	int temp = n-1;
	while (temp > 0){
		temp >>= 1;
		k++;
	}
}
int b[100005], c[100005];
int a[132005];
bool d[20][132005];
int f[20][132005], g[20][132005];
inline int lc(int y){return y*2-1;}
inline int rc(int y){return y*2;}
inline int dc(int x, int y){return d[x][y] ? rc(y) : lc(y);}
int invdc(int x, int y){return d[x][y] ? lc(y) : rc(y);}
void initfg(int x = 0, int y = 1){
	if (x >= k){
		f[x][y] = a[y];
		g[x][y] = y-1;
		return;
	}
	initfg(x+1, lc(y));
	initfg(x+1, rc(y));
	int r = k - x;
	if (f[x+1][dc(x, y)] >= r){
		f[x][y] = f[x+1][dc(x, y)];
		g[x][y] = g[x+1][dc(x, y)];
	} else {
		f[x][y] = f[x+1][invdc(x, y)];
		g[x][y] = max(g[x+1][lc(y)], g[x+1][rc(y)]);
	}
}
long long ansd[132005];
long long ans[132005];
inline void add(int l, int r, int val){
	ansd[l] += val;
	ansd[r+1] -= val;
}
inline void calc(int x, int y, int cr, int maxn, int mina){
	if ((1 << (cr-1)) + 1 > min(maxn, 1 << cr)) return;
	int r = k - x;
	if (x == k){
		if (a[y] < mina) maxn = min(maxn, y-1);
		if ((1 << (cr-1)) + 1 <= min(maxn, 1 << cr)) add((1 << (cr-1)) + 1, min(maxn, 1 << cr), y);
		return;
	}
	calc(x+1, dc(x, y), cr, maxn, max(mina, r));
	if (f[x+1][dc(x, y)] >= r) calc(x+1, invdc(x, y), cr, min(maxn, g[x+1][dc(x, y)]), mina);
	else calc(x+1, invdc(x, y), cr, maxn, mina);
}
void solve(){
	memset(ansd, 0, sizeof(ansd));
	int N = (1 << k);
	initfg();
	for (int i = 0; i < k; i++){
		calc(i, 1, k-i, N, 0);
	}
	add(1, 1, 1);
	for (int i = 1; i <= n; i++){
		ans[i] = ans[i-1] + ansd[i];
	}
	long long ANS = 0;
	for (int i = 1; i <= m; i++)
		ANS ^= (ans[c[i]] * i);
	cout << ANS << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 1; i <= m; i++)
		cin >> c[i];
	initk();
	for (int i = n+1; i <= (1 << k); i++)
		a[i] = 1e9;
	for (int i = k-1; i >= 0; i--)
		for (int j = 1; j <= (1 << i); j++){
			char c;
			cin >> c; 
			d[i][j] = c - '0';
		}
	int t;
	cin >> t;
	while (t--){
		int x[4];
		cin >> x[0] >> x[1] >> x[2] >> x[3];
		for (int i = 1; i <= n; i++)
			a[i] = b[i] ^ x[i % 4];
		solve();
	}
	return 0;
}
