#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
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
inline void write(int x, char end = 0){
	if (x < 0){
		putchar('-');
		write(-x, end);
		return;
	}
	int len = x ? 0 : 1, tx = x;
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
const int MOD = 998244353;
int n, m, k;
int a[50005];
void CountSort(int l, int r, bool is_less){
	int cnt[10];
	memset(cnt, 0, sizeof(cnt));
	for (int i = l; i <= r; i++)
		cnt[a[i]]++;
	if (is_less){
		int cur = l - 1;
		for (int i = 0; i < k; i++)
			for (int j = 1; j <= cnt[i]; j++)
				a[++cur] = i;
	} else {
		int cur = l - 1;
		for (int i = k - 1; i >= 0; i--)
			for (int j = 1; j <= cnt[i]; j++)
				a[++cur] = i;
	}
}
int main(){
	freopen("ksystem.in", "r", stdin);
	freopen("ksystem.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= n; i++){
		char c;
		cin >> c;
		a[i] = c - '0';
	}
	for (int i = 1; i <= m; i++){
		int op = read();
		switch (op){
			case 1:{
				int x = read(), y = read();
				a[x] = y;
				break;
			}
			case 2:{
				int l = read(), r = read();
				CountSort(l, r, 1);
				break;
			}
			case 3:{
				int l = read(), r = read();
				CountSort(l, r, 0);
				break;
			}
			case 4:{
				int l = read(), r = read();
				long long ans = 0;
				for (int i = l; i <= r; i++)
					ans = ((ans * k) % MOD + a[i]) % MOD;
				write(ans, '\n');
				break;
			}
		}
//		for (int i = 1; i <= n; i++)
//			cout << a[i] << ' ';
//		cout << endl;
	}
	return 0;
}
// 赞美火车头：n方过百万，暴力碾标算 
