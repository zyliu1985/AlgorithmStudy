#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

inline int read(){
	int re = 0, type = 1;
	char c = getchar();
	while (c < '0' || c > '9'){
		if (c == '-') type = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9'){
		re = (re << 1) + (re << 3) + (c - '0');
		c = getchar();
	}
	return re * type;
}
inline void write(long long x, char end = '\n'){
	if (x < 0){
		putchar('-');
		write(-x, end);
		return;
	}
	int len = x ? 0 : 1;
	long long tx = x;
	while (x > 0){
		x /= 10;
		len++;
	}
	while (len--){
		putchar(tx / pow(10, len) + '0');
		tx %= int(pow(10, len));
	}
	putchar(end);
}
inline void endl(){
	putchar('\n');
}
int a[200005], t[1000005], last[200005], val[200005];
long long dp[200005];
void init(){
	memset(t, 0, sizeof(t));
	for (int i = 1; i <= 2e5; i++)
		last[i] = i;
	memset(val, 0, sizeof(val));
	memset(dp, 0, sizeof(dp));
}
void solve(){
	init();
	int n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		if (t[a[i]] != 0){
			if (t[a[i]] == i-1){
				ans += a[i];
			} else {
				last[i-1] = t[a[i]] + 1;
				val[i-1] = a[i];
			}
		}
		t[a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
		dp[i] = max(dp[i-1], dp[last[i] - 1] + val[i]);
	cout << ans + dp[n] << endl;
}
int main(){
	int t = read();
	while (t--)
		solve();
	return 0;
}

