#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
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
using namespace std;

inline long long read(){
	long long re = 0, type = 1;
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
inline void write(int x, char end = '\n'){
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
inline void endl(){
	putchar('\n');
}
const long long MOD = 1e9 + 7;
struct node{
	int to;
	long long w;
} val[400005];
int pre[400005], nxt[400005], head[200005], tail[200005], cnt;
bool r[200005];
long long count0, count1;
void add(int x, int y, long long w){
	cnt++;
	if (head[x] != 0){
		nxt[head[x]] = cnt;
	} else {
		tail[x] = cnt;
	}
	head[x] = cnt;
	val[cnt] = {y, w};
}
void dfs(int x, int bit, int fa){
	int cur = tail[x];
	while (cur != 0){
		if (val[cur].to != fa){
			r[val[cur].to] = r[x] ^ ((val[cur].w >> bit) & 1);
			if (r[val[cur].to]) count1++;
			else count0++;
			dfs(val[cur].to, bit, x);
		}
		cur = nxt[cur];
	}
}
int main(){
	freopen("distance.in", "r", stdin);
	freopen("distance.out", "w", stdout); 
	int n = read();
	for (int i = 1; i < n; i++){
		int x = read(), y = read();
		long long w = read();
		add(x, y, w);
		add(y, x, w);
	}
	long long ans = 0;
	for (int i = 0; i < 60; i++){
		r[1] = 0;
		count0 = 1;
		count1 = 0;
		dfs(1, i, 0);
		ans += (((count0 * count1) % MOD) * ((1ll << i) % MOD)) % MOD;
		ans %= MOD;
	}
	write(ans);
	return 0;
}
