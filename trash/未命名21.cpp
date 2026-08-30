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
int lc(int y){return y*2-1;}
int rc(int y){return y*2;}
int fa(int y){return (y+1)/2;}
bool get(int y){return !(y&1);}
int dc(int x, int y){return d[x][y] ? rc(y) : lc(y);}
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
void add(int l, int r, int val){
	ansd[l] += val;
	ansd[r+1] -= val;
}
void calc(int x, int y, int val, int maxn){
	cout << '(' << x << ',' << y << ')' << ':' << val << ',' << maxn << '\n'; 
	int r = k - x;
	if (x < k){
		if (maxn <= (1 << (r-1))) return;
		if (y == 1){
			cout << "add ans: " <<  (1 << (r-1)) + 1 << ", " << min(maxn, 1 << r) << '\n';
			add((1 << (r-1)) + 1, min(maxn, 1 << r), val);
		}
	}
	if (x == k && y == 1){
		add(1, 1, val);
	}
	if (x == 0) return;
	int ff = fa(y);
	if (dc(x-1, ff) == y){
		if (a[val] >= r + 1){
//			cout << "i win\n";
			calc(x-1, ff, val, maxn);
		} else {
//			cout << "i lose\n";
			calc(x-1, ff, val, min(maxn, val-1));
		}
	} else {
		if (f[x][dc(x-1, ff)] >= r + 1){
//			cout << "he win, use g = " << g[x][dc(x-1, ff)] << '\n';
			calc(x-1, ff, val, min(maxn, g[x][dc(x-1, ff)]));
		} else {
//			cout << "he lose\n";
			calc(x-1, ff, val, maxn);
		}
	}
}
void solve(){
	memset(ansd, 0, sizeof(ansd));
	int N = (1 << k);
	initfg();
//	cout << "f:\n";
//	for (int i = 0; i <= k; i++){
//		for (int j = 1; j <= (1 << i); j++)
//			cout << f[i][j] << ' ';
//		cout << '\n';
//	}
//	cout << "g:\n";
//	for (int i = 0; i <= k; i++){
//		for (int j = 1; j <= (1 << i); j++)
//			cout << g[i][j] << ' ';
//		cout << '\n';
//	}
	for (int i = 1; i <= N; i++){
		calc(k, i, i, N);
		cout << "-------------\n";
	}
	cout << "ans:\n";
	for (int i = 1; i <= n; i++){
		ans[i] = ans[i-1] + ansd[i];
		cout << ans[i] << ',';
	}
	cout << '\n';
	long long ANS = 0;
	for (int i = 1; i <= m; i++)
		ANS ^= (ans[c[i]] * i);
	cout << ANS << '\n';
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
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
