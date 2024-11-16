#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
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
inline void write(int x){
	if (x / 10)
		write(x / 10);
	putchar(x % 10 + '0');
}
int n, m, k;
int cnt[26], dp[100005];
string s;
void solve1(){
	write(n + m + 1);
}
void solve2(){
	s = ' ' + s;
	dp[0] = 1;
	for (int i = 1; i <= n; i++){
		dp[i] = (dp[i-1] * 2 - dp[cnt[s[i] - 'a']]) % MOD;
		cnt[s[i] - 'a'] = i - 1;
	}
	write(dp[n]);
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(0);
	m = read(), k = read();
	cin >> s;
	n = s.size();
	if (k == 1) solve1();
	if (m == 0) solve2();
	return 0;
}
